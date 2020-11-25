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
	void onButtonShortPressed(ButtonIndex buttonIndex);
	void onButtonLongPressed(ButtonIndex buttonIndex);

	XFEventStatus processEvent();

private:
	int _blinkDelay = 200;
};

} /* namespace app */
#endif // __cplusplus

#endif /* BUTTONEVENTSLEDFLASHER_H_ */
