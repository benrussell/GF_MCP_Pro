//
// Created by Ben on 10/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_COMMANDS_H
#define GF_MCP_PRO_GFMCPPRO_COMMANDS_H


#include "GFCommand.h"


class GFMCPPro_Commands : public GFCommand {
	GFMCPPro_Commands( char* cmd_name, char* cmd_description );

	// what do we actually do when this item is running.
	virtual void _Action_Start();
	virtual void _Action_Hold();
	virtual void _Action_Stop();

};


#endif //GF_MCP_PRO_GFMCPPRO_COMMANDS_H
