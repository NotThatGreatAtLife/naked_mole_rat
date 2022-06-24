//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "NakedMoleRatTestApp.h"
#include "NakedMoleRatApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
NakedMoleRatTestApp::validParams()
{
  InputParameters params = NakedMoleRatApp::validParams();
  return params;
}

NakedMoleRatTestApp::NakedMoleRatTestApp(InputParameters parameters) : MooseApp(parameters)
{
  NakedMoleRatTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

NakedMoleRatTestApp::~NakedMoleRatTestApp() {}

void
NakedMoleRatTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  NakedMoleRatApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"NakedMoleRatTestApp"});
    Registry::registerActionsTo(af, {"NakedMoleRatTestApp"});
  }
}

void
NakedMoleRatTestApp::registerApps()
{
  registerApp(NakedMoleRatApp);
  registerApp(NakedMoleRatTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
NakedMoleRatTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  NakedMoleRatTestApp::registerAll(f, af, s);
}
extern "C" void
NakedMoleRatTestApp__registerApps()
{
  NakedMoleRatTestApp::registerApps();
}
