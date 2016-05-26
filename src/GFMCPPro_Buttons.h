//
// Created by Ben on 6/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_BUTTONS_H
#define GF_MCP_PRO_GFMCPPRO_BUTTONS_H


#include <hidapi.h>

#include "GFCommand.h"

#include "GFMCPPro_State.h"

#include <map>


//action function to call when we detect and parse a button event
typedef int (*GF_action_func)( GFMCPPro_State* ) ;



class GFMCPPro_Buttons {
public:
    GFMCPPro_Buttons( GFMCPPro_State* state );
	~GFMCPPro_Buttons();


	//read usb report and decode into various action
	void read( hid_device* handle );


	//consume and act on sim-command actions in an MCP specific manner.
	int  xp_cmd_action_handler(
			XPLMCommandPhase     inPhase,
			GFCommand*               inCmd);


	std::map<GFCommand*, GF_action_func> _action_map;



private:
	//needed to route into button press handler code.
	GFMCPPro_State* _mcp_state;


	void _read_usb( hid_device* handle );

	void _proc_hid_packet( unsigned char* buf );
	void _proc_buttons( unsigned char* buf );
	void _proc_knobs( unsigned char* buf );

	int _is_knob_bitflag_activity( unsigned char bit_flags );

	int _is_knob_left( unsigned char bit_flags );
	int _is_knob_right( unsigned char bit_flags );


    void _dump_button_packet( int res, unsigned char* buf );




	GFCommand* _btn_Connect;
	GFCommand* _btn_Disconnect;

	GFCommand* _btn_LightTest;



	// ---- Buttons and Switches ----
	// USB Report Packet 5
	GFCommand* _btn_Speed;
	GFCommand* _btn_LVL_CHG;
	GFCommand* _btn_HDG_SEL;
	GFCommand* _btn_APP;
	GFCommand* _btn_ALT_HLD;
	GFCommand* _btn_VS;
	GFCommand* _btn_AP_Disengage;
	GFCommand_Switch* _btn_FD_Right;

	// USB Report Packet 6
	GFCommand* _btn_ALT_INV;
	GFCommand* _btn_CWS_A;
	GFCommand* _btn_CWS_B;
	GFCommand_Switch* _btn_FD_Left;
	GFCommand* _btn_N1;

	// USB Report Packet 7
	GFCommand* _btn_VNAV;
	GFCommand* _btn_LNAV;
	GFCommand* _btn_CMD_A;
	GFCommand* _btn_CMD_B;
	GFCommand_Switch* _btn_AT_Arm;
	GFCommand* _btn_CO;
	GFCommand* _btn_SPD_INTV;
	GFCommand* _btn_VOR_LOC;




	// ---- Scroll Wheels and Rotaries ----
	// These are spread over multiple bytes.
	GFCommand* _btn_crs_left_inc;
	GFCommand* _btn_crs_left_dec;

	GFCommand* _btn_ias_mach_inc;
	GFCommand* _btn_ias_mach_dec;

	GFCommand* _btn_heading_inc;
	GFCommand* _btn_heading_dec;

	GFCommand* _btn_altitude_inc;
	GFCommand* _btn_altitude_dec;

	GFCommand* _btn_vert_speed_inc;
	GFCommand* _btn_vert_speed_dec;

	GFCommand* _btn_crs_right_inc;
	GFCommand* _btn_crs_right_dec;
	// -----------------------------------




	static const std::string  _label_no_description;


	static const std::string _cmd_name_device_connect;
	static int _action_btn_connect( GFMCPPro_State* );

	static const std::string _cmd_name_device_disconnect;
	static int _action_btn_disconnect( GFMCPPro_State* );


	static const std::string _cmd_name_device_light_test;
	static int _action_btn_light_test( GFMCPPro_State* );




	static const std::string _cmd_name_btn_speed;
	static int _action_btn_speed( GFMCPPro_State* );

	static const std::string _cmd_name_btn_lvl_chg;
	static int _action_btn_lvl_chg( GFMCPPro_State* );

	static const std::string _cmd_name_btn_hdg_sel;
	static int _action_btn_hdg_sel( GFMCPPro_State* );

	static const std::string _cmd_name_btn_app;
	static int _action_btn_app( GFMCPPro_State* );

	static const std::string _cmd_name_btn_alt_hld;
	static int _action_btn_alt_hld( GFMCPPro_State* );

	static const std::string _cmd_name_btn_vs;
	static int _action_btn_vs( GFMCPPro_State* );

	static const std::string _cmd_name_btn_ap_disengage;
	static int _action_btn_ap_disengage( GFMCPPro_State* );

	static const std::string _cmd_name_btn_fd_right;
	static int _action_btn_fd_right( GFMCPPro_State* );

	static const std::string _cmd_name_btn_alt_inv;
	static int _action_btn_alt_inv( GFMCPPro_State* );

	static const std::string _cmd_name_btn_cws_a;
	static int _action_btn_cws_a( GFMCPPro_State* );

	static const std::string _cmd_name_btn_cws_b;
	static int _action_btn_cws_b( GFMCPPro_State* );

	static const std::string _cmd_name_btn_fd_left;
	static int _action_btn_fd_left( GFMCPPro_State* );

	static const std::string _cmd_name_btn_n1;
	static int _action_btn_n1( GFMCPPro_State* );

	static const std::string _cmd_name_btn_vnav;
	static int _action_btn_vnav( GFMCPPro_State* );

	static const std::string _cmd_name_btn_lnav;
	static int _action_btn_lnav( GFMCPPro_State* );

	static const std::string _cmd_name_btn_cmd_a;
	static int _action_btn_cmd_a( GFMCPPro_State* );

	static const std::string _cmd_name_btn_cmd_b;
	static int _action_btn_cmd_b( GFMCPPro_State* );

	static const std::string _cmd_name_btn_at_arm;
	static int _action_btn_at_arm( GFMCPPro_State* );

	static const std::string _cmd_name_btn_co;
	static int _action_btn_co( GFMCPPro_State* );

	static const std::string _cmd_name_btn_spd_intv;
	static int _action_btn_spd_intv( GFMCPPro_State* );

	static const std::string _cmd_name_btn_vor_loc;
	static int _action_btn_vor_loc( GFMCPPro_State* );



	// Dials and knobs..
	static const std::string _cmd_name_crs_left_inc;
    static const std::string _cmd_name_crs_left_dec;
	static int _action_crs_left_dec( GFMCPPro_State* );
	static int _action_crs_left_inc( GFMCPPro_State* );

    static const std::string _cmd_name_ias_mach_inc;
    static const std::string _cmd_name_ias_mach_dec;
	static int _action_ias_mach_dec( GFMCPPro_State* );
	static int _action_ias_mach_inc( GFMCPPro_State* );

    static const std::string _cmd_name_heading_inc;
	static const std::string _cmd_name_heading_dec;
	static int _action_heading_dec( GFMCPPro_State* );
	static int _action_heading_inc( GFMCPPro_State* );

    static const std::string _cmd_name_altitude_inc;
	static const std::string _cmd_name_altitude_dec;
	static int _action_altitude_dec( GFMCPPro_State* );
	static int _action_altitude_inc( GFMCPPro_State* );

    static const std::string _cmd_name_vert_speed_inc;
    static const std::string _cmd_name_vert_speed_dec;
	static int _action_vert_speed_dec( GFMCPPro_State* );
	static int _action_vert_speed_inc( GFMCPPro_State* );

    static const std::string _cmd_name_crs_right_inc;
    static const std::string _cmd_name_crs_right_dec;
	static int _action_crs_right_dec( GFMCPPro_State* );
	static int _action_crs_right_inc( GFMCPPro_State* );



};


#endif //GF_MCP_PRO_GFMCPPRO_BUTTONS_H
