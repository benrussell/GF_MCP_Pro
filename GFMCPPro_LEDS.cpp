//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_LEDS.h"

#include "GFUtils.h"


GFMCPPro_LEDS::GFMCPPro_LEDS() {

    // Create datarefs..

    // Top Row
    _dref_leds_vnav         = new GFDataref( (char*)GFMCPPro_LEDS::label_vnav  );
    _dref_leds_lnav         = new GFDataref( (char*)GFMCPPro_LEDS::label_lnav );
    _dref_leds_ap_cmd_a     = new GFDataref( (char*)GFMCPPro_LEDS::label_ap_cmd_a );
    _dref_leds_ap_cmd_b     = new GFDataref( (char*)GFMCPPro_LEDS::label_ap_cmd_b );
    _dref_leds_at_arm       = new GFDataref( (char*)GFMCPPro_LEDS::label_at_arm );
    // blank bit
    // blank bit
    _dref_leds_vor_loc      = new GFDataref( (char*)GFMCPPro_LEDS::label_vor_loc );


    // Mid Row
    // blank bit
    _dref_leds_ap_a_cws     = new GFDataref( (char*)GFMCPPro_LEDS::label_ap_a_cws  );
    _dref_leds_ap_b_cws     = new GFDataref( (char*)GFMCPPro_LEDS::label_ap_b_cws );
    // blank bit
    // blank bit
    // blank bit
    _dref_leds_l_side_fd    = new GFDataref( (char*)GFMCPPro_LEDS::label_l_side_fd );
    _dref_leds_n1           = new GFDataref( (char*)GFMCPPro_LEDS::label_n1 );


    // Bottom Row
    _dref_leds_speed        = new GFDataref( (char*)GFMCPPro_LEDS::label_speed  );
    _dref_leds_lvl_chg      = new GFDataref( (char*)GFMCPPro_LEDS::label_lvl_chg );
    _dref_leds_hdg_sel      = new GFDataref( (char*)GFMCPPro_LEDS::label_hdg_sel  );
    _dref_leds_app          = new GFDataref( (char*)GFMCPPro_LEDS::label_app );
    _dref_leds_alt_hld      = new GFDataref( (char*)GFMCPPro_LEDS::label_alt_hld  );
    _dref_leds_vs           = new GFDataref( (char*)GFMCPPro_LEDS::label_vs );
    // blank bit
    _dref_leds_r_side_fd    = new GFDataref( (char*)GFMCPPro_LEDS::label_r_side_fd  );

}






void GFMCPPro_LEDS::update(){

    unsigned char tmp[3];
    this->_get_led_blob( tmp );

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
    if( _dref_leds_speed->_int_value )
        ret[2] = ret[2] | a;

    if( _dref_leds_lvl_chg->_int_value )
        ret[2] = ret[2] | b;

    if( _dref_leds_hdg_sel->_int_value )
        ret[2] = ret[2] | c;

    if( _dref_leds_app->_int_value )
        ret[2] = ret[2] | d;

    if( _dref_leds_alt_hld->_int_value )
        ret[2] = ret[2] | e;

    if( _dref_leds_vs->_int_value )
        ret[2] = ret[2] | f;

    //blank bit: g

    if( _dref_leds_r_side_fd->_int_value )
        ret[2] = ret[2] | h;




    // Construct bit field for middle row --------------------
    //blank bit: a

    if( _dref_leds_ap_a_cws->_int_value )
        ret[1] = ret[1] | b;

    if( _dref_leds_ap_b_cws->_int_value )
        ret[1] = ret[1] | c;

    //blank bit: d

    //blank bit: e

    //blank bit: f

    if( _dref_leds_l_side_fd->_int_value )
        ret[1] = ret[1] | g;

    if( _dref_leds_n1->_int_value )
        ret[1] = ret[1] | h;




    // Construct bit field for top row -----------------------
    //blank bit: a

    if( _dref_leds_vnav->_int_value )
        ret[0] = ret[0] | a;

    if( _dref_leds_lnav->_int_value )
        ret[0] = ret[0] | b;

    if( _dref_leds_ap_cmd_a->_int_value )
        ret[0] = ret[0] | c;

    if( _dref_leds_ap_cmd_b->_int_value )
        ret[0] = ret[0] | d;

    if( _dref_leds_at_arm->_int_value )
        ret[0] = ret[0] | e;

    //blank bit: f

    //blank bit: g

    if( _dref_leds_vor_loc->_int_value )
        ret[0] = ret[0] | h;



};