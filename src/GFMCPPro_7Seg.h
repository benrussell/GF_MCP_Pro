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

	void _write_override_state();
	void _write_auto_state();
	void _write_light_test();


	// USB Endpoint Targets
    static const unsigned char _usb_report_crs_left;
    static const unsigned char _usb_report_ias;
    static const unsigned char _usb_report_hdg;
    static const unsigned char _usb_report_alt;
    static const unsigned char _usb_report_vs;
    static const unsigned char _usb_report_crs_right;


};


#endif //GF_MCP_PRO_GFMCPPRO_7SEG_H
