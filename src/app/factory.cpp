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
ButtonsController* Factory::btnController;

void Factory::build()
{
	btnEventsLogger = new ButtonEventsLogger();
	btnEventsHandler = new ButtonEventsHandler();
	btnController = new ButtonsController();

	btnEventsHandler->subscribe(btnEventsLogger);
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
