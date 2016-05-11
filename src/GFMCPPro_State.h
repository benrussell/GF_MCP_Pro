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
	GFDataref* _dref_leds_cmd_a;
	GFDataref* _dref_leds_cmd_b;
	GFDataref* _dref_leds_at_arm;
	// blank bit
	// blank bit
	GFDataref* _dref_leds_vor_loc;


	//LED mid row
	// blank bit
	GFDataref* _dref_leds_cws_a;
	GFDataref* _dref_leds_cws_b;
	// blank bit
	// blank bit
	// blank bit
	GFDataref* _dref_leds_fd_left;
	GFDataref* _dref_leds_n1;


	//LED bottom row
	GFDataref* _dref_leds_speed;
	GFDataref* _dref_leds_lvl_chg;
	GFDataref* _dref_leds_hdg_sel;
	GFDataref* _dref_leds_app;
	GFDataref* _dref_leds_alt_hld;
	GFDataref* _dref_leds_vs;
	// blank bit
	GFDataref* _dref_leds_fd_right;





private:

	static const char* label_override;
	static const char* label_light_test;

	// --------- 7 Seg ---------
	static const char* label_crs_left;
	static const char* label_ias_mach;
	static const char* label_heading;
	static const char* label_altitude;
	static const char* label_vert_speed;
	static const char* label_crs_right;

	// ------ Lights and buttons ---------
	//dataref names
	static const char* label_vnav;
	static const char* label_lnav;
	static const char* label_cmd_a;
	static const char* label_cmd_b;
	static const char* label_at_arm;
	static const char* label_vor_loc;

	static const char* label_cws_a;
	static const char* label_cws_b;
	static const char* label_fd_left;
	static const char* label_n1;

	static const char* label_speed;
	static const char* label_lvl_chg;
	static const char* label_hdg_sel;
	static const char* label_app;
	static const char* label_alt_hld;
	static const char* label_vs;
	static const char* label_fd_right;



};


#endif //GF_MCP_PRO_GFMCPPRO_STATE_H
