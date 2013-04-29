/*********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aLight
//!	Generated Date	: Mon, 22, Apr 2013  
	File Path	: DefaultComponent\DefaultConfig\aLight.h
*********************************************************************/

#ifndef aLight_H
#define aLight_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include "Default.h"
//## auto_generated
#include <oxf\omreactive.h>
//## auto_generated
#include <oxf\state.h>
//## auto_generated
#include <oxf\event.h>
//## package Default

//## class TopLevel::aLight
class aLight_C : public OMReactive {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    aLight_C(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~aLight_C();
    
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
    enum aLight_Enum {
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

inline bool aLight_C::rootState_IN() const {
    return true;
}

inline bool aLight_C::Active_IN() const {
    return rootState_subState == Active;
}

inline bool aLight_C::ON_IN() const {
    return Active_subState == ON;
}

inline bool aLight_C::OFF_IN() const {
    return Active_subState == OFF;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aLight.h
*********************************************************************/
