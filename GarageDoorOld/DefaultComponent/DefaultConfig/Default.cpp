/********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Default
//!	Generated Date	: Fri, 10, May 2013  
	File Path	: DefaultComponent\DefaultConfig\Default.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Default.h"
//## classInstance Controller
#include "Controller.h"
//## classInstance GarageDoor
#include "GarageDoor.h"
//## classInstance Motor
#include "Motor.h"
//## classInstance LoweredSensor
#include "Sensor.h"
//#[ ignore
#define down_SERIALIZE OM_NO_OP

#define down_UNSERIALIZE OM_NO_OP

#define down_CONSTRUCTOR down()

#define up_SERIALIZE OM_NO_OP

#define up_UNSERIALIZE OM_NO_OP

#define up_CONSTRUCTOR up()

#define sensor_SERIALIZE OM_NO_OP

#define sensor_UNSERIALIZE OM_NO_OP

#define sensor_CONSTRUCTOR sensor()

#define interrupt_SERIALIZE OM_NO_OP

#define interrupt_UNSERIALIZE OM_NO_OP

#define interrupt_CONSTRUCTOR interrupt()

#define overcurrent_SERIALIZE OM_NO_OP

#define overcurrent_UNSERIALIZE OM_NO_OP

#define overcurrent_CONSTRUCTOR overcurrent()

#define pass_SERIALIZE OM_NO_OP

#define pass_UNSERIALIZE OM_NO_OP

#define pass_CONSTRUCTOR pass()

#define start_SERIALIZE OM_NO_OP

#define start_UNSERIALIZE OM_NO_OP

#define start_CONSTRUCTOR start()

#define initialize_SERIALIZE OM_NO_OP

#define initialize_UNSERIALIZE OM_NO_OP

#define initialize_CONSTRUCTOR initialize()

#define time_SERIALIZE OM_NO_OP

#define time_UNSERIALIZE OM_NO_OP

#define time_CONSTRUCTOR time()

#define mainloop_SERIALIZE OM_NO_OP

#define mainloop_UNSERIALIZE OM_NO_OP

#define mainloop_CONSTRUCTOR mainloop()

#define pushup_SERIALIZE OM_NO_OP

#define pushup_UNSERIALIZE OM_NO_OP

#define pushup_CONSTRUCTOR pushup()

#define pushdown_SERIALIZE OM_NO_OP

#define pushdown_UNSERIALIZE OM_NO_OP

#define pushdown_CONSTRUCTOR pushdown()

#define pushinterrupt_SERIALIZE OM_NO_OP

#define pushinterrupt_UNSERIALIZE OM_NO_OP

#define pushinterrupt_CONSTRUCTOR pushinterrupt()
//#]

//## package Default


//## classInstance Controller
Controller_C Controller;

//## classInstance GarageDoor
GarageDoor_C GarageDoor;

//## classInstance LoweredSensor
Sensor LoweredSensor;

//## classInstance Motor
Motor_C Motor;

//## classInstance RaisedSensor
Sensor RaisedSensor;

#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */);

static void RenameGlobalInstances();

IMPLEMENT_META_PACKAGE(Default, Default)
#endif // _OMINSTRUMENT

void Default_initRelations() {
    {
        {
            GarageDoor.setShouldDelete(false);
        }
        {
            Controller.setShouldDelete(false);
        }
        {
            RaisedSensor.setShouldDelete(false);
        }
        {
            LoweredSensor.setShouldDelete(false);
        }
    }
    LoweredSensor.setDoor(&GarageDoor);
    RaisedSensor.setDoor(&GarageDoor);
    
    #ifdef _OMINSTRUMENT
    RenameGlobalInstances();
    #endif // _OMINSTRUMENT
}

bool Default_startBehavior() {
    bool done = true;
    done &= Controller.startBehavior();
    done &= GarageDoor.startBehavior();
    done &= LoweredSensor.startBehavior();
    done &= RaisedSensor.startBehavior();
    return done;
}

#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */) {
}

static void RenameGlobalInstances() {
    OM_SET_INSTANCE_NAME(&GarageDoor, GarageDoor, "GarageDoor", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&Controller, Controller, "Controller", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&Motor, Motor, "Motor", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&RaisedSensor, Sensor, "RaisedSensor", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&LoweredSensor, Sensor, "LoweredSensor", AOMNoMultiplicity);
}
#endif // _OMINSTRUMENT

//#[ ignore
Default_OMInitializer::Default_OMInitializer() {
    Default_initRelations();
    Default_startBehavior();
}

Default_OMInitializer::~Default_OMInitializer() {
}
//#]

//## event down()
down::down() {
    NOTIFY_EVENT_CONSTRUCTOR(down)
    setId(down_Default_id);
}

bool down::isTypeOf(const short id) const {
    return (down_Default_id==id);
}

IMPLEMENT_META_EVENT_P(down, Default, Default, down())

//## event up()
up::up() {
    NOTIFY_EVENT_CONSTRUCTOR(up)
    setId(up_Default_id);
}

bool up::isTypeOf(const short id) const {
    return (up_Default_id==id);
}

IMPLEMENT_META_EVENT_P(up, Default, Default, up())

//## event sensor()
sensor::sensor() {
    NOTIFY_EVENT_CONSTRUCTOR(sensor)
    setId(sensor_Default_id);
}

bool sensor::isTypeOf(const short id) const {
    return (sensor_Default_id==id);
}

IMPLEMENT_META_EVENT_P(sensor, Default, Default, sensor())

//## event interrupt()
interrupt::interrupt() {
    NOTIFY_EVENT_CONSTRUCTOR(interrupt)
    setId(interrupt_Default_id);
}

bool interrupt::isTypeOf(const short id) const {
    return (interrupt_Default_id==id);
}

IMPLEMENT_META_EVENT_P(interrupt, Default, Default, interrupt())

//## event overcurrent()
overcurrent::overcurrent() {
    NOTIFY_EVENT_CONSTRUCTOR(overcurrent)
    setId(overcurrent_Default_id);
}

bool overcurrent::isTypeOf(const short id) const {
    return (overcurrent_Default_id==id);
}

IMPLEMENT_META_EVENT_P(overcurrent, Default, Default, overcurrent())

//## event pass()
pass::pass() {
    NOTIFY_EVENT_CONSTRUCTOR(pass)
    setId(pass_Default_id);
}

bool pass::isTypeOf(const short id) const {
    return (pass_Default_id==id);
}

IMPLEMENT_META_EVENT_P(pass, Default, Default, pass())

//## event start()
start::start() {
    NOTIFY_EVENT_CONSTRUCTOR(start)
    setId(start_Default_id);
}

bool start::isTypeOf(const short id) const {
    return (start_Default_id==id);
}

IMPLEMENT_META_EVENT_P(start, Default, Default, start())

//## event initialize()
initialize::initialize() {
    NOTIFY_EVENT_CONSTRUCTOR(initialize)
    setId(initialize_Default_id);
}

bool initialize::isTypeOf(const short id) const {
    return (initialize_Default_id==id);
}

IMPLEMENT_META_EVENT_P(initialize, Default, Default, initialize())

//## event time()
time::time() {
    NOTIFY_EVENT_CONSTRUCTOR(time)
    setId(time_Default_id);
}

bool time::isTypeOf(const short id) const {
    return (time_Default_id==id);
}

IMPLEMENT_META_EVENT_P(time, Default, Default, time())

//## event mainloop()
mainloop::mainloop() {
    NOTIFY_EVENT_CONSTRUCTOR(mainloop)
    setId(mainloop_Default_id);
}

bool mainloop::isTypeOf(const short id) const {
    return (mainloop_Default_id==id);
}

IMPLEMENT_META_EVENT_P(mainloop, Default, Default, mainloop())

//## event pushup()
pushup::pushup() {
    NOTIFY_EVENT_CONSTRUCTOR(pushup)
    setId(pushup_Default_id);
}

bool pushup::isTypeOf(const short id) const {
    return (pushup_Default_id==id);
}

IMPLEMENT_META_EVENT_P(pushup, Default, Default, pushup())

//## event pushdown()
pushdown::pushdown() {
    NOTIFY_EVENT_CONSTRUCTOR(pushdown)
    setId(pushdown_Default_id);
}

bool pushdown::isTypeOf(const short id) const {
    return (pushdown_Default_id==id);
}

IMPLEMENT_META_EVENT_P(pushdown, Default, Default, pushdown())

//## event pushinterrupt()
pushinterrupt::pushinterrupt() {
    NOTIFY_EVENT_CONSTRUCTOR(pushinterrupt)
    setId(pushinterrupt_Default_id);
}

bool pushinterrupt::isTypeOf(const short id) const {
    return (pushinterrupt_Default_id==id);
}

IMPLEMENT_META_EVENT_P(pushinterrupt, Default, Default, pushinterrupt())

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Default.cpp
*********************************************************************/
