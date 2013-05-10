/********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Sensor
//!	Generated Date	: Fri, 10, May 2013  
	File Path	: DefaultComponent\DefaultConfig\Sensor.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "Sensor.h"
//## link door
#include "GarageDoor.h"
//#[ ignore
#define Default_Sensor_Sensor_SERIALIZE OM_NO_OP

#define Default_Sensor_set_SERIALIZE aomsmethod->addAttribute("value", x2String(value));
//#]

//## package Default

//## class Sensor
Sensor::Sensor(IOxfActive* theActiveContext) : limit(0) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Sensor, Sensor(), 0, Default_Sensor_Sensor_SERIALIZE);
    setActiveContext(theActiveContext, false);
    door = NULL;
    initStatechart();
}

Sensor::~Sensor() {
    NOTIFY_DESTRUCTOR(~Sensor, true);
    cleanUpRelations();
}

void Sensor::set(int value) {
    NOTIFY_OPERATION(set, set(int), 1, Default_Sensor_set_SERIALIZE);
    //#[ operation set(int)
    //#]
}

int Sensor::getLimit() const {
    return limit;
}

void Sensor::setLimit(int p_limit) {
    limit = p_limit;
}

int Sensor::getValue() const {
    return value;
}

void Sensor::setValue(int p_value) {
    value = p_value;
}

GarageDoor_C* Sensor::getDoor() const {
    return door;
}

void Sensor::setDoor(GarageDoor_C* p_GarageDoor) {
    door = p_GarageDoor;
    if(p_GarageDoor != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("door", p_GarageDoor, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("door");
        }
}

bool Sensor::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Sensor::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void Sensor::cleanUpRelations() {
    if(door != NULL)
        {
            NOTIFY_RELATION_CLEARED("door");
            door = NULL;
        }
}

void Sensor::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("4");
        NOTIFY_STATE_ENTERED("ROOT.init");
        rootState_subState = init;
        rootState_active = init;
        NOTIFY_TRANSITION_TERMINATED("4");
    }
}

IOxfReactive::TakeEventStatus Sensor::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        // State under
        case under:
        {
            if(IS_EVENT_TYPE_OF(pass_Default_id))
                {
                    //## transition 0 
                    if(value > limit)
                        {
                            NOTIFY_TRANSITION_STARTED("0");
                            NOTIFY_STATE_EXITED("ROOT.under");
                            NOTIFY_STATE_ENTERED("ROOT.over");
                            rootState_subState = over;
                            rootState_active = over;
                            NOTIFY_TRANSITION_TERMINATED("0");
                            res = eventConsumed;
                        }
                }
            
        }
        break;
        // State over
        case over:
        {
            if(IS_EVENT_TYPE_OF(pass_Default_id))
                {
                    //## transition 1 
                    if(value < limit)
                        {
                            NOTIFY_TRANSITION_STARTED("1");
                            NOTIFY_STATE_EXITED("ROOT.over");
                            NOTIFY_STATE_ENTERED("ROOT.under");
                            rootState_subState = under;
                            rootState_active = under;
                            NOTIFY_TRANSITION_TERMINATED("1");
                            res = eventConsumed;
                        }
                }
            
        }
        break;
        // State init
        case init:
        {
            if(IS_EVENT_TYPE_OF(initialize_Default_id))
                {
                    //## transition 2 
                    if(value < limit)
                        {
                            NOTIFY_TRANSITION_STARTED("2");
                            NOTIFY_STATE_EXITED("ROOT.init");
                            NOTIFY_STATE_ENTERED("ROOT.under");
                            rootState_subState = under;
                            rootState_active = under;
                            NOTIFY_TRANSITION_TERMINATED("2");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition 3 
                            if(value > limit)
                                {
                                    NOTIFY_TRANSITION_STARTED("3");
                                    NOTIFY_STATE_EXITED("ROOT.init");
                                    NOTIFY_STATE_ENTERED("ROOT.over");
                                    rootState_subState = over;
                                    rootState_active = over;
                                    NOTIFY_TRANSITION_TERMINATED("3");
                                    res = eventConsumed;
                                }
                        }
                }
            
        }
        break;
        default:
            break;
    }
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedSensor::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("limit", x2String(myReal->limit));
    aomsAttributes->addAttribute("value", x2String(myReal->value));
}

void OMAnimatedSensor::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("door", false, true);
    if(myReal->door)
        {
            aomsRelations->ADD_ITEM(myReal->door);
        }
}

void OMAnimatedSensor::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Sensor::under:
        {
            under_serializeStates(aomsState);
        }
        break;
        case Sensor::over:
        {
            over_serializeStates(aomsState);
        }
        break;
        case Sensor::init:
        {
            init_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedSensor::under_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.under");
}

void OMAnimatedSensor::over_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.over");
}

void OMAnimatedSensor::init_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.init");
}
//#]

IMPLEMENT_REACTIVE_META_P(Sensor, Default, Default, false, OMAnimatedSensor)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Sensor.cpp
*********************************************************************/
