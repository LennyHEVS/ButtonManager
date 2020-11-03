/*
 * ButtonEventsHandler.h
 *
 *  Created on: 30 oct. 2020
 *      Author: favre
 */

#ifndef BUTTONEVENTSHANDLER_H_
#define BUTTONEVENTSHANDLER_H_

//
// What is seen only by the C++ compiler
//
#ifdef __cplusplus

#include "interface/buttoneventshandlersubject.h"
#include "interface/buttoneventshandlerobserver.h"
#include "interface/buttonscontrollercallbackprovider.h"
#include "buttonstatesm.h"

#include <list>
#include <vector>

#define BTN_COUNT 4

using namespace interface;

class ButtonStateSM;

class ButtonEventsHandler : public ButtonEventsHandlerSubject, public ButtonsControllerCallbackProvider
{
	friend class ButtonStateSM;

public :
	ButtonEventsHandler();
	~ButtonEventsHandler();
public:
	bool subscribe(ButtonEventsHandlerObserver * observer);			    ///< @brief Registers a new observer. Returns true on success.
	void unsubscribe(ButtonEventsHandlerObserver * observer);	        ///< @brief Un-subscribes a registered observer.
	void onButtonChanged(ButtonIndex buttonIndex, bool pressed);

protected:
	void notifyButtonShortPressed(ButtonIndex buttonIndex);	            ///< @brief Notifies observers about a button short pressed.
    void notifyButtonLongPressed(ButtonIndex buttonIndex);              ///< @brief Notifies observers about a button long pressed.
private:
    std::list<ButtonEventsHandlerObserver*> _subscribers;
    std::vector<ButtonStateSM*> _btnSMs;
};
#endif // __cplusplus

#endif /* BUTTONEVENTSHANDLER_H_ */
