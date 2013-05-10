/*********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Sensor
//!	Generated Date	: Fri, 10, May 2013  
	File Path	: DefaultComponent\DefaultConfig\Sensor.h
*********************************************************************/

#ifndef Sensor_H
#define Sensor_H

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

//## package Default

//## class Sensor
class Sensor : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedSensor;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Sensor(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~Sensor();
    
    ////    Operations    ////
    
    //## operation set(int)
    void set(int value);
    
    ////    Additional operations    ////
    
    //## auto_generated
    int getLimit() const;
    
    //## auto_generated
    void setLimit(int p_limit);
    
    //## auto_generated
    int getValue() const;
    
    //## auto_generated
    void setValue(int p_value);
    
    //## auto_generated
    GarageDoor_C* getDoor() const;
    
    //## auto_generated
    void setDoor(GarageDoor_C* p_GarageDoor);
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    //## auto_generated
    void cleanUpRelations();
    
    ////    Attributes    ////
    
    int limit;		//## attribute limit
    
    int value;		//## attribute value
    
    ////    Relations and components    ////
    
    GarageDoor_C* door;		//## link door
    
    ////    Framework operations    ////

public :

    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // under:
    //## statechart_method
    inline bool under_IN() const;
    
    // over:
    //## statechart_method
    inline bool over_IN() const;
    
    // init:
    //## statechart_method
    inline bool init_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum Sensor_Enum {
        OMNonState = 0,
        under = 1,
        over = 2,
        init = 3
    };
    
    int rootState_subState;
    
    int rootState_active;
//#]
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedSensor : virtual public AOMInstance {
    DECLARE_REACTIVE_META(Sensor, OMAnimatedSensor)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void under_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void over_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void init_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline bool Sensor::rootState_IN() const {
    return true;
}

inline bool Sensor::under_IN() const {
    return rootState_subState == under;
}

inline bool Sensor::over_IN() const {
    return rootState_subState == over;
}

inline bool Sensor::init_IN() const {
    return rootState_subState == init;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Sensor.h
*********************************************************************/
