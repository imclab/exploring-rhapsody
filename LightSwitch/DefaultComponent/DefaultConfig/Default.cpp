/********************************************************************
	Rhapsody	: 8.0 
	Login		: bxt5647
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Default
//!	Generated Date	: Wed, 1, May 2013  
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
#define Default_display_menu_SERIALIZE OM_NO_OP

#define Default_display_status_SERIALIZE OM_NO_OP

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

//## operation display_menu()
void display_menu() {
    NOTIFY_FUNCTION(Default, display_menu, display_menu(), 0, Default_display_menu_SERIALIZE);
    //#[ operation display_menu()
    std::cout << "Actions:\n";
    std::cout << "* toggle - flip switch\n";
    std::cout << "* status - show light status/state\n";
    //#]
}

//## operation display_status()
void display_status() {
    NOTIFY_FUNCTION(Default, display_status, display_status(), 0, Default_display_status_SERIALIZE);
    //#[ operation display_status()
    bool on = Light.IS_IN(ON);
    
    std::cout << "Lightbulb: (" << (on ? "*" : "O") << ")\n";
    //#]
}

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
