//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_LEDS.h"


GFMCPPro_LEDS::GFMCPPro_LEDS() {

    // Create datarefs..

    // Top Row
    //
    _dref_leds_vnav         = XPDataref( (char*)GFMCPPro_LEDS::label_vnav  );
    _dref_leds_lnav         = XPDataref( (char*)GFMCPPro_LEDS::label_lnav );
    _dref_leds_ap_cmd_a     = XPDataref( (char*)GFMCPPro_LEDS::label_ap_cmd_a );
    _dref_leds_ap_cmd_b     = XPDataref( (char*)GFMCPPro_LEDS::label_ap_cmd_b );
    _dref_leds_at_arm       = XPDataref( (char*)GFMCPPro_LEDS::label_at_arm );
    //
    //
    _dref_leds_vor_loc      = XPDataref( (char*)GFMCPPro_LEDS::label_vor_loc );


    // Mid Row
    //
    _dref_leds_ap_a_cws     = XPDataref( (char*)GFMCPPro_LEDS::label_ap_a_cws  );
    _dref_leds_ap_b_cws     = XPDataref( (char*)GFMCPPro_LEDS::label_ap_b_cws );
    //
    //
    //
    _dref_leds_l_side_fd    = XPDataref( (char*)GFMCPPro_LEDS::label_l_side_fd );
    _dref_leds_n1           = XPDataref( (char*)GFMCPPro_LEDS::label_n1 );


    // Bottom Row
    _dref_leds_speed        = XPDataref( (char*)GFMCPPro_LEDS::label_speed  );
    _dref_leds_lvl_chg      = XPDataref( (char*)GFMCPPro_LEDS::label_lvl_chg );
    _dref_leds_hdg_sel      = XPDataref( (char*)GFMCPPro_LEDS::label_hdg_sel  );
    _dref_leds_app          = XPDataref( (char*)GFMCPPro_LEDS::label_app );
    _dref_leds_alt_hld      = XPDataref( (char*)GFMCPPro_LEDS::label_alt_hld  );
    _dref_leds_vs           = XPDataref( (char*)GFMCPPro_LEDS::label_vs );
    //
    _dref_leds_r_side_fd    = XPDataref( (char*)GFMCPPro_LEDS::label_r_side_fd  );

    

}









//supposed to generate the LED state flags
void GFMCPPro_LEDS::get_led_blob( unsigned char ret[3] ){


    unsigned char a = 1;
    unsigned char b = 2;
    unsigned char c = 4;
    unsigned char d = 8;
    unsigned char e = 16;
    unsigned char f = 32;
    unsigned char g = 64;
    unsigned char h = 128;


    //bottom
    ret[0] = 0;
    //mid
    ret[1] = 0;
    //top
    ret[2] = 0;


    //unsigned char btn_a = 0 | b | c | d | e | f | g | h;


    // Construct bit field for bottom row --------------------
    if( _dref_leds_speed._int_value )
        ret[0] = ret[0] | a;

    if( _dref_leds_lvl_chg._int_value )
        ret[0] = ret[0] | b;

    if( _dref_leds_hdg_sel._int_value )
        ret[0] = ret[0] | c;

    if( _dref_leds_app._int_value )
        ret[0] = ret[0] | d;

    if( _dref_leds_alt_hld._int_value )
        ret[0] = ret[0] | e;

    if( _dref_leds_vs._int_value )
        ret[0] = ret[0] | f;

    //blank bit: g

    if( _dref_leds_r_side_fd._int_value )
        ret[0] = ret[0] | h;




    // Construct bit field for middle row --------------------
    //blank bit: a

    if( _dref_leds_ap_a_cws._int_value )
        ret[1] = ret[1] | b;

    if( _dref_leds_ap_b_cws._int_value )
        ret[1] = ret[1] | c;

    //blank bit: d

    //blank bit: e

    //blank bit: f

    if( _dref_leds_l_side_fd._int_value )
        ret[1] = ret[1] | g;

    if( _dref_leds_n1._int_value )
        ret[1] = ret[1] | h;






};