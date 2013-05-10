/*********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Motor
//!	Generated Date	: Fri, 10, May 2013  
	File Path	: DefaultComponent\DefaultConfig\Motor.h
*********************************************************************/

#ifndef Motor_H
#define Motor_H

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
//## link door
class GarageDoor_C;

//## package Default

//## class TopLevel::Motor
class Motor_C {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedMotor_C;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Motor_C();
    
    //## auto_generated
    ~Motor_C();
    
    ////    Operations    ////
    
    //## operation move(int)
    void move(int delta);
    
    ////    Additional operations    ////
    
    //## auto_generated
    GarageDoor_C* getDoor() const;
    
    //## auto_generated
    void setDoor(GarageDoor_C* p_GarageDoor);

protected :

    //## auto_generated
    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    GarageDoor_C* door;		//## link door
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedMotor_C : virtual public AOMInstance {
    DECLARE_META(Motor_C, OMAnimatedMotor_C)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Motor.h
*********************************************************************/
