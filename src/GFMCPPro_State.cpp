//
// Created by Ben on 10/05/2016.
//

#include "GFMCPPro_State.h"




GFMCPPro_State::GFMCPPro_State() {

	// Create datarefs..

	// Control override.
	_dref_mcp_override     = new GFDataref( (char*)GFMCPPro_State::label_override  );

	// Light test
	_dref_mcp_light_test   = new GFDataref( (char*)GFMCPPro_State::label_light_test  );



	// ------- 7 Segs --------

	_dref_crs_left      = new GFDataref( (char*)GFMCPPro_State::label_crs_left,   3);
	_dref_ias_mach      = new GFDataref( (char*)GFMCPPro_State::label_ias_mach,   5);
	_dref_heading       = new GFDataref( (char*)GFMCPPro_State::label_heading,    3);
	_dref_altitude      = new GFDataref( (char*)GFMCPPro_State::label_altitude,   5);
	_dref_vert_speed    = new GFDataref( (char*)GFMCPPro_State::label_vert_speed, 5);
	_dref_crs_right     = new GFDataref( (char*)GFMCPPro_State::label_crs_right,  3);





	// ------- Lights and buttons --------

	// Top Row
	_dref_leds_vnav         = new GFDataref( (char*)GFMCPPro_State::label_vnav  );
	_dref_leds_lnav         = new GFDataref( (char*)GFMCPPro_State::label_lnav );
	_dref_leds_cmd_a     = new GFDataref( (char*)GFMCPPro_State::label_cmd_a );
	_dref_leds_cmd_b     = new GFDataref( (char*)GFMCPPro_State::label_cmd_b );
	_dref_leds_at_arm       = new GFDataref( (char*)GFMCPPro_State::label_at_arm );
	// blank bit
	// blank bit
	_dref_leds_vor_loc      = new GFDataref( (char*)GFMCPPro_State::label_vor_loc );


	// Mid Row
	// blank bit
	_dref_leds_cws_a     = new GFDataref( (char*)GFMCPPro_State::label_cws_a  );
	_dref_leds_cws_b     = new GFDataref( (char*)GFMCPPro_State::label_cws_b );
	// blank bit
	// blank bit
	// blank bit
	_dref_leds_fd_left    = new GFDataref( (char*)GFMCPPro_State::label_fd_left );
	_dref_leds_n1           = new GFDataref( (char*)GFMCPPro_State::label_n1 );


	// Bottom Row
	_dref_leds_speed        = new GFDataref( (char*)GFMCPPro_State::label_speed  );
	_dref_leds_lvl_chg      = new GFDataref( (char*)GFMCPPro_State::label_lvl_chg );
	_dref_leds_hdg_sel      = new GFDataref( (char*)GFMCPPro_State::label_hdg_sel  );
	_dref_leds_app          = new GFDataref( (char*)GFMCPPro_State::label_app );
	_dref_leds_alt_hld      = new GFDataref( (char*)GFMCPPro_State::label_alt_hld  );
	_dref_leds_vs           = new GFDataref( (char*)GFMCPPro_State::label_vs );
	// blank bit
	_dref_leds_fd_right    = new GFDataref( (char*)GFMCPPro_State::label_fd_right  );

}


GFMCPPro_State::~GFMCPPro_State() {

	// 7 seg cleanup
	delete(_dref_crs_left);
	delete(_dref_ias_mach);
	delete(_dref_heading);
	delete(_dref_altitude);
	delete(_dref_vert_speed);
	delete(_dref_crs_right);


	// buttons and lights cleanup
	//FIXME: no cleanup...


}



const char* GFMCPPro_State::label_override      = "goflight/mcp_pro/override";

const char* GFMCPPro_State::label_light_test    = "goflight/mcp_pro/light_test";


// --------- 7 Seg ---------
const char* GFMCPPro_State::label_crs_left      = "goflight/mcp_pro/7seg/crs_left";
const char* GFMCPPro_State::label_ias_mach      = "goflight/mcp_pro/7seg/ias_mach";
const char* GFMCPPro_State::label_heading       = "goflight/mcp_pro/7seg/heading";
const char* GFMCPPro_State::label_altitude      = "goflight/mcp_pro/7seg/altitude";
const char* GFMCPPro_State::label_vert_speed    = "goflight/mcp_pro/7seg/vert_speed";
const char* GFMCPPro_State::label_crs_right     = "goflight/mcp_pro/7seg/crs_right";


// ------ Lights and buttons ---------
//dataref names
const char* GFMCPPro_State::label_vnav          = "goflight/mcp_pro/leds/vnav";
const char* GFMCPPro_State::label_lnav          = "goflight/mcp_pro/leds/lnav";
const char* GFMCPPro_State::label_cmd_a      = "goflight/mcp_pro/leds/cmd_a";
const char* GFMCPPro_State::label_cmd_b      = "goflight/mcp_pro/leds/cmd_b";
const char* GFMCPPro_State::label_at_arm        = "goflight/mcp_pro/leds/at_arm";
const char* GFMCPPro_State::label_vor_loc       = "goflight/mcp_pro/leds/vor_loc";

const char* GFMCPPro_State::label_cws_a      = "goflight/mcp_pro/leds/cws_a";
const char* GFMCPPro_State::label_cws_b      = "goflight/mcp_pro/leds/cws_b";
const char* GFMCPPro_State::label_fd_left     = "goflight/mcp_pro/leds/fd_left";
const char* GFMCPPro_State::label_n1            = "goflight/mcp_pro/leds/n1";

const char* GFMCPPro_State::label_speed         = "goflight/mcp_pro/leds/speed";
const char* GFMCPPro_State::label_lvl_chg       = "goflight/mcp_pro/leds/lvl_chg";
const char* GFMCPPro_State::label_hdg_sel       = "goflight/mcp_pro/leds/hdg_sel";
const char* GFMCPPro_State::label_app           = "goflight/mcp_pro/leds/app";
const char* GFMCPPro_State::label_alt_hld       = "goflight/mcp_pro/leds/alt_hld";
const char* GFMCPPro_State::label_vs            = "goflight/mcp_pro/leds/vs";
const char* GFMCPPro_State::label_fd_right     = "goflight/mcp_pro/leds/fd_right";






//eof
