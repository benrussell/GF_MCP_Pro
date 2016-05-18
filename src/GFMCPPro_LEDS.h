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
    void write( hid_device* handle );


private:
	//get blob for export to hware unit
	void _get_led_blob( unsigned char ret[3] );

	GFMCPPro_State* _mcp_state;


};


#endif //GF_MCP_PRO_GFMCPPRO_LEDS_H
