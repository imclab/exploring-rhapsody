/********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aLight
//!	Generated Date	: Mon, 22, Apr 2013  
	File Path	: DefaultComponent\DefaultConfig\aLight.cpp
*********************************************************************/

//## auto_generated
#include <oxf\omthread.h>
//## auto_generated
#include "aLight.h"
//## package Default

//## class TopLevel::aLight
aLight_C::aLight_C(IOxfActive* theActiveContext) {
    setActiveContext(theActiveContext, false);
    initStatechart();
}

aLight_C::~aLight_C() {
}

bool aLight_C::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void aLight_C::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    Active_subState = OMNonState;
}

void aLight_C::rootState_entDef() {
    {
        Active_entDef();
    }
}

IOxfReactive::TakeEventStatus aLight_C::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        // State ON
        case ON:
        {
            if(IS_EVENT_TYPE_OF(toggle_Default_id))
                {
                    Active_subState = OFF;
                    rootState_active = OFF;
                    res = eventConsumed;
                }
            
            
        }
        break;
        // State OFF
        case OFF:
        {
            if(IS_EVENT_TYPE_OF(toggle_Default_id))
                {
                    Active_subState = ON;
                    rootState_active = ON;
                    res = eventConsumed;
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

void aLight_C::Active_entDef() {
    rootState_subState = Active;
    Active_subState = OFF;
    rootState_active = OFF;
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aLight.cpp
*********************************************************************/
