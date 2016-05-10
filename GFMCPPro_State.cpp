//
// Created by Ben on 10/05/2016.
//

#include "GFMCPPro_State.h"




GFMCPPro_State::GFMCPPro_State() {

	// Create datarefs..

	// Top Row
	_dref_leds_vnav         = new GFDataref( (char*)GFMCPPro_State::label_vnav  );
	_dref_leds_lnav         = new GFDataref( (char*)GFMCPPro_State::label_lnav );
	_dref_leds_ap_cmd_a     = new GFDataref( (char*)GFMCPPro_State::label_ap_cmd_a );
	_dref_leds_ap_cmd_b     = new GFDataref( (char*)GFMCPPro_State::label_ap_cmd_b );
	_dref_leds_at_arm       = new GFDataref( (char*)GFMCPPro_State::label_at_arm );
	// blank bit
	// blank bit
	_dref_leds_vor_loc      = new GFDataref( (char*)GFMCPPro_State::label_vor_loc );


	// Mid Row
	// blank bit
	_dref_leds_ap_a_cws     = new GFDataref( (char*)GFMCPPro_State::label_ap_a_cws  );
	_dref_leds_ap_b_cws     = new GFDataref( (char*)GFMCPPro_State::label_ap_b_cws );
	// blank bit
	// blank bit
	// blank bit
	_dref_leds_l_side_fd    = new GFDataref( (char*)GFMCPPro_State::label_l_side_fd );
	_dref_leds_n1           = new GFDataref( (char*)GFMCPPro_State::label_n1 );


	// Bottom Row
	_dref_leds_speed        = new GFDataref( (char*)GFMCPPro_State::label_speed  );
	_dref_leds_lvl_chg      = new GFDataref( (char*)GFMCPPro_State::label_lvl_chg );
	_dref_leds_hdg_sel      = new GFDataref( (char*)GFMCPPro_State::label_hdg_sel  );
	_dref_leds_app          = new GFDataref( (char*)GFMCPPro_State::label_app );
	_dref_leds_alt_hld      = new GFDataref( (char*)GFMCPPro_State::label_alt_hld  );
	_dref_leds_vs           = new GFDataref( (char*)GFMCPPro_State::label_vs );
	// blank bit
	_dref_leds_r_side_fd    = new GFDataref( (char*)GFMCPPro_State::label_r_side_fd  );

}
