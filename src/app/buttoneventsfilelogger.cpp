/*
 * ButtonEventsFileLogger.cpp
 *
 *  Created on: 10 nov. 2020
 *      Author: favre
 */
#include "buttoneventsfilelogger.h"

namespace app
{

ButtonEventsFileLogger::ButtonEventsFileLogger() {
	_logFile = new FIL();
}

ButtonEventsFileLogger::~ButtonEventsFileLogger() {
	delete _logFile;
}

void ButtonEventsFileLogger::onButtonShortPressed(ButtonIndex buttonIndex) {
	pushEvent(new XFEvent(XFEvent::Event,buttonIndex,this));
}

void ButtonEventsFileLogger::onButtonLongPressed(ButtonIndex buttonIndex) {
	pushEvent(new XFEvent(XFEvent::Event,buttonIndex+4,this));
}

bool ButtonEventsFileLogger::initialize(string path) {
	_filePath = path;

	f_mount(new FATFS(),"",0);

	bool retVal = f_open(_logFile,_filePath.c_str(),FA_CREATE_ALWAYS)==FR_OK;
	f_close(_logFile);

	return retVal;
}

XFEventStatus ButtonEventsFileLogger::processEvent() {
	eEventStatus eventStatus = XFEventStatus::Unknown;

	if (getCurrentEvent()->getEventType() == XFEvent::Event)
	{
		string str("ButtonEventsLogger: Button ");
		if(getCurrentEvent()->getId() < 4)
		{
			str += to_string(getCurrentEvent()->getId());
			str += " short pressed\n";
		}
		else
		{
			str += to_string(getCurrentEvent()->getId() - 4);
			str += " long pressed\n";
		}
		//TODO: Access SD card
		//		Open File
		if(f_open(_logFile,_filePath.c_str(),FA_WRITE)==FR_OK)
		{
			//		Go to EOF
			f_lseek(_logFile, f_size(_logFile));
			//		Write File
			f_write(_logFile,str.c_str(),str.length(),nullptr);
			//		Close File
			f_close(_logFile);
			eventStatus = XFEventStatus::Consumed;
		}
		else
		{
			eventStatus = XFEventStatus::NotConsumed;
		}
	}
	return eventStatus;
}

} /* namespace app */
