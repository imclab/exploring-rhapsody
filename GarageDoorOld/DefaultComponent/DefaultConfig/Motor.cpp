/********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Motor
//!	Generated Date	: Fri, 10, May 2013  
	File Path	: DefaultComponent\DefaultConfig\Motor.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Motor.h"
//## link door
#include "GarageDoor.h"
//#[ ignore
#define Default_Motor_Motor_SERIALIZE OM_NO_OP

#define Default_Motor_move_SERIALIZE aomsmethod->addAttribute("delta", x2String(delta));
//#]

//## package Default

//## class TopLevel::Motor
Motor_C::Motor_C() {
    NOTIFY_CONSTRUCTOR_OBJECT(Motor, Motor(), 0, Default_Motor_Motor_SERIALIZE, Motor_C);
    door = NULL;
}

Motor_C::~Motor_C() {
    NOTIFY_DESTRUCTOR(~Motor, true);
    cleanUpRelations();
}

void Motor_C::move(int delta) {
    NOTIFY_OPERATION(move, move(int), 1, Default_Motor_move_SERIALIZE);
    //#[ operation move(int)
    GarageDoor.position += delta;
    std::cout << "Garage Door moved " << delta << std::endl;
    //#]
}

GarageDoor_C* Motor_C::getDoor() const {
    return door;
}

void Motor_C::setDoor(GarageDoor_C* p_GarageDoor) {
    door = p_GarageDoor;
    if(p_GarageDoor != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("door", p_GarageDoor, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("door");
        }
}

void Motor_C::cleanUpRelations() {
    if(door != NULL)
        {
            NOTIFY_RELATION_CLEARED("door");
            door = NULL;
        }
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedMotor_C::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("door", false, true);
    if(myReal->door)
        {
            aomsRelations->ADD_ITEM(myReal->door);
        }
}
//#]

IMPLEMENT_META_OBJECT_P(Motor, Motor_C, Default, Default, false, OMAnimatedMotor_C)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Motor.cpp
*********************************************************************/
