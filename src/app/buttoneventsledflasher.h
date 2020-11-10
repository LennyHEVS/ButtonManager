/*
 * buttoneventsledflasher.h
 *
 *  Created on: 10 nov. 2020
 *      Author: favre
 */

#ifndef BUTTONEVENTSLEDFLASHER_H_
#define BUTTONEVENTSLEDFLASHER_H_

//
// What is seen only by the C++ compiler
//
#ifdef __cplusplus

#include "interface/buttoneventshandlerobserver.h"
#include "platform/f7-disco-gcc/board/ledcontroller.h"
#include "xf/behavior.h"
#include "xf/event.h"

using namespace interface;

namespace app
{

class ButtonEventsLedFlasher : public ButtonEventsHandlerObserver, public XFBehavior
{
public :
	ButtonEventsLedFlasher();
	~ButtonEventsLedFlasher();
protected:
	typedef enum{btn0ShortPress=0, btn1ShortPress, btn2ShortPress, btn3ShortPress,
				btn0LongPress, btn1LongPress, btn2LongPress, btn3LongPress} btnPressEvents;
	typedef enum{led0ShortFlash=0, led1ShortFlash, led2ShortFlash, led3ShortFlash,
				led0LongFlash, led1LongFlash, led2LongFlash, led3LongFlash,
				led0LongWait, led1LongWait, led2LongWait, led3LongWait} ledFlashTimeouts;

	void onButtonShortPressed(ButtonIndex buttonIndex);
	void onButtonLongPressed(ButtonIndex buttonIndex);

	XFEventStatus processEvent();

private:
	int _blinkDelay = 200;
};

} /* namespace app */
#endif // __cplusplus

#endif /* BUTTONEVENTSLEDFLASHER_H_ */
