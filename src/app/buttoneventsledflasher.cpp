/*
 * buttoneventsledflasher.cpp
 *
 *  Created on: 10 nov. 2020
 *      Author: favre
 */
#include "buttoneventsledflasher.h"

namespace app
{

ButtonEventsLedFlasher::ButtonEventsLedFlasher() {
}

ButtonEventsLedFlasher::~ButtonEventsLedFlasher() {
}

void ButtonEventsLedFlasher::onButtonShortPressed(ButtonIndex buttonIndex) {
	pushEvent(new XFEvent(XFEvent::Event,buttonIndex,this));
}

void ButtonEventsLedFlasher::onButtonLongPressed(ButtonIndex buttonIndex) {
	pushEvent(new XFEvent(XFEvent::Event,buttonIndex+4,this));
}

XFEventStatus ButtonEventsLedFlasher::processEvent() {
	eEventStatus eventStatus = XFEventStatus::Unknown;

	if (getCurrentEvent()->getEventType() == XFEvent::Event)
	{
		if(getCurrentEvent()->getId() < 4)
		{
			LedController::getInstance().setLed(getCurrentEvent()->getId(),true);
		}
		else
		{
			LedController::getInstance().setLed(getCurrentEvent()->getId()-4,true);
		}
		scheduleTimeout(getCurrentEvent()->getId(),_blinkDelay);
		eventStatus = XFEventStatus::Consumed;
	}
	else if (getCurrentEvent()->getEventType() == XFEvent::Timeout)
	{
		if(getCurrentEvent()->getId() < 4)
		{
			LedController::getInstance().setLed(getCurrentEvent()->getId(),false);
		}
		else if(getCurrentEvent()->getId() < 8)
		{
			LedController::getInstance().setLed(getCurrentEvent()->getId()-4,false);
			scheduleTimeout(getCurrentEvent()->getId()+4,_blinkDelay);
		}
		else
		{
			LedController::getInstance().setLed(getCurrentEvent()->getId()-8,true);
			scheduleTimeout(getCurrentEvent()->getId()-8,_blinkDelay);
		}
		eventStatus = XFEventStatus::Consumed;
	}
	return eventStatus;
}

} /* namespace app */
