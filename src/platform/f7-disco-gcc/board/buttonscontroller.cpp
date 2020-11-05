/*
 * buttoncontroller.cpp
 *
 *  Created on: 27 oct. 2020
 *      Author: favre
 */
#include "mcu/mcu.h"
#include "config/btncontroller-config.h"
#include "event/evbuttonirq.h"
#include "event/events.h"
#include "main.h"
#if (BTNCONTROLLER_TRACE_ENABLE != 0)
    #include "trace/trace.h"
#endif // BTNCONTROLLER_TRACE_ENABLE
#include <board/buttonscontroller.h>

ButtonsController * ButtonsController::_pInstance = nullptr;

ButtonsController::ButtonsController() {
	assert(!_pInstance);	// Only one instance of this class allowed!
	_pInstance = this;

	_theCallbackProvider = nullptr;
	_theCallbackMethod = nullptr;

	_btnState = 0x00;

	// Initialize the method array with the right methods.
	_btnOperation[0] = &ButtonsController::getBtn0;
	_btnOperation[1] = &ButtonsController::getBtn1;
	_btnOperation[2] = &ButtonsController::getBtn2;
	_btnOperation[3] = &ButtonsController::getBtn3;

	/*
	 * F7-DISCO BUTTONS GPIOs (Extension Board):
	 * BUTTON0: PI2
	 * BUTTON1: PI3
	 * BUTTON2: PG7
	 * BUTTON3: PG6
	 */
	_state = STATE_INITIAL;
	GEN(XFInitialEvent);
}

ButtonsController::~ButtonsController() {
}

bool ButtonsController::registerCallback(ButtonsControllerCallbackProvider * callbackProvider,
	                                  ButtonsControllerCallbackProvider::CallbackMethod callbackMethod){
	_theCallbackProvider = callbackProvider;
	_theCallbackMethod = callbackMethod;
	return true;
}

void ButtonsController::onIrq() {
	static evButtonIrq e = evButtonIrq();
	pushEvent(&e);
}

bool ButtonsController::getBtn(uint8_t index) {
	return getBtns(0x01 << index);
}

uint8_t ButtonsController::getBtns(uint8_t btnMask) {
	uint8_t retVal = 0x00;
	uint8_t mask = 0x01;

	for (uint8_t i = 0; i < btnCount(); i++, mask <<= 1)
	{
		if ((btnMask & mask) == mask && _btnOperation[i])
		{
			retVal += (this->*_btnOperation[i])()<<i;
		}
	}
	return retVal;
}

bool ButtonsController::getBtn0() {
	bool btnState = 1-HAL_GPIO_ReadPin(BUTTON0_GPIO_Port, BUTTON0_Pin);


	#if (BTNCONTROLLER_TRACE_ENABLE != 0)
		if (btnState)
		{
			// Not using "%s" here (bug in gcc c-library!)
			Trace::out(" BTN0: pressed");
		}
		else
		{
			Trace::out(" BTN0: released");
		}
	#endif // BTNCONTROLLER_TRACE_ENABLE

	return btnState;
}

bool ButtonsController::getBtn1() {
	bool btnState = 1-HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);


		#if (BTNCONTROLLER_TRACE_ENABLE != 0)
			if (btnState)
			{
				// Not using "%s" here (bug in gcc c-library!)
				Trace::out(" BTN1: pressed");
			}
			else
			{
				Trace::out(" BTN1: released");
			}
		#endif // BTNCONTROLLER_TRACE_ENABLE

		return btnState;
}

bool ButtonsController::getBtn2() {
	bool btnState = 1-HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);


		#if (BTNCONTROLLER_TRACE_ENABLE != 0)
			if (btnState)
			{
				// Not using "%s" here (bug in gcc c-library!)
				Trace::out(" BTN2: pressed");
			}
			else
			{
				Trace::out(" BTN2: released");
			}
		#endif // BTNCONTROLLER_TRACE_ENABLE

		return btnState;
}

bool ButtonsController::getBtn3() {
	bool btnState = 1-HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);


		#if (BTNCONTROLLER_TRACE_ENABLE != 0)
			if (btnState)
			{
				// Not using "%s" here (bug in gcc c-library!)
				Trace::out(" BTN3: pressed");
			}
			else
			{
				Trace::out(" BTN3: released");
			}
		#endif // BTNCONTROLLER_TRACE_ENABLE

		return btnState;
}

ButtonsController::ControllerState ButtonsController::getState() {
	return _state;
}

XFEventStatus ButtonsController::processEvent() {
	eEventStatus eventStatus = XFEventStatus::Unknown;

	ControllerState oldState = _state;

		switch (_state)
		{
		case STATE_INITIAL:
			if (getCurrentEvent()->getEventType() == XFEvent::Initial)
			{
				_state = STATE_CHECK_BUTTONS;
				eventStatus = XFEventStatus::Consumed;
			}
			break;
		case STATE_CHECK_BUTTONS:
			if (getCurrentEvent()->getEventType() == XFEvent::Event &&
					getCurrentEvent()->getId() == EventIds::evButtonIrqId)
			{
				scheduleTimeout(EventIds::tmDebounceId, _debounceDelay);
				_state = STATE_DEBOUNCE;
				eventStatus = XFEventStatus::Consumed;
			}
			break;
		case STATE_DEBOUNCE:
			if (getCurrentEvent()->getEventType() == XFEvent::Timeout)
			{
				if(getCurrentEvent()->getId() == EventIds::tmDebounceId)
				{
					_state = STATE_CHECK_BUTTONS;
					eventStatus = XFEventStatus::Consumed;
				}
			}
			break;
		default:
			break;
		}

		if(_state!=oldState)
		{
			switch(_state)
			{
				case STATE_CHECK_BUTTONS:
					doCheckButtons();
					break;
				default:
					break;
			}
		}

		return eventStatus;
}

void ButtonsController::doCheckButtons() {
	uint8_t newBtnState = 0x00;
	uint16_t pos = 0;
	bool pressed = false;

	newBtnState = getBtns((0x01<<BTN_COUNT)-0x01);
	if(newBtnState!=_btnState)
	{
		pressed = newBtnState>_btnState;
		while(((_btnState^newBtnState)>>pos)!=0x01)
		{
			pos++;
		}
		(_theCallbackProvider->*_theCallbackMethod)(pos,pressed);
		_btnState = newBtnState;
	}
}
