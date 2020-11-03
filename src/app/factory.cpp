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
ButtonEventsHandler* Factory::btnEventsHandler;

void Factory::build()
{
	btnEventsLogger = new ButtonEventsLogger();
	btnEventsHandler = new ButtonEventsHandler();

	btnEventsHandler->subscribe(btnEventsLogger);
	ButtonsController::getInstance().registerCallback((ButtonsControllerCallbackProvider*)btnEventsHandler,(ButtonsControllerCallbackProvider::CallbackMethod)&ButtonEventsHandler::onButtonChanged);
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
