/********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Switch
//!	Generated Date	: Mon, 22, Apr 2013  
	File Path	: DefaultComponent\DefaultConfig\Switch.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "Switch.h"
//## link itsLight
#include "Light.h"
//#[ ignore
#define Default_Switch_Switch_SERIALIZE OM_NO_OP

#define Default_Switch_flip_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class TopLevel::Switch
Switch_C::Switch_C(IOxfActive* theActiveContext) {
    NOTIFY_REACTIVE_CONSTRUCTOR_OBJECT(Switch, Switch(), 0, Default_Switch_Switch_SERIALIZE, Switch_C);
    setActiveContext(theActiveContext, false);
    itsLight = NULL;
    initStatechart();
}

Switch_C::~Switch_C() {
    NOTIFY_DESTRUCTOR(~Switch, true);
    cleanUpRelations();
}

void Switch_C::flip() {
    NOTIFY_OPERATION(flip, flip(), 0, Default_Switch_flip_SERIALIZE);
    //#[ operation flip()
    itsLight->GEN(toggle());
    //#]
}

Light_C* Switch_C::getItsLight() const {
    return itsLight;
}

void Switch_C::setItsLight(Light_C* p_Light) {
    itsLight = p_Light;
    if(p_Light != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsLight", p_Light, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsLight");
        }
}

bool Switch_C::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Switch_C::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void Switch_C::cleanUpRelations() {
    if(itsLight != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsLight");
            itsLight = NULL;
        }
}

void Switch_C::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
    }
}

IOxfReactive::TakeEventStatus Switch_C::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedSwitch_C::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsLight", false, true);
    if(myReal->itsLight)
        {
            aomsRelations->ADD_ITEM(myReal->itsLight);
        }
}

void OMAnimatedSwitch_C::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
}
//#]

IMPLEMENT_REACTIVE_META_OBJECT_P(Switch, Switch_C, Default, Default, false, OMAnimatedSwitch_C)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Switch.cpp
*********************************************************************/
