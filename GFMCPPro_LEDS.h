//
// Created by Ben on 6/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_LEDS_H
#define GF_MCP_PRO_GFMCPPRO_LEDS_H


#include <hidapi.h>

#include "GFDataref.h"


class GFMCPPro_LEDS {
public:
    GFMCPPro_LEDS();

    void update();


    hid_device* _handle;


    //LED top row
    GFDataref* _dref_leds_vnav;
    GFDataref* _dref_leds_lnav;
    GFDataref* _dref_leds_ap_cmd_a;
    GFDataref* _dref_leds_ap_cmd_b;
    GFDataref* _dref_leds_at_arm;
    // blank bit
    // blank bit
    GFDataref* _dref_leds_vor_loc;


    //LED mid row
    // blank bit
    GFDataref* _dref_leds_ap_a_cws;
    GFDataref* _dref_leds_ap_b_cws;
    // blank bit
    // blank bit
    // blank bit
    GFDataref* _dref_leds_l_side_fd;
    GFDataref* _dref_leds_n1;


    //LED bottom row
    GFDataref* _dref_leds_speed;
    GFDataref* _dref_leds_lvl_chg;
    GFDataref* _dref_leds_hdg_sel;
    GFDataref* _dref_leds_app;
    GFDataref* _dref_leds_alt_hld;
    GFDataref* _dref_leds_vs;
    // blank bit
    GFDataref* _dref_leds_r_side_fd;



private:
	//dataref names
	const char* label_vnav          = "goflight/mcp_pro/leds/vnav";
	const char* label_lnav          = "goflight/mcp_pro/leds/lnav";
	const char* label_ap_cmd_a      = "goflight/mcp_pro/leds/ap_cmd_a";
	const char* label_ap_cmd_b      = "goflight/mcp_pro/leds/ap_cmd_b";
	const char* label_at_arm        = "goflight/mcp_pro/leds/at_arm";
	const char* label_vor_loc       = "goflight/mcp_pro/leds/vor_loc";

	const char* label_ap_a_cws      = "goflight/mcp_pro/leds/ap_a_cws";
	const char* label_ap_b_cws      = "goflight/mcp_pro/leds/ap_b_cws";
	const char* label_l_side_fd     = "goflight/mcp_pro/leds/l_side_fd";
	const char* label_n1            = "goflight/mcp_pro/leds/n1";

	const char* label_speed         = "goflight/mcp_pro/leds/speed";
	const char* label_lvl_chg       = "goflight/mcp_pro/leds/lvl_chg";
	const char* label_hdg_sel       = "goflight/mcp_pro/leds/hdg_sel";
	const char* label_app           = "goflight/mcp_pro/leds/app";
	const char* label_alt_hld       = "goflight/mcp_pro/leds/alt_hld";
	const char* label_vs            = "goflight/mcp_pro/leds/vs";
	const char* label_r_side_fd     = "goflight/mcp_pro/leds/r_side_fd";



	//get blob for export to hware unit
	void _get_led_blob( unsigned char ret[3] );





};


#endif //GF_MCP_PRO_GFMCPPRO_LEDS_H
