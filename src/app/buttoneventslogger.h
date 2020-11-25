/*
 * ButtonEventsLogger.h
 *
 *  Created on: 27 oct. 2020
 *      Author: favre
 */

#ifndef BUTTONEVENTSLOGGER_H_
#define BUTTONEVENTSLOGGER_H_

//
// What is seen only by the C++ compiler
//
#ifdef __cplusplus

#include "interface/buttoneventshandlerobserver.h"
#include "trace/trace.h"
#include "xf/behavior.h"
#include "xf/event.h"

using namespace interface;

namespace app
{

class ButtonEventsLogger : public ButtonEventsHandlerObserver, public XFBehavior
{
public :
	ButtonEventsLogger();
	~ButtonEventsLogger();
protected:
	void onButtonShortPressed(ButtonIndex buttonIndex);
	void onButtonLongPressed(ButtonIndex buttonIndex);

	XFEventStatus processEvent();
};

} /* namespace app */
#endif // __cplusplus

#endif /* BUTTONEVENTSLOGGER_H_ */
