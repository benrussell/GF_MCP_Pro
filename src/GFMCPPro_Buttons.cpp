//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_Buttons.h"

#include "GFUtils.h"

#include <stdlib.h>
#include <hidapi.h>

#include "Windows_snprintf.h"



GFMCPPro_Buttons::GFMCPPro_Buttons( GFMCPPro_State* state ){

	_mcp_state = state;


	_btn_Connect            = new GFCommand( _cmd_name_device_connect, _label_no_description, (void*)this );
	_action_map[ _btn_Connect ] = &GFMCPPro_Buttons::_action_btn_connect;
	_btn_Disconnect         = new GFCommand( _cmd_name_device_disconnect, _label_no_description, (void*)this );
	_action_map[ _btn_Disconnect ] = &GFMCPPro_Buttons::_action_btn_disconnect;


	_btn_LightTest         = new GFCommand( _cmd_name_device_light_test, _label_no_description, (void*)this );
	_action_map[ _btn_LightTest ] = &GFMCPPro_Buttons::_action_btn_light_test;




	// Create commands for buttons and switches.
    _btn_Speed              = new GFCommand( _cmd_name_btn_speed, _label_no_description, (void*)this );
	_action_map[ _btn_Speed ] = &GFMCPPro_Buttons::_action_btn_speed;
	_btn_LVL_CHG            = new GFCommand( _cmd_name_btn_lvl_chg, _label_no_description, (void*)this );
	_action_map[ _btn_LVL_CHG ] = &GFMCPPro_Buttons::_action_btn_lvl_chg;
	_btn_HDG_SEL            = new GFCommand( _cmd_name_btn_hdg_sel, _label_no_description, (void*)this );
	_action_map[ _btn_HDG_SEL ] = &GFMCPPro_Buttons::_action_btn_hdg_sel;
	_btn_APP                = new GFCommand( _cmd_name_btn_app, _label_no_description, (void*)this );
	_action_map[ _btn_APP ] = &GFMCPPro_Buttons::_action_btn_app;
	_btn_ALT_HLD            = new GFCommand( _cmd_name_btn_alt_hld, _label_no_description, (void*)this );
	_action_map[ _btn_ALT_HLD ] = &GFMCPPro_Buttons::_action_btn_alt_hld;
	_btn_VS                 = new GFCommand( _cmd_name_btn_vs, _label_no_description, (void*)this );
	_action_map[ _btn_VS ] = &GFMCPPro_Buttons::_action_btn_vs;
	_btn_AP_Disengage       = new GFCommand( _cmd_name_btn_ap_disengage, _label_no_description, (void*)this );
	_action_map[ _btn_AP_Disengage ] = &GFMCPPro_Buttons::_action_btn_ap_disengage;
	_btn_FD_Right           = new GFCommand( _cmd_name_btn_fd_right, _label_no_description, (void*)this );
	_action_map[ _btn_FD_Right ] = &GFMCPPro_Buttons::_action_btn_fd_right;

	_btn_ALT_INV            = new GFCommand( _cmd_name_btn_alt_inv, _label_no_description, (void*)this );
	_action_map[ _btn_ALT_INV ] = &GFMCPPro_Buttons::_action_btn_alt_inv;
	_btn_CWS_A              = new GFCommand( _cmd_name_btn_cws_a, _label_no_description, (void*)this );
	_action_map[ _btn_CWS_A ] = &GFMCPPro_Buttons::_action_btn_cws_a;
	_btn_CWS_B              = new GFCommand( _cmd_name_btn_cws_b, _label_no_description, (void*)this );
	_action_map[ _btn_CWS_B ] = &GFMCPPro_Buttons::_action_btn_cws_b;



	_btn_FD_Left            = new GFCommand( _cmd_name_btn_fd_left, _label_no_description, (void*)this );
	_action_map[ _btn_FD_Left ] = &GFMCPPro_Buttons::_action_btn_fd_left;
	_btn_N1                 = new GFCommand( _cmd_name_btn_n1, _label_no_description, (void*)this );
	_action_map[ _btn_N1 ] = &GFMCPPro_Buttons::_action_btn_n1;

	_btn_VNAV               = new GFCommand( _cmd_name_btn_vnav, _label_no_description, (void*)this );
	_action_map[ _btn_VNAV ] = &GFMCPPro_Buttons::_action_btn_vnav;
	_btn_LNAV               = new GFCommand( _cmd_name_btn_lnav, _label_no_description, (void*)this );
	_action_map[ _btn_LNAV ] = &GFMCPPro_Buttons::_action_btn_lnav;
	_btn_CMD_A              = new GFCommand( _cmd_name_btn_cmd_a, _label_no_description, (void*)this );
	_action_map[ _btn_CMD_A ] = &GFMCPPro_Buttons::_action_btn_cmd_a;
	_btn_CMD_B              = new GFCommand( _cmd_name_btn_cmd_b, _label_no_description, (void*)this );
	_action_map[ _btn_CMD_B ] = &GFMCPPro_Buttons::_action_btn_cmd_b;
	_btn_AT_Arm             = new GFCommand( _cmd_name_btn_at_arm, _label_no_description, (void*)this );
	_action_map[ _btn_AT_Arm ] = &GFMCPPro_Buttons::_action_btn_at_arm;
	_btn_CO                 = new GFCommand( _cmd_name_btn_co, _label_no_description, (void*)this );
	_action_map[ _btn_CO ] = &GFMCPPro_Buttons::_action_btn_co;
	_btn_SPD_INTV           = new GFCommand( _cmd_name_btn_spd_intv, _label_no_description, (void*)this );
	_action_map[ _btn_SPD_INTV ] = &GFMCPPro_Buttons::_action_btn_spd_intv;
	_btn_VOR_LOC            = new GFCommand( _cmd_name_btn_vor_loc, _label_no_description, (void*)this );
	_action_map[ _btn_VOR_LOC ] = &GFMCPPro_Buttons::_action_btn_vor_loc;





	// Create commands for Scroll Wheels and Rotary Knobs.
    _btn_crs_left_inc = new GFCommand( _cmd_name_crs_left_inc, _label_no_description, (void*)this );
    _btn_crs_left_dec = new GFCommand( _cmd_name_crs_left_dec, _label_no_description, (void*)this );
	_action_map[ _btn_crs_left_inc ] = &GFMCPPro_Buttons::_action_crs_left_inc;
	_action_map[ _btn_crs_left_dec ] = &GFMCPPro_Buttons::_action_crs_left_dec;
	
	
	_btn_ias_mach_inc = new GFCommand( _cmd_name_ias_mach_inc, _label_no_description, (void*)this );
    _btn_ias_mach_dec = new GFCommand( _cmd_name_ias_mach_dec, _label_no_description, (void*)this );
	_action_map[ _btn_ias_mach_inc ] = &GFMCPPro_Buttons::_action_ias_mach_inc;
	_action_map[ _btn_ias_mach_dec ] = &GFMCPPro_Buttons::_action_ias_mach_dec;


    _btn_heading_inc = new GFCommand( _cmd_name_heading_inc, _label_no_description, (void*)this );
    _btn_heading_dec = new GFCommand( _cmd_name_heading_dec, _label_no_description, (void*)this );
	_action_map[ _btn_heading_inc ] = &GFMCPPro_Buttons::_action_heading_inc;
	_action_map[ _btn_heading_dec ] = &GFMCPPro_Buttons::_action_heading_dec;


	_btn_altitude_inc = new GFCommand( _cmd_name_altitude_inc, _label_no_description, (void*)this );
    _btn_altitude_dec = new GFCommand( _cmd_name_altitude_dec, _label_no_description, (void*)this );
	_action_map[ _btn_altitude_inc ] = &GFMCPPro_Buttons::_action_altitude_inc;
	_action_map[ _btn_altitude_dec ] = &GFMCPPro_Buttons::_action_altitude_dec;

	
    _btn_vert_speed_inc = new GFCommand( _cmd_name_vert_speed_inc, _label_no_description, (void*)this );
    _btn_vert_speed_dec = new GFCommand( _cmd_name_vert_speed_dec, _label_no_description, (void*)this );
	_action_map[ _btn_vert_speed_inc ] = &GFMCPPro_Buttons::_action_vert_speed_inc;
	_action_map[ _btn_vert_speed_dec ] = &GFMCPPro_Buttons::_action_vert_speed_dec;

	
    _btn_crs_right_inc = new GFCommand( _cmd_name_crs_right_inc, _label_no_description, (void*)this );
    _btn_crs_right_dec = new GFCommand( _cmd_name_crs_right_dec, _label_no_description, (void*)this );
	_action_map[ _btn_crs_right_inc ] = &GFMCPPro_Buttons::_action_crs_right_inc;
	_action_map[ _btn_crs_right_dec ] = &GFMCPPro_Buttons::_action_crs_right_dec;

}



GFMCPPro_Buttons::~GFMCPPro_Buttons(){

	delete(_btn_Connect);
	delete(_btn_Disconnect);

	delete(_btn_LightTest);

	delete(_btn_Speed);
	delete(_btn_LVL_CHG);
	delete(_btn_HDG_SEL);
	delete(_btn_APP);
	delete(_btn_ALT_HLD);
	delete(_btn_VS);
	delete(_btn_AP_Disengage);
	delete(_btn_FD_Right);

	delete(_btn_ALT_INV);
	delete(_btn_CWS_A);
	delete(_btn_CWS_B);

	delete(_btn_FD_Left);
	delete(_btn_N1);

	delete(_btn_VNAV);
	delete(_btn_LNAV);
	delete(_btn_CMD_A);
	delete(_btn_CMD_B);
	delete(_btn_AT_Arm);
	delete(_btn_CO);
	delete(_btn_SPD_INTV);
	delete(_btn_VOR_LOC);



	//knobs
	delete(_btn_crs_left_inc);
	delete(_btn_crs_left_dec);

	delete(_btn_ias_mach_inc);
	delete(_btn_ias_mach_dec);

	delete(_btn_heading_inc);
	delete(_btn_heading_dec);

	delete(_btn_altitude_inc);
	delete(_btn_altitude_dec);

	delete(_btn_vert_speed_inc);
	delete(_btn_vert_speed_dec);

	delete(_btn_crs_right_inc);
	delete(_btn_crs_right_dec);

}





void GFMCPPro_Buttons::read( hid_device* handle ) {

    _read_usb( handle );

}





int  GFMCPPro_Buttons::xp_cmd_action_handler(
		XPLMCommandPhase     inPhase,
		GFCommand*               inCmd){

	// http://www.xsquawkbox.net/xpsdk/mediawiki/XPLMRegisterCommandHandler

	if( inPhase != xplm_CommandBegin ) {
		//we're only interested in the begin state, we dont have any hold or end events
		return 1;
	}


	if( 1 == _mcp_state->_dref_override->_int_value ){
		//we can ignore all the buttons!
		return 1;
	}



	// Use the command string to find the action function in a std::map.
	std::map<GFCommand*, GF_action_func>::iterator it = _action_map.find( inCmd );

	if( it != _action_map.end() ){

		// deref to actual type for no reason other than clarity of purpose.
		GF_action_func f = it->second;
		f( _mcp_state );

	}else{

		char caTmp[1024];
		snprintf( caTmp, 1024, "Undefined action for cmd string:(%s)\n", inCmd->_name.c_str() );
		GFUtils::Log( caTmp );

	}


	return 1;

}






void GFMCPPro_Buttons::_read_usb( hid_device* handle ) {

	if( 0 == handle ){
		GFUtils::Log("USB Read Failed: Invalid device handle.\n");
		return;
	}

    const int buf_size=8;
    unsigned char buf[buf_size];
	memset(buf, 0, buf_size);

	// Read hardware state
	int res = hid_read( handle, buf, buf_size);
    if (res < 0) {
		//FIXME: usb read fail, propagate.
		GFUtils::Log("USB Read Failed.\n");
		_mcp_state->_dref_connected->_int_value = 0;

    } else {

        //_dump_button_packet( res, buf );
        _proc_hid_packet( buf );

    } //checking for packet read

} // read_usb()



void GFMCPPro_Buttons::_proc_hid_packet( unsigned char* buf ) {

	// All knob events come through on channels 1,2,3.
	if( buf[1] || buf[2] || buf[3] ){
		// ------------------ Knobs ----------------
		_proc_knobs( buf );

	}else{
		// ------------------ Buttons --------------
		_proc_buttons( buf );

	}

}





int GFMCPPro_Buttons::_is_knob_bitflag_activity( unsigned char bit_flags ) {

	int activity_detected = 0;

	if( bit_flags & 1 || bit_flags & 2 || bit_flags & 4 ){
		//activity.
		activity_detected = 1;
	}

	return activity_detected;

}


int GFMCPPro_Buttons::_is_knob_left( unsigned char bit_flags ) {

	if( ! _is_knob_bitflag_activity( bit_flags ) ){
		return 0;
	}

	// low bit on 4 indicates knob left.
	if( bit_flags & 8 ){
		return 0;
	}
	return 1;
}



int GFMCPPro_Buttons::_is_knob_right( unsigned char bit_flags ) {

	if( ! _is_knob_bitflag_activity( bit_flags ) ){
		return 0;
	}

	// high bit on 4 indicates knob right.
	if( bit_flags & 8 ){
		return 1;
	}
	return 0;
}






void GFMCPPro_Buttons::_proc_knobs( unsigned char* buf ) {

	// raw bitflag data from logging.

	// 1,2,3 -- max 7.
	// 0000 0abc

	// 14,15 -- max 15.
	// 0000 1abc


	// 16, 32, 48, 64
	// 0dcb 0000

	// 224, 240,
	// 1dcb 0000


	// we only need to look at 1 byte at a time. bit shifting also needed.
	// single byte var much easier to use.
	unsigned char btn_flags;


	// Packet 1
	// --------------------
	// HDG
	btn_flags = buf[1];
	_is_knob_right( btn_flags ) ? _btn_heading_inc->Begin() : _btn_heading_inc->Stop();
	_is_knob_left( btn_flags )  ? _btn_heading_dec->Begin() : _btn_heading_dec->Stop();
	// CRS Left
	btn_flags = buf[1] >> 4;
	_is_knob_right( btn_flags ) ? _btn_crs_left_inc->Begin() : _btn_crs_left_inc->Stop();
	_is_knob_left( btn_flags )  ? _btn_crs_left_dec->Begin() : _btn_crs_left_dec->Stop();

	// Packet 2
	// --------------------
	// VS
	btn_flags = buf[2];
	_is_knob_right( btn_flags ) ? _btn_vert_speed_inc->Begin() : _btn_vert_speed_inc->Stop();
	_is_knob_left( btn_flags )  ? _btn_vert_speed_dec->Begin() : _btn_vert_speed_dec->Stop();
	// IAS
	btn_flags = buf[2] >> 4;
	_is_knob_right( btn_flags ) ? _btn_ias_mach_inc->Begin() : _btn_ias_mach_inc->Stop();
	_is_knob_left( btn_flags )  ? _btn_ias_mach_dec->Begin() : _btn_ias_mach_dec->Stop();

	// Packet 3
	// --------------------
	// CRS Right
	btn_flags = buf[3];
	_is_knob_right( btn_flags ) ? _btn_crs_right_inc->Begin() : _btn_crs_right_inc->Stop();
	_is_knob_left( btn_flags )  ? _btn_crs_right_dec->Begin() : _btn_crs_right_dec->Stop();
	// ALT
	btn_flags = buf[3] >> 4;
	_is_knob_right( btn_flags ) ? _btn_altitude_inc->Begin() : _btn_altitude_inc->Stop();
	_is_knob_left( btn_flags )  ? _btn_altitude_dec->Begin() : _btn_altitude_dec->Stop();

}



void GFMCPPro_Buttons::_proc_buttons( unsigned char* buf ){

	// Channel
	// packet, value


	// Packet 5
    // --------------------
    // Speed            1
    // LVL CHG          2
    // HDG SEL          4
    // APP              8
    // ALT HLD          16
    // V/S              32
    // AP Disengage     64
    // FD Right         128
    buf[5] & 1 ? _btn_Speed->Begin()            : _btn_Speed->Stop();
    buf[5] & 2 ? _btn_LVL_CHG->Begin()          : _btn_LVL_CHG->Stop();
    buf[5] & 4 ? _btn_HDG_SEL->Begin()          : _btn_HDG_SEL->Stop();
    buf[5] & 8 ? _btn_APP->Begin()              : _btn_APP->Stop();
    buf[5] & 16 ? _btn_ALT_HLD->Begin()         : _btn_ALT_HLD->Stop();
    buf[5] & 32 ? _btn_VS->Begin()              : _btn_VS->Stop();
    buf[5] & 64 ? _btn_AP_Disengage->Begin()    : _btn_AP_Disengage->Stop();
    buf[5] & 128 ? _btn_FD_Right->Begin()       : _btn_FD_Right->Stop();

    // Packet 6
    // --------------------
    // ALT INV          1
    // CWS A            2
    // CWS B            4
    // IAS Dial         8
    // HDG Dial         16
    // ALT Dial         32
    // FD Left          64
    // N1               128
    buf[6] & 1 ? _btn_ALT_INV->Begin()          : _btn_ALT_INV->Stop();
    buf[6] & 2 ? _btn_CWS_A->Begin()            : _btn_CWS_A->Stop();
    buf[6] & 4 ? _btn_CWS_B->Begin()            : _btn_CWS_B->Stop();
    //buf[6] & 8 ? _btn_IAS_Dial->Begin()         : _btn_IAS_Dial->Stop(); // -- Dial --
    //buf[6] & 16 ? _btn_HDG_Dial->Begin()        : _btn_HDG_Dial->Stop(); // -- Dial --
    //buf[6] & 32 ? _btn_ALT_Dial->Begin()        : _btn_ALT_Dial->Stop(); // -- Dial --
    buf[6] & 64 ? _btn_FD_Left->Begin()         : _btn_FD_Left->Stop();
    buf[6] & 128 ? _btn_N1->Begin()             : _btn_N1->Stop();

    // Packet 7
    // --------------------
    // VNAV             1
    // LNAV             2
    // CMD A            4
    // CMD B            8
    // AT Arm           16
    // C/O              32
    // SPD INTV         64
    // VOR LOC          128
    buf[7] & 1 ? _btn_VNAV->Begin()             : _btn_VNAV->Stop();
    buf[7] & 2 ? _btn_LNAV->Begin()             : _btn_LNAV->Stop();
    buf[7] & 4 ? _btn_CMD_A->Begin()            : _btn_CMD_A->Stop();
    buf[7] & 8 ? _btn_CMD_B->Begin()            : _btn_CMD_B->Stop();
    buf[7] & 16 ? _btn_AT_Arm->Begin()          : _btn_AT_Arm->Stop();
    buf[7] & 32 ? _btn_CO->Begin()              : _btn_CO->Stop();
    buf[7] & 64 ? _btn_SPD_INTV->Begin()        : _btn_SPD_INTV->Stop();
    buf[7] & 128 ? _btn_VOR_LOC->Begin()        : _btn_VOR_LOC->Stop();



} //_proc_button_packet



void GFMCPPro_Buttons::_dump_button_packet( int res, unsigned char* buf ){

    // Print out the returned buffer.
    for (int i = 0; i < res; i++) {
        printf("%4d    ", buf[i]);
    }
    //if a report has been rxd and dumped, we should put a new line
    if (res > 0) {
        printf("\n");
    }

}




const std::string GFMCPPro_Buttons::_label_no_description 	   = "No description.";



const std::string GFMCPPro_Buttons::_cmd_name_device_connect      = "goflight/mcp_pro/device/connect";
const std::string GFMCPPro_Buttons::_cmd_name_device_disconnect   = "goflight/mcp_pro/device/disconnect";

const std::string GFMCPPro_Buttons::_cmd_name_device_light_test   = "goflight/mcp_pro/device/light_test";


const std::string GFMCPPro_Buttons::_cmd_name_btn_speed        = "goflight/mcp_pro/btn/speed";
const std::string GFMCPPro_Buttons::_cmd_name_btn_lvl_chg      = "goflight/mcp_pro/btn/lvl_chg";
const std::string GFMCPPro_Buttons::_cmd_name_btn_hdg_sel      = "goflight/mcp_pro/btn/hdg_sel";
const std::string GFMCPPro_Buttons::_cmd_name_btn_app          = "goflight/mcp_pro/btn/app";
const std::string GFMCPPro_Buttons::_cmd_name_btn_alt_hld      = "goflight/mcp_pro/btn/alt_hld";
const std::string GFMCPPro_Buttons::_cmd_name_btn_vs           = "goflight/mcp_pro/btn/vs";
const std::string GFMCPPro_Buttons::_cmd_name_btn_ap_disengage = "goflight/mcp_pro/btn/ap_disengage";
const std::string GFMCPPro_Buttons::_cmd_name_btn_fd_right     = "goflight/mcp_pro/btn/fd_right";
const std::string GFMCPPro_Buttons::_cmd_name_btn_alt_inv      = "goflight/mcp_pro/btn/alt_inv";
const std::string GFMCPPro_Buttons::_cmd_name_btn_cws_a        = "goflight/mcp_pro/btn/cws_a";
const std::string GFMCPPro_Buttons::_cmd_name_btn_cws_b        = "goflight/mcp_pro/btn/cws_b";
const std::string GFMCPPro_Buttons::_cmd_name_btn_fd_left      = "goflight/mcp_pro/btn/fd_left";
const std::string GFMCPPro_Buttons::_cmd_name_btn_n1           = "goflight/mcp_pro/btn/n1";
const std::string GFMCPPro_Buttons::_cmd_name_btn_vnav         = "goflight/mcp_pro/btn/vnav";
const std::string GFMCPPro_Buttons::_cmd_name_btn_lnav         = "goflight/mcp_pro/btn/lnav";
const std::string GFMCPPro_Buttons::_cmd_name_btn_cmd_a        = "goflight/mcp_pro/btn/cmd_a";
const std::string GFMCPPro_Buttons::_cmd_name_btn_cmd_b        = "goflight/mcp_pro/btn/cmd_b";
const std::string GFMCPPro_Buttons::_cmd_name_btn_at_arm       = "goflight/mcp_pro/btn/at_arm";
const std::string GFMCPPro_Buttons::_cmd_name_btn_co           = "goflight/mcp_pro/btn/co";
const std::string GFMCPPro_Buttons::_cmd_name_btn_spd_intv     = "goflight/mcp_pro/btn/spd_intv";
const std::string GFMCPPro_Buttons::_cmd_name_btn_vor_loc      = "goflight/mcp_pro/btn/vor_loc";



// Dials and knobs..
const std::string GFMCPPro_Buttons::_cmd_name_crs_left_inc     = "goflight/mcp_pro/knob/crs_left_inc";
const std::string GFMCPPro_Buttons::_cmd_name_crs_left_dec     = "goflight/mcp_pro/knob/crs_left_dec";

const std::string GFMCPPro_Buttons::_cmd_name_ias_mach_inc     = "goflight/mcp_pro/knob/ias_mach_inc";
const std::string GFMCPPro_Buttons::_cmd_name_ias_mach_dec     = "goflight/mcp_pro/knob/ias_mach_dec";

const std::string GFMCPPro_Buttons::_cmd_name_heading_inc      = "goflight/mcp_pro/knob/heading_inc";
const std::string GFMCPPro_Buttons::_cmd_name_heading_dec      = "goflight/mcp_pro/knob/heading_dec";

const std::string GFMCPPro_Buttons::_cmd_name_altitude_inc     = "goflight/mcp_pro/knob/altitude_inc";
const std::string GFMCPPro_Buttons::_cmd_name_altitude_dec     = "goflight/mcp_pro/knob/altitude_dec";

const std::string GFMCPPro_Buttons::_cmd_name_vert_speed_inc   = "goflight/mcp_pro/knob/vert_speed_inc";
const std::string GFMCPPro_Buttons::_cmd_name_vert_speed_dec   = "goflight/mcp_pro/knob/vert_speed_dec";

const std::string GFMCPPro_Buttons::_cmd_name_crs_right_inc    = "goflight/mcp_pro/knob/crs_right_inc";
const std::string GFMCPPro_Buttons::_cmd_name_crs_right_dec    = "goflight/mcp_pro/knob/crs_right_dec";






int GFMCPPro_Buttons::_action_btn_connect( GFMCPPro_State* mcp_state ){

	GFUtils::Log("cmd: Connection request..");
	mcp_state->_wants_connection = 1;

	return 1;
}

int GFMCPPro_Buttons::_action_btn_disconnect( GFMCPPro_State* mcp_state ){

	GFUtils::Log("cmd: Disconnection request..");
	mcp_state->_wants_disconnection = 1;

	return 1;
}




int GFMCPPro_Buttons::_action_btn_light_test( GFMCPPro_State* mcp_state ){

	GFUtils::Log("cmd: Light Test..");
	//FIXME: light test cycle needs a timer
	mcp_state->_dref_light_test->_int_value = 1;

	return 1;
}









int GFMCPPro_Buttons::_action_btn_speed( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_speed->_int_value ){
		mcp_state->_dref_leds_speed->_int_value = 0;
	}else{
		mcp_state->_dref_leds_speed->_int_value = 1;
	}

	return 1;
}

int GFMCPPro_Buttons::_action_btn_lvl_chg( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_lvl_chg->_int_value ){
		mcp_state->_dref_leds_lvl_chg->_int_value = 0;
	}else{
		mcp_state->_dref_leds_lvl_chg->_int_value = 1;
	}

	return 1;
}

int GFMCPPro_Buttons::_action_btn_hdg_sel( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_hdg_sel->_int_value ){
		mcp_state->_dref_leds_hdg_sel->_int_value = 0;
	}else{
		mcp_state->_dref_leds_hdg_sel->_int_value = 1;
	}

	return 1;
}

int GFMCPPro_Buttons::_action_btn_app( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_app->_int_value ){
		mcp_state->_dref_leds_app->_int_value = 0;
	}else{
		mcp_state->_dref_leds_app->_int_value = 1;
	}

	return 1;
}




int GFMCPPro_Buttons::_action_btn_alt_hld( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_alt_hld->_int_value ){
		mcp_state->_dref_leds_alt_hld->_int_value = 0;
	}else{
		mcp_state->_dref_leds_alt_hld->_int_value = 1;
	}

	return 1;
}




int GFMCPPro_Buttons::_action_btn_vs( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_vs->_int_value ){
		mcp_state->_dref_leds_vs->_int_value = 0;
	}else{
		mcp_state->_dref_leds_vs->_int_value = 1;
	}

	return 1;
}



int GFMCPPro_Buttons::_action_btn_ap_disengage( GFMCPPro_State* mcp_state ){

	// There is no LED for this switch.

	//TODO: trigger built in xp ap dis command ? emit gf cmd sig only?
	// cant find the cmd string

	return 1;
}



int GFMCPPro_Buttons::_action_btn_fd_right( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_fd_right->_int_value ){
		mcp_state->_dref_leds_fd_right->_int_value = 0;
	}else{
		mcp_state->_dref_leds_fd_right->_int_value = 1;
	}

	return 1;
}




int GFMCPPro_Buttons::_action_btn_alt_inv( GFMCPPro_State* mcp_state ){

	// There is no LED for this button.

	//TODO: clarify purpose of alt inv button
	//cam: "It does not have an LED. It's a small red button. I think it's NG specific"

	/*
	[11/05/2016 12:39:09 pm] Cameron: http://www.flaps2approach.com/journal/2013/2/20/speed-altitude-intervention-spd-intv-alt-intv-v-nav-how-to-u.html
[11/05/2016 12:39:40 pm] Cameron: Engaging speed intervention you will immediately observe that the MCP speed window becomes active iand displays your current speed.  Dial in into the speed window the new speed requirement of 280 kias.  Notice on the PFD that the speed indicator value above the speed tape has changed from 300 kias to the new speed of 280 kias.  If you cross check with the cruise altitude (INDEX/PERF INT/CRZ ALT) in the CDU it will still indicate the cruise speed of 300 kias.
[11/05/2016 12:40:23 pm] Cameron: ALT INTV is even more fun
[11/05/2016 12:40:24 pm] Cameron: http://www.flaps2approach.com/storage/post-images/2013-posts/altitude-speed-intervention/alpha.jpg?__SQUARESPACE_CACHEVERSION=1361007752444
[11/05/2016 12:40:50 pm] Cameron: Anyways, that's basically up to a developer of an aircraft to code logic for
	 */

	return 1;
}


int GFMCPPro_Buttons::_action_btn_cws_a( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_cws_a->_int_value ){
		mcp_state->_dref_leds_cws_a->_int_value = 0;
	}else{
		mcp_state->_dref_leds_cws_a->_int_value = 1;
	}

	return 1;
}


int GFMCPPro_Buttons::_action_btn_cws_b( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_cws_b->_int_value ){
		mcp_state->_dref_leds_cws_b->_int_value = 0;
	}else{
		mcp_state->_dref_leds_cws_b->_int_value = 1;
	}

	return 1;
}



int GFMCPPro_Buttons::_action_btn_fd_left( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_fd_left->_int_value ){
		mcp_state->_dref_leds_fd_left->_int_value = 0;
	}else{
		mcp_state->_dref_leds_fd_left->_int_value = 1;
	}

	return 1;
}



int GFMCPPro_Buttons::_action_btn_n1( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_n1->_int_value ){
		mcp_state->_dref_leds_n1->_int_value = 0;
	}else{
		mcp_state->_dref_leds_n1->_int_value = 1;
	}

	return 1;
}




int GFMCPPro_Buttons::_action_btn_vnav( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_vnav->_int_value ){
		mcp_state->_dref_leds_vnav->_int_value = 0;
	}else{
		mcp_state->_dref_leds_vnav->_int_value = 1;
	}

	return 1;
}





int GFMCPPro_Buttons::_action_btn_lnav( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_lnav->_int_value ){
		mcp_state->_dref_leds_lnav->_int_value = 0;
	}else{
		mcp_state->_dref_leds_lnav->_int_value = 1;
	}

	return 1;
}





int GFMCPPro_Buttons::_action_btn_cmd_a( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_cmd_a->_int_value ){
		mcp_state->_dref_leds_cmd_a->_int_value = 0;
	}else{
		mcp_state->_dref_leds_cmd_a->_int_value = 1;
	}

	return 1;
}


int GFMCPPro_Buttons::_action_btn_cmd_b( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_cmd_b->_int_value ){
		mcp_state->_dref_leds_cmd_b->_int_value = 0;
	}else{
		mcp_state->_dref_leds_cmd_b->_int_value = 1;
	}

	return 1;
}





int GFMCPPro_Buttons::_action_btn_at_arm( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_at_arm->_int_value ){
		mcp_state->_dref_leds_at_arm->_int_value = 0;
	}else{
		mcp_state->_dref_leds_at_arm->_int_value = 1;
	}

	return 1;
}




int GFMCPPro_Buttons::_action_btn_co( GFMCPPro_State* mcp_state ){

	// There is no LED for this button.

	//TODO: clarify purpose of CO button
	//switch between IAS and Mach

	return 1;
}







int GFMCPPro_Buttons::_action_btn_spd_intv( GFMCPPro_State* mcp_state ){

	// There is no LED for this button.

	//TODO: see alt intv

	return 1;
}






int GFMCPPro_Buttons::_action_btn_vor_loc( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_vor_loc->_int_value ){
		mcp_state->_dref_leds_vor_loc->_int_value = 0;
	}else{
		mcp_state->_dref_leds_vor_loc->_int_value = 1;
	}

	return 1;
}








/// ---- knobs and dials ---



int GFMCPPro_Buttons::_action_crs_left_dec( GFMCPPro_State* mcp_state ){
	mcp_state->_dref_crs_left->_int_value--;
	return 0;
}

int GFMCPPro_Buttons::_action_crs_left_inc( GFMCPPro_State* mcp_state ){
	mcp_state->_dref_crs_left->_int_value++;
	return 0;
}



int GFMCPPro_Buttons::_action_ias_mach_dec( GFMCPPro_State* mcp_state ){
	mcp_state->_dref_ias_mach->_int_value--;
	return 0;
}

int GFMCPPro_Buttons::_action_ias_mach_inc( GFMCPPro_State* mcp_state ){
	mcp_state->_dref_ias_mach->_int_value++;
	return 0;
}



int GFMCPPro_Buttons::_action_heading_dec( GFMCPPro_State* mcp_state ){
	mcp_state->_dref_heading->_int_value--;
	return 0;
}

int GFMCPPro_Buttons::_action_heading_inc( GFMCPPro_State* mcp_state ){
	mcp_state->_dref_heading->_int_value++;
	return 0;
}



int GFMCPPro_Buttons::_action_altitude_dec( GFMCPPro_State* mcp_state ){
	mcp_state->_dref_altitude->_int_value--;
	return 0;
}

int GFMCPPro_Buttons::_action_altitude_inc( GFMCPPro_State* mcp_state ){
	mcp_state->_dref_altitude->_int_value++;
	return 0;
}



int GFMCPPro_Buttons::_action_vert_speed_dec( GFMCPPro_State* mcp_state ){
	mcp_state->_dref_vert_speed->_int_value--;
	return 0;
}

int GFMCPPro_Buttons::_action_vert_speed_inc( GFMCPPro_State* mcp_state ){
	mcp_state->_dref_vert_speed->_int_value++;
	return 0;
}


int GFMCPPro_Buttons::_action_crs_right_dec( GFMCPPro_State* mcp_state ){
	mcp_state->_dref_crs_right->_int_value--;
	return 0;
}

int GFMCPPro_Buttons::_action_crs_right_inc( GFMCPPro_State* mcp_state ){
	mcp_state->_dref_crs_right->_int_value++;
	return 0;
}






// eof
