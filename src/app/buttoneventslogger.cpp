/*
 * ButtonEventsLogger.cpp
 *
 *  Created on: 27 oct. 2020
 *      Author: favre
 */
#include "buttoneventslogger.h"

namespace app
{

ButtonEventsLogger::ButtonEventsLogger() {
	Trace::initialize();
}

ButtonEventsLogger::~ButtonEventsLogger() {
}

void ButtonEventsLogger::onButtonShortPressed(ButtonIndex buttonIndex) {
	pushEvent(new XFEvent(XFEvent::Event,buttonIndex,this));
}

void ButtonEventsLogger::onButtonLongPressed(ButtonIndex buttonIndex) {
	pushEvent(new XFEvent(XFEvent::Event,buttonIndex+4,this));
}

XFEventStatus ButtonEventsLogger::processEvent() {
	eEventStatus eventStatus = XFEventStatus::Unknown;

	if (getCurrentEvent()->getEventType() == XFEvent::Event)
	{
		string str("ButtonEventsLogger: Button ");
		if(getCurrentEvent()->getId() < 4)
		{
			str += to_string(getCurrentEvent()->getId());
			str += " short pressed";
		}
		else
		{
			str += to_string(getCurrentEvent()->getId() - 4);
			str += " long pressed";
		}
		Trace::out(str);
		eventStatus = XFEventStatus::Consumed;
	}
	return eventStatus;
}

} /* namespace app */
