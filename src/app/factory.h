#ifndef FACTORY_H
#define FACTORY_H

//
// What is seen only by the C++ compiler
//
#ifdef __cplusplus

#include "buttoneventslogger.h"
#include "buttoneventsfilelogger.h"
#include "buttoneventsledflasher.h"
#include "mdw/button/buttoneventshandler.h"
#include "platform/f7-disco-gcc/board/buttonscontroller.h"

namespace app
{

class Factory
{
public:
    Factory();

    static void initialize();           ///< Initializes the factory
    static void build();                ///< Creates components and initializes relations

protected:
    static ButtonEventsLogger* btnEventsLogger;
    static ButtonEventsLedFlasher* btnEventsLedFlasher;
    static ButtonEventsFileLogger* btnEventsFileLogger;

    static ButtonEventsHandler* btnEventsHandler;

    static LedController* ledController;
    static ButtonsController* btnController;
};

} /* namespace app */
#endif // __cplusplus

//
// What is seen by the C and C++ compiler
//
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void Factory_initialize();
void Factory_build();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // FACTORY_H
