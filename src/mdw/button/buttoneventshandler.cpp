/*
 * ButtonEventsHandler.cpp
 *
 *  Created on: 30 oct. 2020
 *      Author: favre
 */
#include "buttoneventshandler.h"
#include "platform/f7-disco-gcc/board/buttonscontroller.h"

ButtonEventsHandler::ButtonEventsHandler() {
	_btnSMs.clear();
	for(uint32_t i=0 ; i<BTN_COUNT ; i++)
	{
		ButtonStateSM* b = new ButtonStateSM(i);
		b->subscribe(this);
		_btnSMs.push_back(b);
	}
	_subscribers.clear();
}

ButtonEventsHandler::~ButtonEventsHandler() {
	std::vector<ButtonStateSM*>::iterator it = _btnSMs.begin();
	while(it != _btnSMs.end())
	{
		it = _btnSMs.erase(it);
	}
}

bool ButtonEventsHandler::subscribe(ButtonEventsHandlerObserver* observer) {
	_subscribers.push_back(observer);
	return true;
}

void ButtonEventsHandler::unsubscribe(ButtonEventsHandlerObserver* observer) {
	_subscribers.remove(observer);
}

void ButtonEventsHandler::notifyButtonShortPressed(ButtonIndex buttonIndex) {
	for (std::list<ButtonEventsHandlerObserver*>::iterator it = _subscribers.begin(); it != _subscribers.end(); ++it){
	    (*it)->onButtonShortPressed(buttonIndex);
	}
}

void ButtonEventsHandler::onButtonChanged(ButtonIndex buttonIndex,
		bool pressed) {
	XFBehavior* btnStateSM = _btnSMs.at(buttonIndex);
	XFEvent* e;
	if(pressed)
	{
		e = new XFEvent(XFEvent::Event,EventIds::evButtonPressedId,btnStateSM);
	}
	else
	{
		e = new XFEvent(XFEvent::Event,EventIds::evButtonReleasedId,btnStateSM);
	}
	btnStateSM->pushEvent(e);
}

void ButtonEventsHandler::notifyButtonLongPressed(ButtonIndex buttonIndex) {
	for (std::list<ButtonEventsHandlerObserver*>::iterator it = _subscribers.begin(); it != _subscribers.end(); ++it){
		    (*it)->onButtonLongPressed(buttonIndex);
		}
}
