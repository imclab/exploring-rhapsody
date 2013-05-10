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
//#[ ignore
#define Default_GarageDoor_GarageDoor_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class TopLevel::GarageDoor
GarageDoor_C::GarageDoor_C(IOxfActive* theActiveContext) {
    NOTIFY_REACTIVE_CONSTRUCTOR_OBJECT(GarageDoor, GarageDoor(), 0, Default_GarageDoor_GarageDoor_SERIALIZE, GarageDoor_C);
    setActiveContext(theActiveContext, false);
    initStatechart();
}

GarageDoor_C::~GarageDoor_C() {
    NOTIFY_DESTRUCTOR(~GarageDoor, true);
    cancelTimeouts();
}

int GarageDoor_C::getPosition() const {
    return position;
}

void GarageDoor_C::setPosition(int p_position) {
    position = p_position;
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
        NOTIFY_STATE_ENTERED("ROOT.lowered");
        rootState_subState = lowered;
        rootState_active = lowered;
        //#[ state lowered.(Entry) 
        prompt();
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
                    //#[ transition 1 
                    std::cout << "<< up" << std::endl;
                    //#]
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
                    NOTIFY_TRANSITION_STARTED("4");
                    NOTIFY_STATE_EXITED("ROOT.raised");
                    lowering_entDef();
                    NOTIFY_TRANSITION_TERMINATED("4");
                    res = eventConsumed;
                }
            
        }
        break;
        // State move
        case move:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == raising_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("6");
                            cancel(raising_timeout);
                            NOTIFY_STATE_EXITED("ROOT.raising.move");
                            //#[ transition 6 
                            position++;
                            
                            if (position >= 10) {
                            	position = 10;
                            	GEN(overcurrent);
                            }
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.raising.move");
                            raising_subState = move;
                            rootState_active = move;
                            raising_timeout = scheduleTimeout(500, "ROOT.raising.move");
                            NOTIFY_TRANSITION_TERMINATED("6");
                            res = eventConsumed;
                        }
                }
            
            if(res == eventNotConsumed)
                {
                    res = raising_handleEvent();
                }
        }
        break;
        // State move
        case lowering_move:
        {
            res = lowering_move_handleEvent();
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
    //#[ state raising.(Entry) 
    std::cout << "(( raising" << std::endl;
    prompt();
    //#]
    NOTIFY_TRANSITION_STARTED("8");
    NOTIFY_STATE_ENTERED("ROOT.raising.move");
    raising_subState = move;
    rootState_active = move;
    raising_timeout = scheduleTimeout(500, "ROOT.raising.move");
    NOTIFY_TRANSITION_TERMINATED("8");
}

void GarageDoor_C::raising_exit() {
    // State move
    if(raising_subState == move)
        {
            cancel(raising_timeout);
            NOTIFY_STATE_EXITED("ROOT.raising.move");
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
            //#[ state raised.(Entry) 
            prompt();
            //#]
            NOTIFY_TRANSITION_TERMINATED("2");
            res = eventConsumed;
        }
    
    return res;
}

void GarageDoor_C::lowering_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.lowering");
    rootState_subState = lowering;
    //#[ state lowering.(Entry) 
    prompt();
    //#]
    NOTIFY_TRANSITION_STARTED("9");
    NOTIFY_STATE_ENTERED("ROOT.lowering.move");
    lowering_subState = lowering_move;
    rootState_active = lowering_move;
    lowering_timeout = scheduleTimeout(500, "ROOT.lowering.move");
    NOTIFY_TRANSITION_TERMINATED("9");
}

void GarageDoor_C::lowering_exit() {
    // State move
    if(lowering_subState == lowering_move)
        {
            cancel(lowering_timeout);
            NOTIFY_STATE_EXITED("ROOT.lowering.move");
        }
    lowering_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.lowering");
}

IOxfReactive::TakeEventStatus GarageDoor_C::lowering_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(overcurrent_Default_id))
        {
            NOTIFY_TRANSITION_STARTED("3");
            lowering_exit();
            NOTIFY_STATE_ENTERED("ROOT.lowered");
            rootState_subState = lowered;
            rootState_active = lowered;
            //#[ state lowered.(Entry) 
            prompt();
            //#]
            NOTIFY_TRANSITION_TERMINATED("3");
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(interruption_Default_id))
        {
            NOTIFY_TRANSITION_STARTED("5");
            lowering_exit();
            raising_entDef();
            NOTIFY_TRANSITION_TERMINATED("5");
            res = eventConsumed;
        }
    
    return res;
}

IOxfReactive::TakeEventStatus GarageDoor_C::lowering_move_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == lowering_timeout)
                {
                    NOTIFY_TRANSITION_STARTED("7");
                    cancel(lowering_timeout);
                    NOTIFY_STATE_EXITED("ROOT.lowering.move");
                    //#[ transition 7 
                    position--;
                    
                    if (position <= 0) {
                    	position = 0;
                    	GEN(overcurrent);
                    }
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.lowering.move");
                    lowering_subState = lowering_move;
                    rootState_active = lowering_move;
                    lowering_timeout = scheduleTimeout(500, "ROOT.lowering.move");
                    NOTIFY_TRANSITION_TERMINATED("7");
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
        default:
            break;
    }
}

void OMAnimatedGarageDoor_C::raising_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.raising");
    if(myReal->raising_subState == GarageDoor_C::move)
        {
            move_serializeStates(aomsState);
        }
}

void OMAnimatedGarageDoor_C::move_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.raising.move");
}

void OMAnimatedGarageDoor_C::raised_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.raised");
}

void OMAnimatedGarageDoor_C::lowering_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.lowering");
    if(myReal->lowering_subState == GarageDoor_C::lowering_move)
        {
            lowering_move_serializeStates(aomsState);
        }
}

void OMAnimatedGarageDoor_C::lowering_move_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.lowering.move");
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
