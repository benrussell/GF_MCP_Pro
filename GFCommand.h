//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_GFCommand_H
#define GF_MCP_PRO_GFCommand_H


#include <XPLMUtilities.h>

#include <string>



class GFCommand {
private:
    XPLMCommandRef _cmd;
    int _cmd_active; //held high

public:
    GFCommand();
    GFCommand( char* cmd_name, char* cmd_description );

    std::string _name;
    std::string _description;


    void Begin();
    void Stop();


};


#endif //GF_MCP_PRO_GFCommand_H
