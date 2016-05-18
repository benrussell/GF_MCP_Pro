//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_GFCommand_H
#define GF_MCP_PRO_GFCommand_H


#include <XPLMUtilities.h>

#include <string>



class GFCommand {
private:
    int _cmd_active; //held high while the hardware button is down, returns to low when we get a release event from USB HID

	XPLMCommandRef _xpcmd;


public:
    GFCommand( const std::string cmd_name, const std::string cmd_description, void* _button_router );

    std::string _name;


	//std::string _description;


    void Begin();
    void Stop();



	void* _button_router;

};


#endif //GF_MCP_PRO_GFCommand_H
