/*
 * buttonstatesm.h
 *
 *  Created on: 30 oct. 2020
 *      Author: favre
 */

#ifndef BUTTONSTATESM_H_
#define BUTTONSTATESM_H_

#include "xf/behavior.h"
#include "event/events.h"
#include "buttoneventshandler.h"

class ButtonEventsHandler;

class ButtonStateSM : public XFBehavior
{
public:
	typedef uint8_t ButtonIndex;

	ButtonStateSM(ButtonIndex index);
	~ButtonStateSM();

	void subscribe(ButtonEventsHandler* handler);
	void unsubscribe(ButtonEventsHandler* handler);
protected:
	XFEventStatus processEvent();

	void doNotifyButtonShortPressed();
	void doNotifyButtonLongPressed();

	typedef enum{INITIAL_STATE,
		WAIT_BUTTON_PRESSED,
		BUTTON_PRESSED,
		BUTTON_SHORT_PRESSED,
		BUTTON_LONG_PRESSED} ButtonState;

	ButtonState _btnState;
	ButtonIndex _btnIndex;

	ButtonEventsHandler* _theHandler;

	int _longPressDelay = 1000;
};



#endif /* BUTTONSTATESM_H_ */
