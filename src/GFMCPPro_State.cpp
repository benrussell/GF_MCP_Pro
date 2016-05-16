//
// Created by Ben on 10/05/2016.
//

#include "GFMCPPro_State.h"




GFMCPPro_State::GFMCPPro_State() {

	// Create datarefs..

	// Control override.
	_dref_mcp_override     = new GFDataref( (char*)GFMCPPro_State::_label_override.c_str()  );

	// Light test
	_dref_mcp_light_test   = new GFDataref( (char*)GFMCPPro_State::_label_light_test.c_str()  );


	// ------- 7 Segs --------
	_dref_crs_left      = new GFDataref( (char*)GFMCPPro_State::_label_crs_left.c_str(),   3);
	_dref_ias_mach      = new GFDataref( (char*)GFMCPPro_State::_label_ias_mach.c_str(),   5);
	_dref_heading       = new GFDataref( (char*)GFMCPPro_State::_label_heading.c_str(),    3);
	_dref_altitude      = new GFDataref( (char*)GFMCPPro_State::_label_altitude.c_str(),   5);
	_dref_vert_speed    = new GFDataref( (char*)GFMCPPro_State::_label_vert_speed.c_str(), 5);
	_dref_crs_right     = new GFDataref( (char*)GFMCPPro_State::_label_crs_right.c_str(),  3);
	//FIXME: more drefs for indi state.



	// ------- Lights and buttons --------
	// Top Row
	_dref_leds_vnav         = new GFDataref( (char*)GFMCPPro_State::_label_vnav.c_str()  );
	_dref_leds_lnav         = new GFDataref( (char*)GFMCPPro_State::_label_lnav.c_str() );
	_dref_leds_cmd_a     = new GFDataref( (char*)GFMCPPro_State::_label_cmd_a.c_str() );
	_dref_leds_cmd_b     = new GFDataref( (char*)GFMCPPro_State::_label_cmd_b.c_str() );
	_dref_leds_at_arm       = new GFDataref( (char*)GFMCPPro_State::_label_at_arm.c_str() );
	// blank bit
	// blank bit
	_dref_leds_vor_loc      = new GFDataref( (char*)GFMCPPro_State::_label_vor_loc.c_str() );


	// Mid Row
	// blank bit
	_dref_leds_cws_a     = new GFDataref( (char*)GFMCPPro_State::_label_cws_a.c_str()  );
	_dref_leds_cws_b     = new GFDataref( (char*)GFMCPPro_State::_label_cws_b.c_str() );
	// blank bit
	// blank bit
	// blank bit
	_dref_leds_fd_left    = new GFDataref( (char*)GFMCPPro_State::_label_fd_left.c_str() );
	_dref_leds_n1           = new GFDataref( (char*)GFMCPPro_State::_label_n1.c_str() );


	// Bottom Row
	_dref_leds_speed        = new GFDataref( (char*)GFMCPPro_State::_label_speed.c_str()  );
	_dref_leds_lvl_chg      = new GFDataref( (char*)GFMCPPro_State::_label_lvl_chg.c_str() );
	_dref_leds_hdg_sel      = new GFDataref( (char*)GFMCPPro_State::_label_hdg_sel.c_str()  );
	_dref_leds_app          = new GFDataref( (char*)GFMCPPro_State::_label_app.c_str() );
	_dref_leds_alt_hld      = new GFDataref( (char*)GFMCPPro_State::_label_alt_hld.c_str()  );
	_dref_leds_vs           = new GFDataref( (char*)GFMCPPro_State::_label_vs.c_str() );
	// blank bit
	_dref_leds_fd_right    = new GFDataref( (char*)GFMCPPro_State::_label_fd_right.c_str()  );

}


GFMCPPro_State::~GFMCPPro_State() {


	// Control override.
	delete(_dref_mcp_override);

	// Light test
	delete(_dref_mcp_light_test);

	// 7 seg cleanup
	delete(_dref_crs_left);
	delete(_dref_ias_mach);
	delete(_dref_heading);
	delete(_dref_altitude);
	delete(_dref_vert_speed);
	delete(_dref_crs_right);



	// buttons and lights cleanup
	// Top Row
	delete(_dref_leds_vnav);
	delete(_dref_leds_lnav);
	delete(_dref_leds_cmd_a);
	delete(_dref_leds_cmd_b);
	delete(_dref_leds_at_arm);
	// blank bit
	// blank bit
	delete(_dref_leds_vor_loc);


	// Mid Row
	// blank bit
	delete(_dref_leds_cws_a);
	delete(_dref_leds_cws_b);
	// blank bit
	// blank bit
	// blank bit
	delete(_dref_leds_fd_left);
	delete(_dref_leds_n1);


	// Bottom Row
	delete(_dref_leds_speed);
	delete(_dref_leds_lvl_chg);
	delete(_dref_leds_hdg_sel);
	delete(_dref_leds_app);
	delete(_dref_leds_alt_hld);
	delete(_dref_leds_vs);
	// blank bit
	delete(_dref_leds_fd_right);
	
	
}



const std::string GFMCPPro_State::_label_override      = "goflight/mcp_pro/override";

const std::string GFMCPPro_State::_label_light_test    = "goflight/mcp_pro/light_test";


// --------- 7 Seg ---------
const std::string GFMCPPro_State::_label_crs_left      = "goflight/mcp_pro/7seg/crs_left";
const std::string GFMCPPro_State::_label_ias_mach      = "goflight/mcp_pro/7seg/ias_mach";
const std::string GFMCPPro_State::_label_heading       = "goflight/mcp_pro/7seg/heading";
const std::string GFMCPPro_State::_label_altitude      = "goflight/mcp_pro/7seg/altitude";
const std::string GFMCPPro_State::_label_vert_speed    = "goflight/mcp_pro/7seg/vert_speed";
const std::string GFMCPPro_State::_label_crs_right     = "goflight/mcp_pro/7seg/crs_right";


// ------ Lights and buttons ---------
//dataref names
const std::string GFMCPPro_State::_label_vnav          = "goflight/mcp_pro/leds/vnav";
const std::string GFMCPPro_State::_label_lnav          = "goflight/mcp_pro/leds/lnav";
const std::string GFMCPPro_State::_label_cmd_a      = "goflight/mcp_pro/leds/cmd_a";
const std::string GFMCPPro_State::_label_cmd_b      = "goflight/mcp_pro/leds/cmd_b";
const std::string GFMCPPro_State::_label_at_arm        = "goflight/mcp_pro/leds/at_arm";
const std::string GFMCPPro_State::_label_vor_loc       = "goflight/mcp_pro/leds/vor_loc";

const std::string GFMCPPro_State::_label_cws_a      = "goflight/mcp_pro/leds/cws_a";
const std::string GFMCPPro_State::_label_cws_b      = "goflight/mcp_pro/leds/cws_b";
const std::string GFMCPPro_State::_label_fd_left     = "goflight/mcp_pro/leds/fd_left";
const std::string GFMCPPro_State::_label_n1            = "goflight/mcp_pro/leds/n1";

const std::string GFMCPPro_State::_label_speed         = "goflight/mcp_pro/leds/speed";
const std::string GFMCPPro_State::_label_lvl_chg       = "goflight/mcp_pro/leds/lvl_chg";
const std::string GFMCPPro_State::_label_hdg_sel       = "goflight/mcp_pro/leds/hdg_sel";
const std::string GFMCPPro_State::_label_app           = "goflight/mcp_pro/leds/app";
const std::string GFMCPPro_State::_label_alt_hld       = "goflight/mcp_pro/leds/alt_hld";
const std::string GFMCPPro_State::_label_vs            = "goflight/mcp_pro/leds/vs";
const std::string GFMCPPro_State::_label_fd_right     = "goflight/mcp_pro/leds/fd_right";


//eof
