/*
 * buttoncontroller.h
 *
 *  Created on: 27 oct. 2020
 *      Author: favre
 */

#ifndef BUTTONSCONTROLLER_H_
#define BUTTONSCONTROLLER_H_

#include <assert.h>
#include <stdint.h>

#include "interface/buttonirq.h"
#include "interface/buttonscontrollercallbackcaller.h"
#include "xf/behavior.h"

using namespace interface;

class ButtonsController : public ButtonsControllerCallbackCaller, public ButtonIrq, public XFBehavior
{
public:
	#define BTN_COUNT	4
public:
	~ButtonsController();

	inline static ButtonsController & getInstance() { assert(_pInstance); return *_pInstance; }

	bool getBtn(uint8_t index);
	uint8_t getBtns(uint8_t btnMask);

	inline uint8_t btnCount() const { return BTN_COUNT; }

	bool getBtn0();
	bool getBtn1();
	bool getBtn2();
	bool getBtn3();

	typedef enum {STATE_INITIAL,STATE_CHECK_BUTTONS,STATE_DEBOUNCE} ControllerState;
	ControllerState getState();

	void onIrq();
	bool registerCallback(ButtonsControllerCallbackProvider * callbackProvider,
		                                  ButtonsControllerCallbackProvider::CallbackMethod callbackMethod);


protected:
	XFEventStatus processEvent() override;		///< Remplementation from XFBehavior
	typedef bool (ButtonsController::*btnMethod)();


	static ButtonsController * _pInstance;

	ControllerState _state;
	uint8_t _btnState;

	ButtonsControllerCallbackProvider * _theCallbackProvider;
	ButtonsControllerCallbackProvider::CallbackMethod _theCallbackMethod;

	btnMethod _btnOperation[BTN_COUNT];		///< Array of pointers to button functions.

private:
	ButtonsController();
	void doCheckButtons();

	int _debounceDelay = 100;
};

#endif /* BUTTONSCONTROLLER_H_ */
