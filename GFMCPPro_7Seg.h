//
// Created by Ben on 6/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_7SEG_H
#define GF_MCP_PRO_GFMCPPRO_7SEG_H


#include <hidapi.h>


#include "GFDataref.h"

#include "GFUtils.h"

#include "GFMCPPro_State.h"


class GFMCPPro_7Seg {
public:

	//called by parent.
    void update();

	//set by parent.
	GFMCPPro_State* _mcp_state;
    hid_device* _handle;


private:

    // USB Endpoint Targets
    const unsigned char target_crs_left   = 3;
    const unsigned char target_ias        = 5;
    const unsigned char target_hdg        = 7;
    const unsigned char target_alt        = 9;
    const unsigned char target_vs         = 11;
    const unsigned char target_crs_right  = 13;


};


#endif //GF_MCP_PRO_GFMCPPRO_7SEG_H
