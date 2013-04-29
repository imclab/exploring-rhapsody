/*********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aSwitch
//!	Generated Date	: Mon, 22, Apr 2013  
	File Path	: DefaultComponent\DefaultConfig\aSwitch.h
*********************************************************************/

#ifndef aSwitch_H
#define aSwitch_H

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
//## link itsALight
class aLight_C;

//## package Default

//## class TopLevel::aSwitch
class aSwitch_C : public OMReactive {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    aSwitch_C(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~aSwitch_C();
    
    ////    Operations    ////
    
    //## operation flip()
    void flip();
    
    ////    Additional operations    ////
    
    //## auto_generated
    aLight_C* getItsALight() const;
    
    //## auto_generated
    void setItsALight(aLight_C* p_aLight);
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    //## auto_generated
    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    aLight_C* itsALight;		//## link itsALight
    
    ////    Framework operations    ////

public :

    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    ////    Framework    ////

protected :

//#[ ignore
    enum aSwitch_Enum {
        OMNonState = 0
    };
    
    int rootState_subState;
    
    int rootState_active;
//#]
};

inline bool aSwitch_C::rootState_IN() const {
    return true;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aSwitch.h
*********************************************************************/
