//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_XPCOMMAND_H
#define GF_MCP_PRO_XPCOMMAND_H



#include <XPLMUtilities.h>

#include "XPCommand.h"


#include <string>



class XPCommand {
private:
    XPLMCommandRef _cmd;


public:
    XPCommand();
    XPCommand( char* cmd_name, char* cmd_description );

    std::string _name;
    std::string _description;


};


#endif //GF_MCP_PRO_XPCOMMAND_H
