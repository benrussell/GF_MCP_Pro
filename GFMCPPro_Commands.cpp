//
// Created by Ben on 10/05/2016.
//

#include "GFMCPPro_Commands.h"



GFMCPPro_Commands::GFMCPPro_Commands(char *cmd_name, char* cmd_description)
		: GFCommand( cmd_name, cmd_description )
{

	XPLMDebugString("GFMCPPro_Commands: Initializer ran.\n");

}



// what do we actually do when this item is running.
void GFMCPPro_Commands::_Action_Start(){
	XPLMDebugString("GFMCPPro_Commands: _Action_Start() default.\n");
}
void GFMCPPro_Commands::_Action_Hold(){
	XPLMDebugString("GFMCPPro_Commands: _Action_Hold() default.\n");
}
void GFMCPPro_Commands::_Action_Stop(){
	XPLMDebugString("GFMCPPro_Commands: _Action_Stop() default.\n");
}
