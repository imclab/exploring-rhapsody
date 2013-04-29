/********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Default
//!	Generated Date	: Mon, 22, Apr 2013  
	File Path	: DefaultComponent\DefaultConfig\Default.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Default.h"
//## classInstance Light
#include "Light.h"
//## classInstance Switch
#include "Switch.h"
//#[ ignore
#define toggle_SERIALIZE OM_NO_OP

#define toggle_UNSERIALIZE OM_NO_OP

#define toggle_CONSTRUCTOR toggle()
//#]

//## package Default


//## classInstance Light
Light_C Light;

//## classInstance Switch
Switch_C Switch;

#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */);

static void RenameGlobalInstances();

IMPLEMENT_META_PACKAGE(Default, Default)
#endif // _OMINSTRUMENT

void Default_initRelations() {
    {
        {
            Light.setShouldDelete(false);
        }
        {
            Switch.setShouldDelete(false);
        }
    }
    
    #ifdef _OMINSTRUMENT
    RenameGlobalInstances();
    #endif // _OMINSTRUMENT
}

bool Default_startBehavior() {
    bool done = true;
    done &= Light.startBehavior();
    done &= Switch.startBehavior();
    return done;
}

#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */) {
}

static void RenameGlobalInstances() {
    OM_SET_INSTANCE_NAME(&Light, Light, "Light", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&Switch, Switch, "Switch", AOMNoMultiplicity);
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

//## event toggle()
toggle::toggle() {
    NOTIFY_EVENT_CONSTRUCTOR(toggle)
    setId(toggle_Default_id);
}

bool toggle::isTypeOf(const short id) const {
    return (toggle_Default_id==id);
}

IMPLEMENT_META_EVENT_P(toggle, Default, Default, toggle())

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Default.cpp
*********************************************************************/
