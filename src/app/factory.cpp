#include "trace/trace.h"
#include "factory.h"
#include <assert.h>

namespace app
{
Factory::Factory()
{

}

void Factory::initialize()
{

}

ButtonEventsLogger* Factory::btnEventsLogger;
ButtonEventsLedFlasher* Factory::btnEventsLedFlasher;
ButtonEventsFileLogger* Factory::btnEventsFileLogger;

ButtonEventsHandler* Factory::btnEventsHandler;

LedController* Factory::ledController;
ButtonsController* Factory::btnController;

void Factory::build()
{
	btnEventsLogger = new ButtonEventsLogger();
	btnEventsLedFlasher = new ButtonEventsLedFlasher();
	btnEventsFileLogger = new ButtonEventsFileLogger();

	btnEventsHandler = new ButtonEventsHandler();

	ledController = new LedController();
	btnController = new ButtonsController();

	assert(btnEventsFileLogger->initialize("logs.txt"));

	btnEventsHandler->subscribe(btnEventsLogger);
	btnEventsHandler->subscribe(btnEventsLedFlasher);
	btnEventsHandler->subscribe(btnEventsFileLogger);
	btnController->registerCallback(btnEventsHandler,(ButtonsControllerCallbackProvider::CallbackMethod)&ButtonEventsHandler::onButtonChanged);
}

} /* namespace app */

void Factory_initialize()
{
    app::Factory::initialize();
}

void Factory_build()
{
    app::Factory::build();
}
