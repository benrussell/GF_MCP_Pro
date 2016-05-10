//
// Created by Ben on 5/05/2016.
//

#include "GFCommand.h"

#include "XPLGlue.h"


GFCommand::GFCommand( char *cmd_name, char* cmd_description, void* button_router ) {

	char caTmp[1024];
	snprintf( caTmp, 1024, "GF_MCP_Pro: Create cmd:(%s)\n", cmd_name );
    XPLMDebugString( caTmp );

	_button_router = button_router;

    _name = std::string( cmd_name );
    _description = std::string( cmd_description );

    _cmd = XPLMCreateCommand( cmd_name, cmd_description );


    XPLMRegisterCommandHandler( _cmd,              // in Command name
                                GFMCPPro_cmdHandler,       // in Handler
                                1,                      // Receive input before plugin windows.
                                (void *)this
								);

}


void GFCommand::Begin() {
    XPLMCommandBegin( _cmd );
    _cmd_active = 1;
}


void GFCommand::Stop() {
    if( _cmd_active ) {
        XPLMCommandEnd(_cmd);
        _cmd_active = 0;
    }
}



// --- Action handlers ---


// what do we actually do when this item is running.
void GFCommand::_Action_Start(){
	XPLMDebugString("GFCommand: _Action_Start() default.\n");
}
void GFCommand::_Action_Hold(){
	XPLMDebugString("GFCommand: _Action_Hold() default.\n");
}
void GFCommand::_Action_Stop(){
	XPLMDebugString("GFCommand: _Action_Stop() default.\n");
}


// eof
