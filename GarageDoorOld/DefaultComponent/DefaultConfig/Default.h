/*********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Default
//!	Generated Date	: Fri, 10, May 2013  
	File Path	: DefaultComponent\DefaultConfig\Default.h
*********************************************************************/

#ifndef Default_H
#define Default_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
//## auto_generated
#include <cstdio>
//## auto_generated
#include <string>
//## auto_generated
#include <oxf\event.h>
//## classInstance Controller
class Controller_C;

//## classInstance GarageDoor
class GarageDoor_C;

//## classInstance Motor
class Motor_C;

//## classInstance LoweredSensor
class Sensor;

//#[ ignore
#define down_Default_id 18601

#define up_Default_id 18602

#define sensor_Default_id 18603

#define interrupt_Default_id 18604

#define overcurrent_Default_id 18605

#define pass_Default_id 18606

#define start_Default_id 18607

#define initialize_Default_id 18608

#define time_Default_id 18609

#define mainloop_Default_id 18610

#define pushup_Default_id 18611

#define pushdown_Default_id 18612

#define pushinterrupt_Default_id 18613
//#]

//## package Default


//## classInstance Controller
extern Controller_C Controller;

//## classInstance GarageDoor
extern GarageDoor_C GarageDoor;

//## classInstance LoweredSensor
extern Sensor LoweredSensor;

//## classInstance Motor
extern Motor_C Motor;

//## classInstance RaisedSensor
extern Sensor RaisedSensor;

//## auto_generated
void Default_initRelations();

//## auto_generated
bool Default_startBehavior();

//#[ ignore
class Default_OMInitializer {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    Default_OMInitializer();
    
    //## auto_generated
    ~Default_OMInitializer();
};
//#]

//## event down()
class down : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimateddown;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    down();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimateddown : virtual public AOMEvent {
    DECLARE_META_EVENT(down)
};
//#]
#endif // _OMINSTRUMENT

//## event up()
class up : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedup;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    up();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedup : virtual public AOMEvent {
    DECLARE_META_EVENT(up)
};
//#]
#endif // _OMINSTRUMENT

//## event sensor()
class sensor : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedsensor;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    sensor();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedsensor : virtual public AOMEvent {
    DECLARE_META_EVENT(sensor)
};
//#]
#endif // _OMINSTRUMENT

//## event interrupt()
class interrupt : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedinterrupt;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    interrupt();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedinterrupt : virtual public AOMEvent {
    DECLARE_META_EVENT(interrupt)
};
//#]
#endif // _OMINSTRUMENT

//## event overcurrent()
class overcurrent : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedovercurrent;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    overcurrent();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedovercurrent : virtual public AOMEvent {
    DECLARE_META_EVENT(overcurrent)
};
//#]
#endif // _OMINSTRUMENT

//## event pass()
class pass : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedpass;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    pass();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedpass : virtual public AOMEvent {
    DECLARE_META_EVENT(pass)
};
//#]
#endif // _OMINSTRUMENT

//## event start()
class start : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedstart;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    start();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedstart : virtual public AOMEvent {
    DECLARE_META_EVENT(start)
};
//#]
#endif // _OMINSTRUMENT

//## event initialize()
class initialize : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedinitialize;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    initialize();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedinitialize : virtual public AOMEvent {
    DECLARE_META_EVENT(initialize)
};
//#]
#endif // _OMINSTRUMENT

//## event time()
class time : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedtime;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    time();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedtime : virtual public AOMEvent {
    DECLARE_META_EVENT(time)
};
//#]
#endif // _OMINSTRUMENT

//## event mainloop()
class mainloop : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedmainloop;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    mainloop();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedmainloop : virtual public AOMEvent {
    DECLARE_META_EVENT(mainloop)
};
//#]
#endif // _OMINSTRUMENT

//## event pushup()
class pushup : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedpushup;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    pushup();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedpushup : virtual public AOMEvent {
    DECLARE_META_EVENT(pushup)
};
//#]
#endif // _OMINSTRUMENT

//## event pushdown()
class pushdown : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedpushdown;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    pushdown();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedpushdown : virtual public AOMEvent {
    DECLARE_META_EVENT(pushdown)
};
//#]
#endif // _OMINSTRUMENT

//## event pushinterrupt()
class pushinterrupt : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedpushinterrupt;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    pushinterrupt();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedpushinterrupt : virtual public AOMEvent {
    DECLARE_META_EVENT(pushinterrupt)
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Default.h
*********************************************************************/
