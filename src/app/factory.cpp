#include "trace/trace.h"
#include "factory.h"

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

ButtonEventsHandler* Factory::btnEventsHandler;

LedController* Factory::ledController;
ButtonsController* Factory::btnController;

void Factory::build()
{
	btnEventsLogger = new ButtonEventsLogger();
	btnEventsLedFlasher = new ButtonEventsLedFlasher();

	btnEventsHandler = new ButtonEventsHandler();

	ledController = new LedController();
	btnController = new ButtonsController();

	btnEventsHandler->subscribe(btnEventsLogger);
	btnEventsHandler->subscribe(btnEventsLedFlasher);
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
