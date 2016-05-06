//
// Created by Ben on 5/05/2016.
//

#include "GFCommand.h"

#include "XPLGlue.h"


GFCommand::GFCommand() {
    XPLMDebugString("GF_MCP_Pro: Create command.. default\n");
}

GFCommand::GFCommand(char *cmd_name, char* cmd_description) {

    XPLMDebugString("GF_MCP_Pro: Create command..\n");

    _name = std::string( cmd_name );
    _description = std::string( cmd_description );

    _cmd = XPLMCreateCommand( cmd_name, cmd_description );


    XPLMRegisterCommandHandler( _cmd,              // in Command name
                                GFMCPPro_cmdHandler,       // in Handler
                                1,                      // Receive input before plugin windows.
                                (void *)this);

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