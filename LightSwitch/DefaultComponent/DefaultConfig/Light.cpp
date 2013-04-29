/********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Light
//!	Generated Date	: Mon, 22, Apr 2013  
	File Path	: DefaultComponent\DefaultConfig\Light.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "Light.h"
//#[ ignore
#define Default_Light_Light_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class TopLevel::Light
Light_C::Light_C(IOxfActive* theActiveContext) {
    NOTIFY_REACTIVE_CONSTRUCTOR_OBJECT(Light, Light(), 0, Default_Light_Light_SERIALIZE, Light_C);
    setActiveContext(theActiveContext, false);
    initStatechart();
}

Light_C::~Light_C() {
    NOTIFY_DESTRUCTOR(~Light, true);
}

bool Light_C::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Light_C::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    Active_subState = OMNonState;
}

void Light_C::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        Active_entDef();
    }
}

IOxfReactive::TakeEventStatus Light_C::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        // State ON
        case ON:
        {
            if(IS_EVENT_TYPE_OF(toggle_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("2");
                    NOTIFY_STATE_EXITED("ROOT.Active.ON");
                    NOTIFY_STATE_ENTERED("ROOT.Active.OFF");
                    Active_subState = OFF;
                    rootState_active = OFF;
                    NOTIFY_TRANSITION_TERMINATED("2");
                    res = eventConsumed;
                }
            
            
        }
        break;
        // State OFF
        case OFF:
        {
            if(IS_EVENT_TYPE_OF(toggle_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.Active.OFF");
                    NOTIFY_STATE_ENTERED("ROOT.Active.ON");
                    Active_subState = ON;
                    rootState_active = ON;
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

void Light_C::Active_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.Active");
    rootState_subState = Active;
    NOTIFY_TRANSITION_STARTED("0");
    NOTIFY_STATE_ENTERED("ROOT.Active.OFF");
    Active_subState = OFF;
    rootState_active = OFF;
    NOTIFY_TRANSITION_TERMINATED("0");
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedLight_C::serializeRelations(AOMSRelations* aomsRelations) const {
}

void OMAnimatedLight_C::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    if(myReal->rootState_subState == Light_C::Active)
        {
            Active_serializeStates(aomsState);
        }
}

void OMAnimatedLight_C::Active_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Active");
    switch (myReal->Active_subState) {
        case Light_C::ON:
        {
            ON_serializeStates(aomsState);
        }
        break;
        case Light_C::OFF:
        {
            OFF_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedLight_C::ON_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Active.ON");
}

void OMAnimatedLight_C::OFF_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Active.OFF");
}
//#]

IMPLEMENT_REACTIVE_META_OBJECT_P(Light, Light_C, Default, Default, false, OMAnimatedLight_C)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Light.cpp
*********************************************************************/
