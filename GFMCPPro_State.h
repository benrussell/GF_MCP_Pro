//
// Created by Ben on 10/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_STATE_H
#define GF_MCP_PRO_GFMCPPRO_STATE_H


#include "GFDataref.h"


class GFMCPPro_State {
public:
	GFMCPPro_State();
	~GFMCPPro_State();



	GFDataref* _dref_mcp_override;
	GFDataref* _dref_mcp_light_test;



	// --------- 7 Seg displays ------------

	// 7 Seg byte arrays.
	GFDataref* _dref_crs_left;
	GFDataref* _dref_ias_mach;
	GFDataref* _dref_heading;
	GFDataref* _dref_altitude;
	GFDataref* _dref_vert_speed;
	GFDataref* _dref_crs_right;




	// -------- Lights and buttons ---------

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


	const char* label_override      = "goflight/mcp_pro/override";
	const char* label_light_test    = "goflight/mcp_pro/light_test";




	// --------- 7 Seg ---------

	const char* label_crs_left      = "goflight/mcp_pro/7seg/crs_left";
	const char* label_ias_mach      = "goflight/mcp_pro/7seg/ias_mach";
	const char* label_heading       = "goflight/mcp_pro/7seg/heading";
	const char* label_altitude      = "goflight/mcp_pro/7seg/altitude";
	const char* label_vert_speed    = "goflight/mcp_pro/7seg/vert_speed";
	const char* label_crs_right     = "goflight/mcp_pro/7seg/crs_right";





	// ------ Lights and buttons ---------

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





};


#endif //GF_MCP_PRO_GFMCPPRO_STATE_H
