/*********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Controller
//!	Generated Date	: Fri, 10, May 2013  
	File Path	: DefaultComponent\DefaultConfig\Controller.h
*********************************************************************/

#ifndef Controller_H
#define Controller_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
//## auto_generated
#include <cstdio>
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
//## link door
class GarageDoor_C;

//## link loweredSensor
class Sensor;

//## package Default

//## class TopLevel::Controller
class Controller_C : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedController_C;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Controller_C(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~Controller_C();
    
    ////    Additional operations    ////
    
    //## auto_generated
    GarageDoor_C* getDoor() const;
    
    //## auto_generated
    void setDoor(GarageDoor_C* p_GarageDoor);
    
    //## auto_generated
    Sensor* getLoweredSensor() const;
    
    //## auto_generated
    void setLoweredSensor(Sensor* p_Sensor);
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    //## auto_generated
    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    GarageDoor_C* door;		//## link door
    
    Sensor* loweredSensor;		//## link loweredSensor
    
    ////    Framework operations    ////

public :

    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // main:
    //## statechart_method
    inline bool main_IN() const;
    
    // action:
    //## statechart_method
    inline bool action_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum Controller_Enum {
        OMNonState = 0,
        main = 1,
        action = 2
    };
    
    int rootState_subState;
    
    int rootState_active;
//#]
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedController_C : virtual public AOMInstance {
    DECLARE_REACTIVE_META(Controller_C, OMAnimatedController_C)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void main_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void action_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline bool Controller_C::rootState_IN() const {
    return true;
}

inline bool Controller_C::main_IN() const {
    return rootState_subState == main;
}

inline bool Controller_C::action_IN() const {
    return rootState_subState == action;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Controller.h
*********************************************************************/
