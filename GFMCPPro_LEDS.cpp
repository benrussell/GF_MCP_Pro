//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_LEDS.h"


GFMCPPro_LEDS::GFMCPPro_LEDS() {

    // Create datarefs..

    _dref_leds_vnav = XPDataref( (char*)GFMCPPro_LEDS::label_vnav  );
    _dref_leds_lnav = XPDataref( (char*)GFMCPPro_LEDS::label_lnav );
    _dref_leds_ap_cmd_a = XPDataref( (char*)GFMCPPro_LEDS::label_ap_cmd_a );
    _dref_leds_ap_cmd_b = XPDataref( (char*)GFMCPPro_LEDS::label_ap_cmd_b );
    _dref_leds_at_arm = XPDataref( (char*)GFMCPPro_LEDS::label_at_arm );
    _dref_leds_vor_loc = XPDataref( (char*)GFMCPPro_LEDS::label_vor_loc );


    _led_ap_a_cws = 0;
    _led_ap_b_cws = 0;
    _led_l_side_fd = 0;
    _led_n1 = 0;


    _led_speed = 0;
    _led_lvl_chg = 0;
    _led_hdg_sel = 0;
    _led_app = 0;
    _led_alt_hld = 0;
    _led_vs = 0;
    _led_r_side_fd = 0;


}









//supposed to generate the LED state flags
unsigned char* GFMCPPro_LEDS::get_led_blob(){

    unsigned char ret[3];
    ret[0] = 1;
    ret[1] = 4;
    ret[2] = 8;

    return ret; //FIXME

};