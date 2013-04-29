/*********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Light
//!	Generated Date	: Mon, 22, Apr 2013  
	File Path	: DefaultComponent\DefaultConfig\Light.h
*********************************************************************/

#ifndef Light_H
#define Light_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
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

//## class TopLevel::Light
class Light_C : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedLight_C;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Light_C(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~Light_C();
    
    ////    Additional operations    ////
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    ////    Framework operations    ////

public :

    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // Active:
    //## statechart_method
    inline bool Active_IN() const;
    
    //## statechart_method
    void Active_entDef();
    
    // ON:
    //## statechart_method
    inline bool ON_IN() const;
    
    // OFF:
    //## statechart_method
    inline bool OFF_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum Light_Enum {
        OMNonState = 0,
        Active = 1,
        ON = 2,
        OFF = 3
    };
    
    int rootState_subState;
    
    int rootState_active;
    
    int Active_subState;
//#]
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedLight_C : virtual public AOMInstance {
    DECLARE_REACTIVE_META(Light_C, OMAnimatedLight_C)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Active_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void ON_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void OFF_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline bool Light_C::rootState_IN() const {
    return true;
}

inline bool Light_C::Active_IN() const {
    return rootState_subState == Active;
}

inline bool Light_C::ON_IN() const {
    return Active_subState == ON;
}

inline bool Light_C::OFF_IN() const {
    return Active_subState == OFF;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Light.h
*********************************************************************/
