/*********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: GarageDoor
//!	Generated Date	: Fri, 10, May 2013  
	File Path	: DefaultComponent\DefaultConfig\GarageDoor.h
*********************************************************************/

#ifndef GarageDoor_H
#define GarageDoor_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
//## auto_generated
#include <iostream>
//## auto_generated
#include <string>
//## auto_generated
#include "Default.h"
//## auto_generated
#include <oxf\omthread.h>
//## auto_generated
#include <oxf\omreactive.h>
//## auto_generated
#include <oxf\state.h>
//## auto_generated
#include <oxf\event.h>
//## package Default

//## class TopLevel::GarageDoor
class GarageDoor_C : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedGarageDoor_C;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    GarageDoor_C(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~GarageDoor_C();
    
    ////    Additional operations    ////
    
    //## auto_generated
    int getPosition() const;
    
    //## auto_generated
    void setPosition(int p_position);
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    //## auto_generated
    void cancelTimeouts();
    
    //## auto_generated
    bool cancelTimeout(const IOxfTimeout* arg);
    
    ////    Attributes    ////
    
    int position;		//## attribute position
    
    ////    Framework operations    ////

public :

    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // raising:
    //## statechart_method
    inline bool raising_IN() const;
    
    //## statechart_method
    void raising_entDef();
    
    //## statechart_method
    void raising_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus raising_handleEvent();
    
    // move:
    //## statechart_method
    inline bool move_IN() const;
    
    // raised:
    //## statechart_method
    inline bool raised_IN() const;
    
    // lowering:
    //## statechart_method
    inline bool lowering_IN() const;
    
    //## statechart_method
    void lowering_entDef();
    
    //## statechart_method
    void lowering_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus lowering_handleEvent();
    
    // lowering_move:
    //## statechart_method
    inline bool lowering_move_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus lowering_move_handleEvent();
    
    // lowered:
    //## statechart_method
    inline bool lowered_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum GarageDoor_Enum {
        OMNonState = 0,
        raising = 1,
        move = 2,
        raised = 3,
        lowering = 4,
        lowering_move = 5,
        lowered = 6
    };
    
    int rootState_subState;
    
    int rootState_active;
    
    int raising_subState;
    
    IOxfTimeout* raising_timeout;
    
    int lowering_subState;
    
    IOxfTimeout* lowering_timeout;
//#]
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedGarageDoor_C : virtual public AOMInstance {
    DECLARE_REACTIVE_META(GarageDoor_C, OMAnimatedGarageDoor_C)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void raising_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void move_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void raised_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void lowering_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void lowering_move_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void lowered_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline bool GarageDoor_C::rootState_IN() const {
    return true;
}

inline bool GarageDoor_C::raising_IN() const {
    return rootState_subState == raising;
}

inline bool GarageDoor_C::move_IN() const {
    return raising_subState == move;
}

inline bool GarageDoor_C::raised_IN() const {
    return rootState_subState == raised;
}

inline bool GarageDoor_C::lowering_IN() const {
    return rootState_subState == lowering;
}

inline bool GarageDoor_C::lowering_move_IN() const {
    return lowering_subState == lowering_move;
}

inline bool GarageDoor_C::lowered_IN() const {
    return rootState_subState == lowered;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\GarageDoor.h
*********************************************************************/
