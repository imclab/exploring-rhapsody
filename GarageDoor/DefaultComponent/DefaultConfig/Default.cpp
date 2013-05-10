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
//## classInstance GarageDoor
#include "GarageDoor.h"
//#[ ignore
#define Default_prompt_SERIALIZE OM_NO_OP

#define up_SERIALIZE OM_NO_OP

#define up_UNSERIALIZE OM_NO_OP

#define up_CONSTRUCTOR up()

#define overcurrent_SERIALIZE OM_NO_OP

#define overcurrent_UNSERIALIZE OM_NO_OP

#define overcurrent_CONSTRUCTOR overcurrent()

#define down_SERIALIZE OM_NO_OP

#define down_UNSERIALIZE OM_NO_OP

#define down_CONSTRUCTOR down()

#define infrared_SERIALIZE OM_NO_OP

#define infrared_UNSERIALIZE OM_NO_OP

#define infrared_CONSTRUCTOR infrared()

#define interruption_SERIALIZE OM_NO_OP

#define interruption_UNSERIALIZE OM_NO_OP

#define interruption_CONSTRUCTOR interruption()
//#]

//## package Default


//## classInstance GarageDoor
GarageDoor_C GarageDoor;

#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */);

static void RenameGlobalInstances();

IMPLEMENT_META_PACKAGE(Default, Default)
#endif // _OMINSTRUMENT

//## operation prompt()
void prompt() {
    NOTIFY_FUNCTION(Default, prompt, prompt(), 0, Default_prompt_SERIALIZE);
    //#[ operation prompt()
    std::string cmd;
    bool bad = false;
    
    do {
    	bad = false;
    	
    	std::cout << "remote> ";
    	std::cin >> cmd;
    	
    	if (cmd.compare("up") == 0) {
    		GarageDoor.GEN(up);
    	} else if (cmd.compare("down") == 0) {
    		GarageDoor.GEN(down);
    	} else if (cmd.compare("laser") == 0) {
    		GarageDoor.GEN(interruption);
    	} else {
    		std::cout << "[[ unknown command " << cmd << std::endl;
    		bad = true;
    	}
    } while (bad);
    //#]
}

void Default_initRelations() {
    {
        {
            GarageDoor.setShouldDelete(false);
        }
    }
    
    #ifdef _OMINSTRUMENT
    RenameGlobalInstances();
    #endif // _OMINSTRUMENT
}

bool Default_startBehavior() {
    bool done = true;
    done &= GarageDoor.startBehavior();
    return done;
}

#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */) {
}

static void RenameGlobalInstances() {
    OM_SET_INSTANCE_NAME(&GarageDoor, GarageDoor, "GarageDoor", AOMNoMultiplicity);
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

//## event up()
up::up() {
    NOTIFY_EVENT_CONSTRUCTOR(up)
    setId(up_Default_id);
}

bool up::isTypeOf(const short id) const {
    return (up_Default_id==id);
}

IMPLEMENT_META_EVENT_P(up, Default, Default, up())

//## event overcurrent()
overcurrent::overcurrent() {
    NOTIFY_EVENT_CONSTRUCTOR(overcurrent)
    setId(overcurrent_Default_id);
}

bool overcurrent::isTypeOf(const short id) const {
    return (overcurrent_Default_id==id);
}

IMPLEMENT_META_EVENT_P(overcurrent, Default, Default, overcurrent())

//## event down()
down::down() {
    NOTIFY_EVENT_CONSTRUCTOR(down)
    setId(down_Default_id);
}

bool down::isTypeOf(const short id) const {
    return (down_Default_id==id);
}

IMPLEMENT_META_EVENT_P(down, Default, Default, down())

//## event infrared()
infrared::infrared() {
    NOTIFY_EVENT_CONSTRUCTOR(infrared)
    setId(infrared_Default_id);
}

bool infrared::isTypeOf(const short id) const {
    return (infrared_Default_id==id);
}

IMPLEMENT_META_EVENT_P(infrared, Default, Default, infrared())

//## event interruption()
interruption::interruption() {
    NOTIFY_EVENT_CONSTRUCTOR(interruption)
    setId(interruption_Default_id);
}

bool interruption::isTypeOf(const short id) const {
    return (interruption_Default_id==id);
}

IMPLEMENT_META_EVENT_P(interruption, Default, Default, interruption())

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Default.cpp
*********************************************************************/
