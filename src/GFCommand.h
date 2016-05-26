//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_GFCommand_H
#define GF_MCP_PRO_GFCommand_H


#include <XPLMUtilities.h>

#include <string>



class GFCommand {
protected:
    int _cmd_active; //held high while the hardware button is down, returns to low when we get a release event from USB HID

	XPLMCommandRef _xpcmd;


public:
    GFCommand( const std::string cmd_name, const std::string cmd_description, void* _button_router );
	virtual ~GFCommand(){};

    std::string _name;

	int _is_multi_phase;

	//std::string _description;


    virtual void Begin();
    virtual void Stop();



	void* _button_router;

};





// track hardware switch states.

class GFCommand_Switch : public GFCommand {
private:
	//track the up/down state of the switch.
	int _switch_initialized;
	int _last_switch_state;

public:

	GFCommand_Switch( const std::string cmd_name, const std::string cmd_description, void* _button_router );

	virtual void Begin();
	virtual void Stop();
};





#endif //GF_MCP_PRO_GFCommand_H
