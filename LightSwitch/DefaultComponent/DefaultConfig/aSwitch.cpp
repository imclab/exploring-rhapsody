/********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aSwitch
//!	Generated Date	: Mon, 22, Apr 2013  
	File Path	: DefaultComponent\DefaultConfig\aSwitch.cpp
*********************************************************************/

//## auto_generated
#include <oxf\omthread.h>
//## auto_generated
#include "aSwitch.h"
//## link itsALight
#include "aLight.h"
//## package Default

//## class TopLevel::aSwitch
aSwitch_C::aSwitch_C(IOxfActive* theActiveContext) {
    setActiveContext(theActiveContext, false);
    itsALight = NULL;
    initStatechart();
}

aSwitch_C::~aSwitch_C() {
    cleanUpRelations();
}

void aSwitch_C::flip() {
    //#[ operation flip()
    itsLight->GEN(toggle());
    //#]
}

aLight_C* aSwitch_C::getItsALight() const {
    return itsALight;
}

void aSwitch_C::setItsALight(aLight_C* p_aLight) {
    itsALight = p_aLight;
}

bool aSwitch_C::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void aSwitch_C::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void aSwitch_C::cleanUpRelations() {
    if(itsALight != NULL)
        {
            itsALight = NULL;
        }
}

void aSwitch_C::rootState_entDef() {
}

IOxfReactive::TakeEventStatus aSwitch_C::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    return res;
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aSwitch.cpp
*********************************************************************/
