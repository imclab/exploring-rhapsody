/********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: GarageDoor
//!	Generated Date	: Fri, 10, May 2013  
	File Path	: DefaultComponent\DefaultConfig\GarageDoor.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "GarageDoor.h"
//## link motor
#include "Motor.h"
//#[ ignore
#define Default_GarageDoor_GarageDoor_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class TopLevel::GarageDoor
GarageDoor_C::GarageDoor_C(IOxfActive* theActiveContext) {
    NOTIFY_REACTIVE_CONSTRUCTOR_OBJECT(GarageDoor, GarageDoor(), 0, Default_GarageDoor_GarageDoor_SERIALIZE, GarageDoor_C);
    setActiveContext(theActiveContext, false);
    motor = NULL;
    initStatechart();
}

GarageDoor_C::~GarageDoor_C() {
    NOTIFY_DESTRUCTOR(~GarageDoor, true);
    cleanUpRelations();
    cancelTimeouts();
}

unsigned int GarageDoor_C::getPosition() const {
    return position;
}

void GarageDoor_C::setPosition(unsigned int p_position) {
    position = p_position;
}

Motor_C* GarageDoor_C::getMotor() const {
    return motor;
}

void GarageDoor_C::setMotor(Motor_C* p_Motor) {
    motor = p_Motor;
    if(p_Motor != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("motor", p_Motor, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("motor");
        }
}

bool GarageDoor_C::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void GarageDoor_C::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    raising_subState = OMNonState;
    raising_timeout = NULL;
    lowering_subState = OMNonState;
    lowering_timeout = NULL;
}

void GarageDoor_C::cleanUpRelations() {
    if(motor != NULL)
        {
            NOTIFY_RELATION_CLEARED("motor");
            motor = NULL;
        }
}

void GarageDoor_C::cancelTimeouts() {
    cancel(raising_timeout);
    cancel(lowering_timeout);
}

bool GarageDoor_C::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(raising_timeout == arg)
        {
            raising_timeout = NULL;
            res = true;
        }
    if(lowering_timeout == arg)
        {
            lowering_timeout = NULL;
            res = true;
        }
    return res;
}

void GarageDoor_C::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        //#[ transition 0 
        position = 100;
        //#]
        NOTIFY_STATE_ENTERED("ROOT.lowered");
        rootState_subState = lowered;
        rootState_active = lowered;
        //#[ state lowered.(Entry) 
        GEN(up);
        //#]
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus GarageDoor_C::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        // State lowered
        case lowered:
        {
            if(IS_EVENT_TYPE_OF(up_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.lowered");
                    raising_entDef();
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            
        }
        break;
        // State raised
        case raised:
        {
            if(IS_EVENT_TYPE_OF(down_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("3");
                    NOTIFY_STATE_EXITED("ROOT.raised");
                    lowering_entDef();
                    NOTIFY_TRANSITION_TERMINATED("3");
                    res = eventConsumed;
                }
            
        }
        break;
        // State main
        case main:
        {
            res = main_handleEvent();
        }
        break;
        // State main
        case lowering_main:
        {
            res = lowering_main_handleEvent();
        }
        break;
        // State stopped
        case stopped:
        {
            if(IS_EVENT_TYPE_OF(down_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("7");
                    NOTIFY_STATE_EXITED("ROOT.stopped");
                    lowering_entDef();
                    NOTIFY_TRANSITION_TERMINATED("7");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(up_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("6");
                    NOTIFY_STATE_EXITED("ROOT.stopped");
                    raising_entDef();
                    NOTIFY_TRANSITION_TERMINATED("6");
                    res = eventConsumed;
                }
            
        }
        break;
        default:
            break;
    }
    return res;
}

void GarageDoor_C::raising_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.raising");
    rootState_subState = raising;
    NOTIFY_TRANSITION_STARTED("10");
    NOTIFY_STATE_ENTERED("ROOT.raising.main");
    raising_subState = main;
    rootState_active = main;
    raising_timeout = scheduleTimeout(100, "ROOT.raising.main");
    NOTIFY_TRANSITION_TERMINATED("10");
}

void GarageDoor_C::raising_exit() {
    // State main
    if(raising_subState == main)
        {
            cancel(raising_timeout);
            NOTIFY_STATE_EXITED("ROOT.raising.main");
        }
    raising_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.raising");
}

IOxfReactive::TakeEventStatus GarageDoor_C::raising_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(overcurrent_Default_id))
        {
            NOTIFY_TRANSITION_STARTED("2");
            raising_exit();
            NOTIFY_STATE_ENTERED("ROOT.raised");
            rootState_subState = raised;
            rootState_active = raised;
            NOTIFY_TRANSITION_TERMINATED("2");
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(interrupt_Default_id))
        {
            NOTIFY_TRANSITION_STARTED("5");
            raising_exit();
            NOTIFY_STATE_ENTERED("ROOT.stopped");
            rootState_subState = stopped;
            rootState_active = stopped;
            NOTIFY_TRANSITION_TERMINATED("5");
            res = eventConsumed;
        }
    
    return res;
}

IOxfReactive::TakeEventStatus GarageDoor_C::main_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == raising_timeout)
                {
                    NOTIFY_TRANSITION_STARTED("9");
                    cancel(raising_timeout);
                    NOTIFY_STATE_EXITED("ROOT.raising.main");
                    //#[ transition 9 
                    Motor.move(-1);
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.raising.main");
                    raising_subState = main;
                    rootState_active = main;
                    raising_timeout = scheduleTimeout(100, "ROOT.raising.main");
                    NOTIFY_TRANSITION_TERMINATED("9");
                    res = eventConsumed;
                }
        }
    
    if(res == eventNotConsumed)
        {
            res = raising_handleEvent();
        }
    return res;
}

void GarageDoor_C::lowering_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.lowering");
    rootState_subState = lowering;
    NOTIFY_TRANSITION_STARTED("11");
    NOTIFY_STATE_ENTERED("ROOT.lowering.main");
    lowering_subState = lowering_main;
    rootState_active = lowering_main;
    lowering_timeout = scheduleTimeout(100, "ROOT.lowering.main");
    NOTIFY_TRANSITION_TERMINATED("11");
}

void GarageDoor_C::lowering_exit() {
    // State main
    if(lowering_subState == lowering_main)
        {
            cancel(lowering_timeout);
            NOTIFY_STATE_EXITED("ROOT.lowering.main");
        }
    lowering_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.lowering");
}

IOxfReactive::TakeEventStatus GarageDoor_C::lowering_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(overcurrent_Default_id))
        {
            NOTIFY_TRANSITION_STARTED("4");
            lowering_exit();
            NOTIFY_STATE_ENTERED("ROOT.lowered");
            rootState_subState = lowered;
            rootState_active = lowered;
            //#[ state lowered.(Entry) 
            GEN(up);
            //#]
            NOTIFY_TRANSITION_TERMINATED("4");
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(interrupt_Default_id))
        {
            NOTIFY_TRANSITION_STARTED("8");
            lowering_exit();
            NOTIFY_STATE_ENTERED("ROOT.stopped");
            rootState_subState = stopped;
            rootState_active = stopped;
            NOTIFY_TRANSITION_TERMINATED("8");
            res = eventConsumed;
        }
    
    return res;
}

IOxfReactive::TakeEventStatus GarageDoor_C::lowering_main_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == lowering_timeout)
                {
                    NOTIFY_TRANSITION_STARTED("12");
                    cancel(lowering_timeout);
                    NOTIFY_STATE_EXITED("ROOT.lowering.main");
                    NOTIFY_STATE_ENTERED("ROOT.lowering.main");
                    lowering_subState = lowering_main;
                    rootState_active = lowering_main;
                    lowering_timeout = scheduleTimeout(100, "ROOT.lowering.main");
                    NOTIFY_TRANSITION_TERMINATED("12");
                    res = eventConsumed;
                }
        }
    
    if(res == eventNotConsumed)
        {
            res = lowering_handleEvent();
        }
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedGarageDoor_C::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("position", x2String(myReal->position));
}

void OMAnimatedGarageDoor_C::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("motor", false, true);
    if(myReal->motor)
        {
            aomsRelations->ADD_ITEM(myReal->motor);
        }
}

void OMAnimatedGarageDoor_C::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case GarageDoor_C::lowered:
        {
            lowered_serializeStates(aomsState);
        }
        break;
        case GarageDoor_C::raised:
        {
            raised_serializeStates(aomsState);
        }
        break;
        case GarageDoor_C::raising:
        {
            raising_serializeStates(aomsState);
        }
        break;
        case GarageDoor_C::lowering:
        {
            lowering_serializeStates(aomsState);
        }
        break;
        case GarageDoor_C::stopped:
        {
            stopped_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedGarageDoor_C::stopped_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.stopped");
}

void OMAnimatedGarageDoor_C::raising_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.raising");
    if(myReal->raising_subState == GarageDoor_C::main)
        {
            main_serializeStates(aomsState);
        }
}

void OMAnimatedGarageDoor_C::main_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.raising.main");
}

void OMAnimatedGarageDoor_C::raised_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.raised");
}

void OMAnimatedGarageDoor_C::lowering_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.lowering");
    if(myReal->lowering_subState == GarageDoor_C::lowering_main)
        {
            lowering_main_serializeStates(aomsState);
        }
}

void OMAnimatedGarageDoor_C::lowering_main_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.lowering.main");
}

void OMAnimatedGarageDoor_C::lowered_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.lowered");
}
//#]

IMPLEMENT_REACTIVE_META_OBJECT_P(GarageDoor, GarageDoor_C, Default, Default, false, OMAnimatedGarageDoor_C)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\GarageDoor.cpp
*********************************************************************/
