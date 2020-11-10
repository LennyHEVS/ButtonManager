/*
 * buttonstatesm.cpp
 *
 *  Created on: 30 oct. 2020
 *      Author: favre
 */
#include "buttonstatesm.h"

ButtonStateSM::ButtonStateSM(ButtonIndex index) {
	_btnIndex = index;
	_btnState = INITIAL_STATE;

	_theHandler = nullptr;

	startBehavior();
}

ButtonStateSM::~ButtonStateSM() {
}

void ButtonStateSM::subscribe(ButtonEventsHandler* handler) {
	_theHandler = handler;
}

XFEventStatus ButtonStateSM::processEvent() {
	eEventStatus eventStatus = XFEventStatus::Unknown;

	ButtonState oldState = _btnState;

	switch(_btnState)
	{
		case INITIAL_STATE:
			if (getCurrentEvent()->getEventType() == XFEvent::Initial)
			{
				_btnState = WAIT_BUTTON_PRESSED;
				eventStatus = XFEventStatus::Consumed;
			}
			break;
		case WAIT_BUTTON_PRESSED:
			if (getCurrentEvent()->getEventType() == XFEvent::Event &&
					getCurrentEvent()->getId() == EventIds::evButtonPressedId)
			{
				scheduleTimeout(EventIds::tmButtonLongPressId,_longPressDelay);
				_btnState = BUTTON_PRESSED;
				eventStatus = XFEventStatus::Consumed;
			}
			break;
		case BUTTON_PRESSED:
			if (getCurrentEvent()->getEventType() == XFEvent::Event &&
					getCurrentEvent()->getId() == EventIds::evButtonReleasedId)
			{
				unscheduleTimeout(EventIds::tmButtonLongPressId);
				_btnState = BUTTON_SHORT_PRESSED;
				eventStatus = XFEventStatus::Consumed;
			}
			else if (getCurrentEvent()->getEventType() == XFEvent::Timeout &&
					getCurrentEvent()->getId() == EventIds::tmButtonLongPressId)
			{
				_btnState = BUTTON_LONG_PRESSED;
				eventStatus = XFEventStatus::Consumed;
			}
			break;
		case BUTTON_SHORT_PRESSED:
			if(getCurrentEvent()->getEventType() == XFEvent::NullTransition)
			{
				_btnState = WAIT_BUTTON_PRESSED;
				eventStatus = XFEventStatus::Consumed;
			}
			break;
		case BUTTON_LONG_PRESSED:
			if(getCurrentEvent()->getEventType() == XFEvent::NullTransition)
			{
				_btnState = WAIT_BUTTON_PRESSED;
				eventStatus = XFEventStatus::Consumed;
			}
			break;
		default:
			break;
	}

	if(_btnState != oldState)
	{
		switch(_btnState)
		{
			case BUTTON_SHORT_PRESSED:
				doNotifyButtonShortPressed();
				GEN(XFNullTransition);
				break;
			case BUTTON_LONG_PRESSED:
				doNotifyButtonLongPressed();
				GEN(XFNullTransition);
				break;
			default:
				break;
		}
	}
	return eventStatus;
}

void ButtonStateSM::doNotifyButtonShortPressed() {
	if(_theHandler!=nullptr)
	{
		_theHandler->notifyButtonShortPressed(_btnIndex);
	}
}

void ButtonStateSM::unsubscribe(ButtonEventsHandler* handler) {
	if(_theHandler == handler)
	{
		_theHandler = nullptr;
	}
}

void ButtonStateSM::doNotifyButtonLongPressed() {
	if(_theHandler!=nullptr)
		{
			_theHandler->notifyButtonLongPressed(_btnIndex);
		}
}
