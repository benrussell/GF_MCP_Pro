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
