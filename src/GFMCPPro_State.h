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


	GFDataref* _dref_connected;
	GFDataref* _dref_override;
	GFDataref* _dref_light_test;


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


	// action request flags... triggered by XPLMCommand requests.
	int _wants_connection;
	int _wants_disconnection;



private:
	// --- General State ---
	static const std::string _drname_connected;
	static const std::string _drname_override;
	static const std::string _drname_light_test;

	// --------- 7 Seg ---------
	static const std::string _drname_crs_left;
	static const std::string _drname_ias_mach;
	static const std::string _drname_heading;
	static const std::string _drname_altitude;
	static const std::string _drname_vert_speed;
	static const std::string _drname_crs_right;

	// ------ Lights and buttons ---------
	//dataref names
	static const std::string _drname_vnav;
	static const std::string _drname_lnav;
	static const std::string _drname_cmd_a;
	static const std::string _drname_cmd_b;
	static const std::string _drname_at_arm;
	static const std::string _drname_vor_loc;

	static const std::string _drname_cws_a;
	static const std::string _drname_cws_b;
	static const std::string _drname_fd_left;
	static const std::string _drname_n1;

	static const std::string _drname_speed;
	static const std::string _drname_lvl_chg;
	static const std::string _drname_hdg_sel;
	static const std::string _drname_app;
	static const std::string _drname_alt_hld;
	static const std::string _drname_vs;
	static const std::string _drname_fd_right;



};


#endif //GF_MCP_PRO_GFMCPPRO_STATE_H
