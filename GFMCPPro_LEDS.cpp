//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_LEDS.h"


GFMCPPro_LEDS::GFMCPPro_LEDS() {

    // Create datarefs..

    _dref_leds_vnav         = XPDataref( (char*)GFMCPPro_LEDS::label_vnav  );
    _dref_leds_lnav         = XPDataref( (char*)GFMCPPro_LEDS::label_lnav );
    _dref_leds_ap_cmd_a     = XPDataref( (char*)GFMCPPro_LEDS::label_ap_cmd_a );
    _dref_leds_ap_cmd_b     = XPDataref( (char*)GFMCPPro_LEDS::label_ap_cmd_b );
    _dref_leds_at_arm       = XPDataref( (char*)GFMCPPro_LEDS::label_at_arm );
    _dref_leds_vor_loc      = XPDataref( (char*)GFMCPPro_LEDS::label_vor_loc );


    _dref_leds_ap_a_cws     = XPDataref( (char*)GFMCPPro_LEDS::label_ap_a_cws  );
    _dref_leds_ap_b_cws     = XPDataref( (char*)GFMCPPro_LEDS::label_ap_b_cws );
    _dref_leds_l_side_fd    = XPDataref( (char*)GFMCPPro_LEDS::label_l_side_fd );
    _dref_leds_n1           = XPDataref( (char*)GFMCPPro_LEDS::label_n1 );


    _dref_leds_speed        = XPDataref( (char*)GFMCPPro_LEDS::label_speed  );
    _dref_leds_lvl_chg      = XPDataref( (char*)GFMCPPro_LEDS::label_lvl_chg );
    _dref_leds_hdg_sel      = XPDataref( (char*)GFMCPPro_LEDS::label_hdg_sel  );
    _dref_leds_app          = XPDataref( (char*)GFMCPPro_LEDS::label_app );
    _dref_leds_alt_hld      = XPDataref( (char*)GFMCPPro_LEDS::label_alt_hld  );
    _dref_leds_vs           = XPDataref( (char*)GFMCPPro_LEDS::label_vs );
    _dref_leds_r_side_fd    = XPDataref( (char*)GFMCPPro_LEDS::label_r_side_fd  );


}









//supposed to generate the LED state flags
unsigned char* GFMCPPro_LEDS::get_led_blob(){

    unsigned char ret[3];
    ret[0] = 1;
    ret[1] = 4;
    ret[2] = 8;

    return ret; //FIXME

};