//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_Buttons.h"

#include "GFUtils.h"

#include <stdlib.h>
#include <hidapi.h>

#include "Windows_snprintf.h"



GFMCPPro_Buttons::GFMCPPro_Buttons( GFMCPPro_State* state ){

	_handle = 0;

	_mcp_state = state;

    // Create commands for buttons and switches.
    _btn_Speed              = new GFCommand( (char*)_label_btn_speed.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_speed ] = &GFMCPPro_Buttons::_action_btn_speed;
	_btn_LVL_CHG            = new GFCommand( (char*)_label_btn_lvl_chg.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_lvl_chg ] = &GFMCPPro_Buttons::_action_btn_lvl_chg;
	_btn_HDG_SEL            = new GFCommand( (char*)_label_btn_hdg_sel.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_hdg_sel ] = &GFMCPPro_Buttons::_action_btn_hdg_sel;
	_btn_APP                = new GFCommand( (char*)_label_btn_app.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_app ] = &GFMCPPro_Buttons::_action_btn_app;
	_btn_ALT_HLD            = new GFCommand( (char*)_label_btn_alt_hld.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_alt_hld ] = &GFMCPPro_Buttons::_action_btn_alt_hld;
	_btn_VS                 = new GFCommand( (char*)_label_btn_vs.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_vs ] = &GFMCPPro_Buttons::_action_btn_vs;
	_btn_AP_Disengage       = new GFCommand( (char*)_label_btn_ap_disengage.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_ap_disengage ] = &GFMCPPro_Buttons::_action_btn_ap_disengage;
	_btn_FD_Right           = new GFCommand( (char*)_label_btn_fd_right.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_fd_right ] = &GFMCPPro_Buttons::_action_btn_fd_right;

	_btn_ALT_INV            = new GFCommand( (char*)_label_btn_alt_inv.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_alt_inv ] = &GFMCPPro_Buttons::_action_btn_alt_inv;
	_btn_CWS_A              = new GFCommand( (char*)_label_btn_cws_a.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_cws_a ] = &GFMCPPro_Buttons::_action_btn_cws_a;
	_btn_CWS_B              = new GFCommand( (char*)_label_btn_cws_b.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_cws_b ] = &GFMCPPro_Buttons::_action_btn_cws_b;

	/*
	_btn_IAS_Dial           = new GFCommand( (char*)_label_btn_ias_dial.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_ias_dial ] = &GFMCPPro_Buttons::_action_btn_ias_dial;
	_btn_HDG_Dial           = new GFCommand( (char*)_label_btn_hdg_dial.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_hdg_dial ] = &GFMCPPro_Buttons::_action_btn_hdg_dial;
	_btn_ALT_Dial           = new GFCommand( (char*)_label_btn_alt_dial.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_alt_dial ] = &GFMCPPro_Buttons::_action_btn_alt_dial;
	*/

	_btn_FD_Left            = new GFCommand( (char*)_label_btn_fd_left.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_fd_left ] = &GFMCPPro_Buttons::_action_btn_fd_left;
	_btn_N1                 = new GFCommand( (char*)_label_btn_n1.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_n1 ] = &GFMCPPro_Buttons::_action_btn_n1;

	_btn_VNAV               = new GFCommand( (char*)_label_btn_vnav.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_vnav ] = &GFMCPPro_Buttons::_action_btn_vnav;
	_btn_LNAV               = new GFCommand( (char*)_label_btn_lnav.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_lnav ] = &GFMCPPro_Buttons::_action_btn_lnav;
	_btn_CMD_A              = new GFCommand( (char*)_label_btn_cmd_a.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_cmd_a ] = &GFMCPPro_Buttons::_action_btn_cmd_a;
	_btn_CMD_B              = new GFCommand( (char*)_label_btn_cmd_b.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_cmd_b ] = &GFMCPPro_Buttons::_action_btn_cmd_b;
	_btn_AT_Arm             = new GFCommand( (char*)_label_btn_at_arm.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_at_arm ] = &GFMCPPro_Buttons::_action_btn_at_arm;
	_btn_CO                 = new GFCommand( (char*)_label_btn_co.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_co ] = &GFMCPPro_Buttons::_action_btn_co;
	_btn_SPD_INTV           = new GFCommand( (char*)_label_btn_spd_intv.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_spd_intv ] = &GFMCPPro_Buttons::_action_btn_spd_intv;
	_btn_VOR_LOC            = new GFCommand( (char*)_label_btn_vor_loc.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_btn_vor_loc ] = &GFMCPPro_Buttons::_action_btn_vor_loc;



	// Create commands for Scroll Wheels and Rotary Knobs.
    _btn_crs_left_inc = new GFCommand( (char*)_label_crs_left_inc.c_str(), (char*)_label_no_description.c_str(), (void*)this );
    _btn_crs_left_dec = new GFCommand( (char*)_label_crs_left_dec.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_crs_left_inc ] = &GFMCPPro_Buttons::_action_crs_left_inc;
	_action_map[ _label_crs_left_dec ] = &GFMCPPro_Buttons::_action_crs_left_dec;
	
	
	_btn_ias_mach_inc = new GFCommand( (char*)_label_ias_mach_inc.c_str(), (char*)_label_no_description.c_str(), (void*)this );
    _btn_ias_mach_dec = new GFCommand( (char*)_label_ias_mach_dec.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_ias_mach_inc ] = &GFMCPPro_Buttons::_action_ias_mach_inc;
	_action_map[ _label_ias_mach_dec ] = &GFMCPPro_Buttons::_action_ias_mach_dec;


    _btn_heading_inc = new GFCommand( (char*)_label_heading_inc.c_str(), (char*)_label_no_description.c_str(), (void*)this );
    _btn_heading_dec = new GFCommand( (char*)_label_heading_dec.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_heading_inc ] = &GFMCPPro_Buttons::_action_heading_inc;
	_action_map[ _label_heading_dec ] = &GFMCPPro_Buttons::_action_heading_dec;


	_btn_altitude_inc = new GFCommand( (char*)_label_altitude_inc.c_str(), (char*)_label_no_description.c_str(), (void*)this );
    _btn_altitude_dec = new GFCommand( (char*)_label_altitude_dec.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_altitude_inc ] = &GFMCPPro_Buttons::_action_altitude_inc;
	_action_map[ _label_altitude_dec ] = &GFMCPPro_Buttons::_action_altitude_dec;

	
    _btn_vert_speed_inc = new GFCommand( (char*)_label_vert_speed_inc.c_str(), (char*)_label_no_description.c_str(), (void*)this );
    _btn_vert_speed_dec = new GFCommand( (char*)_label_vert_speed_dec.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_vert_speed_inc ] = &GFMCPPro_Buttons::_action_vert_speed_inc;
	_action_map[ _label_vert_speed_dec ] = &GFMCPPro_Buttons::_action_vert_speed_dec;

	
    _btn_crs_right_inc = new GFCommand( (char*)_label_crs_right_inc.c_str(), (char*)_label_no_description.c_str(), (void*)this );
    _btn_crs_right_dec = new GFCommand( (char*)_label_crs_right_dec.c_str(), (char*)_label_no_description.c_str(), (void*)this );
	_action_map[ _label_crs_right_inc ] = &GFMCPPro_Buttons::_action_crs_right_inc;
	_action_map[ _label_crs_right_dec ] = &GFMCPPro_Buttons::_action_crs_right_dec;

}



GFMCPPro_Buttons::~GFMCPPro_Buttons(){

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

	/*
	delete(_btn_IAS_Dial);
	delete(_btn_HDG_Dial);
	delete(_btn_ALT_Dial);
	*/

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





void GFMCPPro_Buttons::read() {

    _read_usb();

}





int  GFMCPPro_Buttons::xp_cmd_action_handler(
		XPLMCommandRef        inCommand,
		XPLMCommandPhase     inPhase,
		GFCommand*               cmd){


	if( inPhase != xplm_CommandBegin ) {
		return 0; //FIXME: what's the correct retval for a cmd handler
	}



	if( 1 == _mcp_state->_dref_mcp_override->_int_value ){
		//we can ignore all the buttons!
		return 0;
	}



	// Use the command string to find the action function in a std::map.

	std::map<std::string, GF_action_func>::iterator it = _action_map.find( cmd->_name );

	if( it != _action_map.end() ){

		// deref to actual type for no reason other than clarity of purpose.
		GF_action_func f = it->second;
		f( _mcp_state );

	}else{

		char caTmp[1024];
		snprintf( caTmp, 1024, "Undefined action for cmd string:(%s)\n", cmd->_name.c_str() );
		GFUtils::Log( caTmp );

	}


	return 0;

}




int GFMCPPro_Buttons::_action_btn_speed( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_speed->_int_value ){
		mcp_state->_dref_leds_speed->_int_value = 0;
	}else{
		mcp_state->_dref_leds_speed->_int_value = 1;
	}

	return 0;
}

int GFMCPPro_Buttons::_action_btn_lvl_chg( GFMCPPro_State* mcp_state ){

	if( mcp_state->_dref_leds_lvl_chg->_int_value ){
		mcp_state->_dref_leds_lvl_chg->_int_value = 0;
	}else{
		mcp_state->_dref_leds_lvl_chg->_int_value = 1;
	}
	
	return 0;
}

int GFMCPPro_Buttons::_action_btn_hdg_sel( GFMCPPro_State* mcp_state ){
	
	if( mcp_state->_dref_leds_hdg_sel->_int_value ){
		mcp_state->_dref_leds_hdg_sel->_int_value = 0;
	}else{
		mcp_state->_dref_leds_hdg_sel->_int_value = 1;
	}
	
	return 0;
}

int GFMCPPro_Buttons::_action_btn_app( GFMCPPro_State* mcp_state ){
	
	if( mcp_state->_dref_leds_app->_int_value ){
		mcp_state->_dref_leds_app->_int_value = 0;
	}else{
		mcp_state->_dref_leds_app->_int_value = 1;
	}
	
	return 0;
}




int GFMCPPro_Buttons::_action_btn_alt_hld( GFMCPPro_State* mcp_state ){
	
	if( mcp_state->_dref_leds_alt_hld->_int_value ){
		mcp_state->_dref_leds_alt_hld->_int_value = 0;
	}else{
		mcp_state->_dref_leds_alt_hld->_int_value = 1;
	}
	
	return 0;
}




int GFMCPPro_Buttons::_action_btn_vs( GFMCPPro_State* mcp_state ){
	
	if( mcp_state->_dref_leds_vs->_int_value ){
		mcp_state->_dref_leds_vs->_int_value = 0;
	}else{
		mcp_state->_dref_leds_vs->_int_value = 1;
	}
	
	return 0;
}



int GFMCPPro_Buttons::_action_btn_ap_disengage( GFMCPPro_State* mcp_state ){

	/*
	if( mcp_state->_dref_leds_ap_disengage->_int_value ){
		mcp_state->_dref_leds_ap_disengage->_int_value = 0;
	}else{
		mcp_state->_dref_leds_ap_disengage->_int_value = 1;
	}
	*/

	//FIXME: trigger built in xp ap dis command ?

	return 0;
}



int GFMCPPro_Buttons::_action_btn_fd_right( GFMCPPro_State* mcp_state ){
	
	if( mcp_state->_dref_leds_fd_right->_int_value ){
		mcp_state->_dref_leds_fd_right->_int_value = 0;
	}else{
		mcp_state->_dref_leds_fd_right->_int_value = 1;
	}
	
	return 0;
}




int GFMCPPro_Buttons::_action_btn_alt_inv( GFMCPPro_State* mcp_state ){

	/*
	if( mcp_state->_dref_leds_alt_inv->_int_value ){
		mcp_state->_dref_leds_alt_inv->_int_value = 0;
	}else{
		mcp_state->_dref_leds_alt_inv->_int_value = 1;
	}
	 */

	//FIXME: clarify purpose of alt inv button
	//cam: "It does not have an LED. It's a small red button. I think it's NG specific"

	/*
	[11/05/2016 12:39:09 pm] Cameron: http://www.flaps2approach.com/journal/2013/2/20/speed-altitude-intervention-spd-intv-alt-intv-v-nav-how-to-u.html
[11/05/2016 12:39:40 pm] Cameron: Engaging speed intervention you will immediately observe that the MCP speed window becomes active iand displays your current speed.  Dial in into the speed window the new speed requirement of 280 kias.  Notice on the PFD that the speed indicator value above the speed tape has changed from 300 kias to the new speed of 280 kias.  If you cross check with the cruise altitude (INDEX/PERF INT/CRZ ALT) in the CDU it will still indicate the cruise speed of 300 kias.
[11/05/2016 12:40:23 pm] Cameron: ALT INTV is even more fun
[11/05/2016 12:40:24 pm] Cameron: http://www.flaps2approach.com/storage/post-images/2013-posts/altitude-speed-intervention/alpha.jpg?__SQUARESPACE_CACHEVERSION=1361007752444
[11/05/2016 12:40:50 pm] Cameron: Anyways, that's basically up to a developer of an aircraft to code logic for
	 */

	return 0;
}


int GFMCPPro_Buttons::_action_btn_cws_a( GFMCPPro_State* mcp_state ){
	
	if( mcp_state->_dref_leds_cws_a->_int_value ){
		mcp_state->_dref_leds_cws_a->_int_value = 0;
	}else{
		mcp_state->_dref_leds_cws_a->_int_value = 1;
	}
	
	return 0;
}


int GFMCPPro_Buttons::_action_btn_cws_b( GFMCPPro_State* mcp_state ){
	
	if( mcp_state->_dref_leds_cws_b->_int_value ){
		mcp_state->_dref_leds_cws_b->_int_value = 0;
	}else{
		mcp_state->_dref_leds_cws_b->_int_value = 1;
	}
	
	return 0;
}



int GFMCPPro_Buttons::_action_btn_fd_left( GFMCPPro_State* mcp_state ){
	
	if( mcp_state->_dref_leds_fd_left->_int_value ){
		mcp_state->_dref_leds_fd_left->_int_value = 0;
	}else{
		mcp_state->_dref_leds_fd_left->_int_value = 1;
	}
	
	return 0;
}



int GFMCPPro_Buttons::_action_btn_n1( GFMCPPro_State* mcp_state ){
	
	if( mcp_state->_dref_leds_n1->_int_value ){
		mcp_state->_dref_leds_n1->_int_value = 0;
	}else{
		mcp_state->_dref_leds_n1->_int_value = 1;
	}
	
	return 0;
}




int GFMCPPro_Buttons::_action_btn_vnav( GFMCPPro_State* mcp_state ){
	
	if( mcp_state->_dref_leds_vnav->_int_value ){
		mcp_state->_dref_leds_vnav->_int_value = 0;
	}else{
		mcp_state->_dref_leds_vnav->_int_value = 1;
	}
	
	return 0;
}





int GFMCPPro_Buttons::_action_btn_lnav( GFMCPPro_State* mcp_state ){
	
	if( mcp_state->_dref_leds_lnav->_int_value ){
		mcp_state->_dref_leds_lnav->_int_value = 0;
	}else{
		mcp_state->_dref_leds_lnav->_int_value = 1;
	}
	
	return 0;
}





int GFMCPPro_Buttons::_action_btn_cmd_a( GFMCPPro_State* mcp_state ){
	
	if( mcp_state->_dref_leds_cmd_a->_int_value ){
		mcp_state->_dref_leds_cmd_a->_int_value = 0;
	}else{
		mcp_state->_dref_leds_cmd_a->_int_value = 1;
	}
	
	return 0;
}


int GFMCPPro_Buttons::_action_btn_cmd_b( GFMCPPro_State* mcp_state ){
	
	if( mcp_state->_dref_leds_cmd_b->_int_value ){
		mcp_state->_dref_leds_cmd_b->_int_value = 0;
	}else{
		mcp_state->_dref_leds_cmd_b->_int_value = 1;
	}
	
	return 0;
}





int GFMCPPro_Buttons::_action_btn_at_arm( GFMCPPro_State* mcp_state ){
	
	if( mcp_state->_dref_leds_at_arm->_int_value ){
		mcp_state->_dref_leds_at_arm->_int_value = 0;
	}else{
		mcp_state->_dref_leds_at_arm->_int_value = 1;
	}
	
	return 0;
}




int GFMCPPro_Buttons::_action_btn_co( GFMCPPro_State* mcp_state ){
	
	/*
	if( mcp_state->_dref_leds_co->_int_value ){
		mcp_state->_dref_leds_co->_int_value = 0;
	}else{
		mcp_state->_dref_leds_co->_int_value = 1;
	}
	 */

	//FIXME: clarify purpose of CO button
	//switch between IAS and Mach
	
	return 0;
}







int GFMCPPro_Buttons::_action_btn_spd_intv( GFMCPPro_State* mcp_state ){

	/*
	if( mcp_state->_dref_leds_spd_intv->_int_value ){
		mcp_state->_dref_leds_spd_intv->_int_value = 0;
	}else{
		mcp_state->_dref_leds_spd_intv->_int_value = 1;
	}
	*/

	//FIXME: see alt intv

	return 0;
}






int GFMCPPro_Buttons::_action_btn_vor_loc( GFMCPPro_State* mcp_state ){
	
	if( mcp_state->_dref_leds_vor_loc->_int_value ){
		mcp_state->_dref_leds_vor_loc->_int_value = 0;
	}else{
		mcp_state->_dref_leds_vor_loc->_int_value = 1;
	}
	
	return 0;
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















void GFMCPPro_Buttons::_read_usb() {

	if( 0 == _handle ){
		GFUtils::Log("USB Read Failed: Invalid device handle.\n");
		return;
	}

    const int buf_size=16;
    unsigned char buf[buf_size];
	//unsigned char* buf = (unsigned char*)calloc( buf_size, 1 );

	memset(buf, 0, buf_size);


	// Read hardware state
	int res = hid_read( _handle, buf, buf_size);
    if (res < 0) {
		GFUtils::Log("USB Read Failed.\n");

    } else {

        //_dump_button_packet( res, buf );
        _proc_hid_packet( res, buf );

    } //checking for packet read


	//free( buf );

} // read_usb()



void GFMCPPro_Buttons::_proc_hid_packet( int res, unsigned char* buf ) {

	// All knob events come through on channels 1,2,3.
	if( buf[1] || buf[2] || buf[3] ){
		// ------------------ Knobs ----------------
		_proc_knobs( res, buf );

	}else{
		// ------------------ Buttons ----------------
		_proc_buttons( res, buf );

	}

}


void GFMCPPro_Buttons::_proc_knobs( int res, unsigned char* buf ) {

	// Channel
	// packet, value

	// Packet 1
	// --------------------
	// HDG
	buf[1] & 14 ? _btn_heading_inc->Begin()         : _btn_heading_inc->Stop();
	buf[1] & 1 ? _btn_heading_dec->Begin()          : _btn_heading_dec->Stop();
	// CRS Left
	buf[1] & 224 ? _btn_crs_left_inc->Begin()       : _btn_crs_left_inc->Stop();
	buf[1] & 16 ? _btn_crs_left_dec->Begin()        : _btn_crs_left_dec->Stop();

	// Packet 2
	// --------------------
	// VS
	buf[2] & 14 ? _btn_vert_speed_inc->Begin()         : _btn_vert_speed_inc->Stop();
	buf[2] & 1 ? _btn_vert_speed_dec->Begin()          : _btn_vert_speed_dec->Stop();
	// IAS
	buf[2] & 224 ? _btn_ias_mach_inc->Begin()           : _btn_ias_mach_inc->Stop();
	buf[2] & 16 ? _btn_ias_mach_dec->Begin()            : _btn_ias_mach_dec->Stop();

	// Packet 3
	// --------------------
	// CRS Right
	buf[3] & 14 ? _btn_crs_right_inc->Begin()         : _btn_crs_right_inc->Stop();
	buf[3] & 1 ? _btn_crs_right_dec->Begin()          : _btn_crs_right_dec->Stop();
	// ALT
	buf[3] & 224 ? _btn_altitude_inc->Begin()         : _btn_altitude_inc->Stop();
	buf[3] & 16 ? _btn_altitude_dec->Begin()          : _btn_altitude_dec->Stop();

}



void GFMCPPro_Buttons::_proc_buttons( int res, unsigned char* buf ){

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
        printf("% 4d    ", buf[i]);
    }
    //if a report has been rxd and dumped, we should put a new line
    if (res > 0) {
        printf("\n");
    }

}



// eof
