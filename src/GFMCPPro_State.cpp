//
// Created by Ben on 10/05/2016.
//

#include "GFMCPPro_State.h"




GFMCPPro_State::GFMCPPro_State() {

	// request flags..
	_wants_connection = 0;
	_wants_disconnection = 0;


	// Create datarefs..

	// Connect state
	_dref_connected     = new GFDataref( GFMCPPro_State::_drname_connected );

	// Control override.
	_dref_override     	= new GFDataref( GFMCPPro_State::_drname_override );
	_dref_override_7seg     	= new GFDataref( GFMCPPro_State::_drname_override_7seg );

	// Light test
	_dref_light_test   	= new GFDataref( GFMCPPro_State::_drname_light_test );


	// ------- 7 Segs --------
	_dref_7seg_crs_left      = new GFDataref( GFMCPPro_State::_drname_7seg_crs_left,   3);
	_dref_7seg_ias_mach      = new GFDataref( GFMCPPro_State::_drname_7seg_ias_mach,   5);
	_dref_7seg_heading       = new GFDataref( GFMCPPro_State::_drname_7seg_heading,    3);
	_dref_7seg_altitude      = new GFDataref( GFMCPPro_State::_drname_7seg_altitude,   5);
	_dref_7seg_vert_speed    = new GFDataref( GFMCPPro_State::_drname_7seg_vert_speed, 5);
	_dref_7seg_crs_right     = new GFDataref( GFMCPPro_State::_drname_7seg_crs_right,  3);


	// --------- 7 Seg Managed ---------
	// drefs track the values managed by this plugin for the heading/crs/etc. as ints instead of byte arrays.
	_dref_managed_crs_left      = new GFDataref( GFMCPPro_State::_drname_managed_crs_left );
	_dref_managed_ias_mach      = new GFDataref( GFMCPPro_State::_drname_managed_ias_mach );
	_dref_managed_heading       = new GFDataref( GFMCPPro_State::_drname_managed_heading );
	_dref_managed_altitude      = new GFDataref( GFMCPPro_State::_drname_managed_altitude );
	_dref_managed_vert_speed    = new GFDataref( GFMCPPro_State::_drname_managed_vert_speed );
	_dref_managed_crs_right     = new GFDataref( GFMCPPro_State::_drname_managed_crs_right );


	// ------- Lights and buttons --------
	// Top Row
	_dref_leds_vnav         = new GFDataref( GFMCPPro_State::_drname_vnav  );
	_dref_leds_lnav         = new GFDataref( GFMCPPro_State::_drname_lnav );
	_dref_leds_cmd_a     	= new GFDataref( GFMCPPro_State::_drname_cmd_a );
	_dref_leds_cmd_b     	= new GFDataref( GFMCPPro_State::_drname_cmd_b );
	_dref_leds_at_arm       = new GFDataref( GFMCPPro_State::_drname_at_arm );
	// blank bit
	// blank bit
	_dref_leds_vor_loc      = new GFDataref( GFMCPPro_State::_drname_vor_loc );


	// Mid Row
	// blank bit
	_dref_leds_cws_a     	= new GFDataref( GFMCPPro_State::_drname_cws_a  );
	_dref_leds_cws_b     	= new GFDataref( GFMCPPro_State::_drname_cws_b );
	// blank bit
	// blank bit
	// blank bit
	_dref_leds_fd_left    	= new GFDataref( GFMCPPro_State::_drname_fd_left );
	_dref_leds_n1           = new GFDataref( GFMCPPro_State::_drname_n1 );


	// Bottom Row
	_dref_leds_speed        = new GFDataref( GFMCPPro_State::_drname_speed  );
	_dref_leds_lvl_chg      = new GFDataref( GFMCPPro_State::_drname_lvl_chg );
	_dref_leds_hdg_sel      = new GFDataref( GFMCPPro_State::_drname_hdg_sel  );
	_dref_leds_app          = new GFDataref( GFMCPPro_State::_drname_app );
	_dref_leds_alt_hld      = new GFDataref( GFMCPPro_State::_drname_alt_hld  );
	_dref_leds_vs           = new GFDataref( GFMCPPro_State::_drname_vs );
	// blank bit
	_dref_leds_fd_right    = new GFDataref( GFMCPPro_State::_drname_fd_right  );

}


GFMCPPro_State::~GFMCPPro_State() {

	// Connection state.
	delete(_dref_connected);

	// Control override.
	delete(_dref_override);

	// Light test
	delete(_dref_light_test);

	// 7 seg cleanup
	delete(_dref_7seg_crs_left);
	delete(_dref_7seg_ias_mach);
	delete(_dref_7seg_heading);
	delete(_dref_7seg_altitude);
	delete(_dref_7seg_vert_speed);
	delete(_dref_7seg_crs_right);



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



const std::string GFMCPPro_State::_drname_connected     = "goflight/mcp_pro/connected";

const std::string GFMCPPro_State::_drname_override      = "goflight/mcp_pro/override";
const std::string GFMCPPro_State::_drname_override_7seg      = "goflight/mcp_pro/override_7seg";
const std::string GFMCPPro_State::_drname_light_test    = "goflight/mcp_pro/light_test";


// --------- 7 Seg ---------
const std::string GFMCPPro_State::_drname_7seg_crs_left      = "goflight/mcp_pro/7seg/crs_left";
const std::string GFMCPPro_State::_drname_7seg_ias_mach      = "goflight/mcp_pro/7seg/ias_mach";
const std::string GFMCPPro_State::_drname_7seg_heading       = "goflight/mcp_pro/7seg/heading";
const std::string GFMCPPro_State::_drname_7seg_altitude      = "goflight/mcp_pro/7seg/altitude";
const std::string GFMCPPro_State::_drname_7seg_vert_speed    = "goflight/mcp_pro/7seg/vert_speed";
const std::string GFMCPPro_State::_drname_7seg_crs_right     = "goflight/mcp_pro/7seg/crs_right";


// --------- 7 Seg Managed ---------
const std::string GFMCPPro_State::_drname_managed_crs_left      = "goflight/mcp_pro/crs_left";
const std::string GFMCPPro_State::_drname_managed_ias_mach      = "goflight/mcp_pro/ias_mach";
const std::string GFMCPPro_State::_drname_managed_heading       = "goflight/mcp_pro/heading";
const std::string GFMCPPro_State::_drname_managed_altitude      = "goflight/mcp_pro/altitude";
const std::string GFMCPPro_State::_drname_managed_vert_speed    = "goflight/mcp_pro/vert_speed";
const std::string GFMCPPro_State::_drname_managed_crs_right     = "goflight/mcp_pro/crs_right";




// ------ Lights and buttons ---------
//dataref names
const std::string GFMCPPro_State::_drname_vnav          = "goflight/mcp_pro/leds/vnav";
const std::string GFMCPPro_State::_drname_lnav          = "goflight/mcp_pro/leds/lnav";
const std::string GFMCPPro_State::_drname_cmd_a      	= "goflight/mcp_pro/leds/cmd_a";
const std::string GFMCPPro_State::_drname_cmd_b      	= "goflight/mcp_pro/leds/cmd_b";
const std::string GFMCPPro_State::_drname_at_arm        = "goflight/mcp_pro/leds/at_arm";
const std::string GFMCPPro_State::_drname_vor_loc       = "goflight/mcp_pro/leds/vor_loc";

const std::string GFMCPPro_State::_drname_cws_a      	= "goflight/mcp_pro/leds/cws_a";
const std::string GFMCPPro_State::_drname_cws_b      	= "goflight/mcp_pro/leds/cws_b";
const std::string GFMCPPro_State::_drname_fd_left     	= "goflight/mcp_pro/leds/fd_left";
const std::string GFMCPPro_State::_drname_n1            = "goflight/mcp_pro/leds/n1";

const std::string GFMCPPro_State::_drname_speed         = "goflight/mcp_pro/leds/speed";
const std::string GFMCPPro_State::_drname_lvl_chg       = "goflight/mcp_pro/leds/lvl_chg";
const std::string GFMCPPro_State::_drname_hdg_sel       = "goflight/mcp_pro/leds/hdg_sel";
const std::string GFMCPPro_State::_drname_app           = "goflight/mcp_pro/leds/app";
const std::string GFMCPPro_State::_drname_alt_hld       = "goflight/mcp_pro/leds/alt_hld";
const std::string GFMCPPro_State::_drname_vs            = "goflight/mcp_pro/leds/vs";
const std::string GFMCPPro_State::_drname_fd_right     	= "goflight/mcp_pro/leds/fd_right";


//eof
