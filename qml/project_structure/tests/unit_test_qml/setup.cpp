
#include "setup.h"

void Setup::applicationAvailable()
{
    // custom code that does not require QQmlEngine
}

void Setup::qmlEngineAvailable(QQmlEngine *engine)
{
    // custom code that needs QQmlEngine, register QML types, add import paths,...

    //engine->addImportPath("../..");
    engine->addImportPath("../../modules");
    //engine->addImportPath("../../FirstModule");
    //engine->addImportPath("../../Style");

    /*engine->addPluginPath("../..");
    engine->addPluginPath("../../modules");
    engine->addPluginPath("../../FirstModule");
    engine->addPluginPath("../../Style");*/
}

void Setup::cleanupTestCase()
{
    // custom code to clean up before destruction starts
}
