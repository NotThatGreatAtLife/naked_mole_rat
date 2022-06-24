#include "NakedMoleRatApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
NakedMoleRatApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

NakedMoleRatApp::NakedMoleRatApp(InputParameters parameters) : MooseApp(parameters)
{
  NakedMoleRatApp::registerAll(_factory, _action_factory, _syntax);
}

NakedMoleRatApp::~NakedMoleRatApp() {}

void
NakedMoleRatApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"NakedMoleRatApp"});
  Registry::registerActionsTo(af, {"NakedMoleRatApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
NakedMoleRatApp::registerApps()
{
  registerApp(NakedMoleRatApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
NakedMoleRatApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  NakedMoleRatApp::registerAll(f, af, s);
}
extern "C" void
NakedMoleRatApp__registerApps()
{
  NakedMoleRatApp::registerApps();
}
