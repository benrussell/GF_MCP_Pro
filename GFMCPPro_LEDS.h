//
// Created by Ben on 6/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_LEDS_H
#define GF_MCP_PRO_GFMCPPRO_LEDS_H


#include <hidapi.h>



#include "GFMCPPro_State.h"



class GFMCPPro_LEDS {
public:
	GFMCPPro_LEDS( GFMCPPro_State* state );

	//called by parent.
    void write();

	//set by parent.
	GFMCPPro_State* _mcp_state;
    hid_device* _handle;

private:
	//get blob for export to hware unit
	void _get_led_blob( unsigned char ret[3] );


};


#endif //GF_MCP_PRO_GFMCPPRO_LEDS_H
