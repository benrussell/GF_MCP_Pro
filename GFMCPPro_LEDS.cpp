//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_LEDS.h"

#include "GFUtils.h"

GFMCPPro_LEDS::GFMCPPro_LEDS( GFMCPPro_State* state ){

	_mcp_state = state;

}



void GFMCPPro_LEDS::write(){

    unsigned char tmp[3];
    _get_led_blob( tmp );

    GFUtils::set_leds( _handle, 15, tmp );


}



//supposed to generate the LED state flags
void GFMCPPro_LEDS::_get_led_blob( unsigned char ret[3] ){

    // bit field reconstruction

    const unsigned char a = 1;
    const unsigned char b = 2;
    const unsigned char c = 4;
    const unsigned char d = 8;
    const unsigned char e = 16;
    const unsigned char f = 32;
    const unsigned char g = 64;
    const unsigned char h = 128;

    //unsigned char btn_a = 0 | b | c | d | e | f | g | h;


    //bottom
    ret[0] = 0;
    //mid
    ret[1] = 0;
    //top
    ret[2] = 0;



    // Construct bit field for bottom row --------------------
    if( _mcp_state->_dref_leds_speed->_int_value )
        ret[0] = ret[0] | a;

    if( _mcp_state->_dref_leds_lvl_chg->_int_value )
        ret[0] = ret[0] | b;

    if( _mcp_state->_dref_leds_hdg_sel->_int_value )
        ret[0] = ret[0] | c;

    if( _mcp_state->_dref_leds_app->_int_value )
        ret[0] = ret[0] | d;

    if( _mcp_state->_dref_leds_alt_hld->_int_value )
        ret[0] = ret[0] | e;

    if( _mcp_state->_dref_leds_vs->_int_value )
        ret[0] = ret[0] | f;

    //blank bit: g

    if( _mcp_state->_dref_leds_r_side_fd->_int_value )
        ret[0] = ret[0] | h;




    // Construct bit field for middle row --------------------
    //blank bit: a

    if( _mcp_state->_dref_leds_ap_a_cws->_int_value )
        ret[1] = ret[1] | b;

    if( _mcp_state->_dref_leds_ap_b_cws->_int_value )
        ret[1] = ret[1] | c;

    //blank bit: d

    //blank bit: e

    //blank bit: f

    if( _mcp_state->_dref_leds_l_side_fd->_int_value )
        ret[1] = ret[1] | g;

    if( _mcp_state->_dref_leds_n1->_int_value )
        ret[1] = ret[1] | h;




    // Construct bit field for top row -----------------------
    //blank bit: a

    if( _mcp_state->_dref_leds_vnav->_int_value )
        ret[2] = ret[2] | a;

    if( _mcp_state->_dref_leds_lnav->_int_value )
        ret[2] = ret[2] | b;

    if( _mcp_state->_dref_leds_ap_cmd_a->_int_value )
        ret[2] = ret[2] | c;

    if( _mcp_state->_dref_leds_ap_cmd_b->_int_value )
        ret[2] = ret[2] | d;

    if( _mcp_state->_dref_leds_at_arm->_int_value )
        ret[2] = ret[2] | e;

    //blank bit: f

    //blank bit: g

    if( _mcp_state->_dref_leds_vor_loc->_int_value )
        ret[2] = ret[2] | h;



};