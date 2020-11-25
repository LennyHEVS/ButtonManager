/*
 * ButtonEventsFileLogger.h
 *
 *  Created on: 10 nov. 2020
 *      Author: favre
 */

#ifndef BUTTONEVENTSFILELOGGER_H_
#define BUTTONEVENTSFILELOGGER_H_

//
// What is seen only by the C++ compiler
//
#ifdef __cplusplus

#include "interface/buttoneventshandlerobserver.h"
#include "xf/behavior.h"
#include "xf/event.h"
#include "Middlewares/Third_Party/FatFs/src/ff.h"
#include <string>
#include <string.h>

using namespace std;
using namespace interface;

namespace app
{

class ButtonEventsFileLogger : public ButtonEventsHandlerObserver, public XFBehavior
{
public :
	ButtonEventsFileLogger();
	~ButtonEventsFileLogger();

	bool initialize(string path);
protected:
	void onButtonShortPressed(ButtonIndex buttonIndex);
	void onButtonLongPressed(ButtonIndex buttonIndex);

	XFEventStatus processEvent();
private:
	FIL* _logFile;
	string _filePath;
};

} /* namespace app */
#endif // __cplusplus

#endif /* BUTTONEVENTSFILELOGGER_H_ */
