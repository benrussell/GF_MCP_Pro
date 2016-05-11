//
// Created by Ben on 6/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_BUTTONS_H
#define GF_MCP_PRO_GFMCPPRO_BUTTONS_H


#include <hidapi.h>

#include "GFCommand.h"

#include "GFMCPPro_State.h"

#include <map>



typedef int (*GF_action_func)( GFMCPPro_State* ) ;



class GFMCPPro_Buttons {
public:
    GFMCPPro_Buttons( GFMCPPro_State* state );
	~GFMCPPro_Buttons();


	//read usb report and decode into various action
	void read();

	//need USB handle for read ops
	hid_device* _handle;


	//consume and act on sim-command actions in an MCP specific manner.
	int  xp_cmd_action_handler(
			XPLMCommandRef        inCommand,
			XPLMCommandPhase     inPhase,
			GFCommand*               cmd);


	std::map<std::string, GF_action_func> _action_map;




private:

	//needed to route into button press handler code.
	GFMCPPro_State* _mcp_state;



	void _read_usb();

    void _proc_buttons( int res, unsigned char* buf );

    void _dump_button_packet( int res, unsigned char* buf );



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




	// ---- Buttons and Switches ----
	// USB Report Packet 5
	GFCommand* _btn_Speed;
	GFCommand* _btn_LVL_CHG;
	GFCommand* _btn_HDG_SEL;
	GFCommand* _btn_APP;
	GFCommand* _btn_ALT_HLD;
	GFCommand* _btn_VS;
	GFCommand* _btn_AP_Disengage;
	GFCommand* _btn_FD_Right;

	// USB Report Packet 6
	GFCommand* _btn_ALT_INV;
	GFCommand* _btn_CWS_A;
	GFCommand* _btn_CWS_B;

	/*
	GFCommand* _btn_IAS_Dial;
	GFCommand* _btn_HDG_Dial;
	GFCommand* _btn_ALT_Dial;
	*/

	GFCommand* _btn_FD_Left;
	GFCommand* _btn_N1;

	// USB Report Packet 7
	GFCommand* _btn_VNAV;
	GFCommand* _btn_LNAV;
	GFCommand* _btn_CMD_A;
	GFCommand* _btn_CMD_B;
	GFCommand* _btn_AT_Arm;
	GFCommand* _btn_CO;
	GFCommand* _btn_SPD_INTV;
	GFCommand* _btn_VOR_LOC;





	const std::string  _label_no_description = "No description.";


    const std::string _label_btn_speed        = "goflight/mcp_pro/emit/btn_speed";
	static int _action_btn_speed( GFMCPPro_State* );

	const std::string _label_btn_lvl_chg      = "goflight/mcp_pro/emit/btn_lvl_chg";
	static int _action_btn_lvl_chg( GFMCPPro_State* );

	const std::string _label_btn_hdg_sel      = "goflight/mcp_pro/emit/btn_hdg_sel";
	static int _action_btn_hdg_sel( GFMCPPro_State* );

	const std::string _label_btn_app          = "goflight/mcp_pro/emit/btn_app";
	static int _action_btn_app( GFMCPPro_State* );

	const std::string _label_btn_alt_hld      = "goflight/mcp_pro/emit/btn_alt_hld";
	static int _action_btn_alt_hld( GFMCPPro_State* );

	const std::string _label_btn_vs           = "goflight/mcp_pro/emit/btn_vs";
	static int _action_btn_vs( GFMCPPro_State* );


	const std::string _label_btn_ap_disengage = "goflight/mcp_pro/emit/btn_ap_disengage";
	static int _action_btn_ap_disengage( GFMCPPro_State* );


	const std::string _label_btn_fd_right     = "goflight/mcp_pro/emit/btn_fd_right";
	static int _action_btn_fd_right( GFMCPPro_State* );


	const std::string _label_btn_alt_inv      = "goflight/mcp_pro/emit/btn_alt_inv";
	static int _action_btn_alt_inv( GFMCPPro_State* );

	const std::string _label_btn_cws_a        = "goflight/mcp_pro/emit/btn_cws_a";
	static int _action_btn_cws_a( GFMCPPro_State* );

	const std::string _label_btn_cws_b        = "goflight/mcp_pro/emit/btn_cws_b";
	static int _action_btn_cws_b( GFMCPPro_State* );

	/*
	const std::string _label_btn_ias_dial     = "goflight/mcp_pro/emit/btn_ias_dial";
	static int _action_btn_ias_dial( GFMCPPro_State* );

	 const std::string _label_btn_hdg_dial     = "goflight/mcp_pro/emit/btn_hdg_dial";
	static int _action_btn_hdg_dial( GFMCPPro_State* );

	 const std::string _label_btn_alt_dial     = "goflight/mcp_pro/emit/btn_alt_dial";
	static int _action_btn_alt_dial( GFMCPPro_State* );
	*/

	const std::string _label_btn_fd_left      = "goflight/mcp_pro/emit/btn_fd_left";
	static int _action_btn_fd_left( GFMCPPro_State* );

	const std::string _label_btn_n1           = "goflight/mcp_pro/emit/btn_n1";
	static int _action_btn_n1( GFMCPPro_State* );
	
	const std::string _label_btn_vnav         = "goflight/mcp_pro/emit/btn_vnav";
	static int _action_btn_vnav( GFMCPPro_State* );

	const std::string _label_btn_lnav         = "goflight/mcp_pro/emit/btn_lnav";
	static int _action_btn_lnav( GFMCPPro_State* );

	const std::string _label_btn_cmd_a        = "goflight/mcp_pro/emit/btn_cmd_a";
	static int _action_btn_cmd_a( GFMCPPro_State* );

	const std::string _label_btn_cmd_b        = "goflight/mcp_pro/emit/btn_cmd_b";
	static int _action_btn_cmd_b( GFMCPPro_State* );

	const std::string _label_btn_at_arm       = "goflight/mcp_pro/emit/btn_at_arm";
	static int _action_btn_at_arm( GFMCPPro_State* );

	const std::string _label_btn_co           = "goflight/mcp_pro/emit/btn_co";
	static int _action_btn_co( GFMCPPro_State* );

	const std::string _label_btn_spd_intv     = "goflight/mcp_pro/emit/btn_spd_intv";
	static int _action_btn_spd_intv( GFMCPPro_State* );

	const std::string _label_btn_vor_loc      = "goflight/mcp_pro/emit/btn_vor_loc";
	static int _action_btn_vor_loc( GFMCPPro_State* );
	
	



	// Dials and knobs..

	
	const std::string _label_crs_left_inc     = "goflight/mcp_pro/emit/crs_left_inc";
    const std::string _label_crs_left_dec     = "goflight/mcp_pro/emit/crs_left_dec";
	static int _action_crs_left_dec( GFMCPPro_State* );
	static int _action_crs_left_inc( GFMCPPro_State* );


    const std::string _label_ias_mach_inc     = "goflight/mcp_pro/emit/ias_mach_inc";
    const std::string _label_ias_mach_dec     = "goflight/mcp_pro/emit/ias_mach_dec";
	static int _action_ias_mach_dec( GFMCPPro_State* );
	static int _action_ias_mach_inc( GFMCPPro_State* );


    const std::string _label_heading_inc      = "goflight/mcp_pro/emit/heading_inc";
	const std::string _label_heading_dec      = "goflight/mcp_pro/emit/heading_dec";
	static int _action_heading_dec( GFMCPPro_State* );
	static int _action_heading_inc( GFMCPPro_State* );


    const std::string _label_altitude_inc     = "goflight/mcp_pro/emit/altitude_inc";
	const std::string _label_altitude_dec     = "goflight/mcp_pro/emit/altitude_dec";
	static int _action_altitude_dec( GFMCPPro_State* );
	static int _action_altitude_inc( GFMCPPro_State* );


    const std::string _label_vert_speed_inc   = "goflight/mcp_pro/emit/vert_speed_inc";
    const std::string _label_vert_speed_dec   = "goflight/mcp_pro/emit/vert_speed_dec";
	static int _action_vert_speed_dec( GFMCPPro_State* );
	static int _action_vert_speed_inc( GFMCPPro_State* );


    const std::string _label_crs_right_inc    = "goflight/mcp_pro/emit/crs_right_inc";
    const std::string _label_crs_right_dec    = "goflight/mcp_pro/emit/crs_right_dec";
	static int _action_crs_right_dec( GFMCPPro_State* );
	static int _action_crs_right_inc( GFMCPPro_State* );



};


#endif //GF_MCP_PRO_GFMCPPRO_BUTTONS_H
