/*********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Switch
//!	Generated Date	: Mon, 22, Apr 2013  
	File Path	: DefaultComponent\DefaultConfig\Switch.h
*********************************************************************/

#ifndef Switch_H
#define Switch_H

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
//## link itsLight
class Light_C;

//## package Default

//## class TopLevel::Switch
class Switch_C : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedSwitch_C;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Switch_C(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~Switch_C();
    
    ////    Operations    ////
    
    //## operation flip()
    void flip();
    
    ////    Additional operations    ////
    
    //## auto_generated
    Light_C* getItsLight() const;
    
    //## auto_generated
    void setItsLight(Light_C* p_Light);
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    //## auto_generated
    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    Light_C* itsLight;		//## link itsLight
    
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
    enum Switch_Enum {
        OMNonState = 0
    };
    
    int rootState_subState;
    
    int rootState_active;
//#]
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedSwitch_C : virtual public AOMInstance {
    DECLARE_REACTIVE_META(Switch_C, OMAnimatedSwitch_C)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline bool Switch_C::rootState_IN() const {
    return true;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Switch.h
*********************************************************************/
