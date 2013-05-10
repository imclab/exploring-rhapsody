/********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Controller
//!	Generated Date	: Fri, 10, May 2013  
	File Path	: DefaultComponent\DefaultConfig\Controller.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "Controller.h"
//## link door
#include "GarageDoor.h"
//## link loweredSensor
#include "Sensor.h"
//#[ ignore
#define Default_Controller_Controller_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class TopLevel::Controller
Controller_C::Controller_C(IOxfActive* theActiveContext) {
    NOTIFY_REACTIVE_CONSTRUCTOR_OBJECT(Controller, Controller(), 0, Default_Controller_Controller_SERIALIZE, Controller_C);
    setActiveContext(theActiveContext, false);
    door = NULL;
    loweredSensor = NULL;
    initStatechart();
}

Controller_C::~Controller_C() {
    NOTIFY_DESTRUCTOR(~Controller, true);
    cleanUpRelations();
}

GarageDoor_C* Controller_C::getDoor() const {
    return door;
}

void Controller_C::setDoor(GarageDoor_C* p_GarageDoor) {
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

Sensor* Controller_C::getLoweredSensor() const {
    return loweredSensor;
}

void Controller_C::setLoweredSensor(Sensor* p_Sensor) {
    loweredSensor = p_Sensor;
    if(p_Sensor != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("loweredSensor", p_Sensor, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("loweredSensor");
        }
}

bool Controller_C::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Controller_C::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void Controller_C::cleanUpRelations() {
    if(door != NULL)
        {
            NOTIFY_RELATION_CLEARED("door");
            door = NULL;
        }
    if(loweredSensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("loweredSensor");
            loweredSensor = NULL;
        }
}

void Controller_C::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        //#[ transition 0 
        // BOO SETUP FOR EVERYTHING!
        
        RaisedSensor.limit = 100;
        loweredSensor.limit = 0;
        //#]
        NOTIFY_STATE_ENTERED("ROOT.main");
        rootState_subState = main;
        rootState_active = main;
        //#[ state main.(Entry) 
        std::string cmd;
        
        std::cout << "gd-controller> ";
        std::cin >> cmd;
        
        if (cmd.compare("up") == 0) {
          GEN(pushup);
        } else if (cmd.compare("down") == 0) {
          GEN(pushdown);
        } else if (cmd.compare("interrupt") == 0) {
          GEN(pushinterrupt);
        } else {
          std::cout << "[[ invalid command: " << cmd << std::endl;
          GEN(mainloop);
        }
        //#]
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus Controller_C::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        // State main
        case main:
        {
            if(IS_EVENT_TYPE_OF(pushdown_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("2");
                    NOTIFY_STATE_EXITED("ROOT.main");
                    //#[ transition 2 
                    GEN(up);
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.action");
                    rootState_subState = action;
                    rootState_active = action;
                    //#[ state action.(Entry) 
                    GEN(mainloop);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("2");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(pushup_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.main");
                    //#[ transition 1 
                    GEN(up);
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.action");
                    rootState_subState = action;
                    rootState_active = action;
                    //#[ state action.(Entry) 
                    GEN(mainloop);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(pushinterrupt_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("3");
                    NOTIFY_STATE_EXITED("ROOT.main");
                    //#[ transition 3 
                    GEN(down);
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.action");
                    rootState_subState = action;
                    rootState_active = action;
                    //#[ state action.(Entry) 
                    GEN(mainloop);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("3");
                    res = eventConsumed;
                }
            
        }
        break;
        // State action
        case action:
        {
            if(IS_EVENT_TYPE_OF(mainloop_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("4");
                    NOTIFY_STATE_EXITED("ROOT.action");
                    NOTIFY_STATE_ENTERED("ROOT.main");
                    rootState_subState = main;
                    rootState_active = main;
                    //#[ state main.(Entry) 
                    std::string cmd;
                    
                    std::cout << "gd-controller> ";
                    std::cin >> cmd;
                    
                    if (cmd.compare("up") == 0) {
                      GEN(pushup);
                    } else if (cmd.compare("down") == 0) {
                      GEN(pushdown);
                    } else if (cmd.compare("interrupt") == 0) {
                      GEN(pushinterrupt);
                    } else {
                      std::cout << "[[ invalid command: " << cmd << std::endl;
                      GEN(mainloop);
                    }
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("4");
                    res = eventConsumed;
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
void OMAnimatedController_C::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("door", false, true);
    if(myReal->door)
        {
            aomsRelations->ADD_ITEM(myReal->door);
        }
    aomsRelations->addRelation("loweredSensor", false, true);
    if(myReal->loweredSensor)
        {
            aomsRelations->ADD_ITEM(myReal->loweredSensor);
        }
}

void OMAnimatedController_C::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Controller_C::main:
        {
            main_serializeStates(aomsState);
        }
        break;
        case Controller_C::action:
        {
            action_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedController_C::main_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.main");
}

void OMAnimatedController_C::action_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.action");
}
//#]

IMPLEMENT_REACTIVE_META_OBJECT_P(Controller, Controller_C, Default, Default, false, OMAnimatedController_C)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Controller.cpp
*********************************************************************/
