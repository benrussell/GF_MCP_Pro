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
	GFMCPPro_7Seg( GFMCPPro_State* state );

	//called by parent.
    void write();

	//set by parent.
	hid_device* _handle;


private:

	GFMCPPro_State* _mcp_state;


	// USB Endpoint Targets
    const unsigned char _usb_report_crs_left   = 3;
    const unsigned char _usb_report_ias        = 5;
    const unsigned char _usb_report_hdg        = 7;
    const unsigned char _usb_report_alt        = 9;
    const unsigned char _usb_report_vs         = 11;
    const unsigned char _usb_report_crs_right  = 13;


};


#endif //GF_MCP_PRO_GFMCPPRO_7SEG_H
