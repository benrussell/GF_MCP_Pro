//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_LEDS.h"


GFMCPPro_LEDS::GFMCPPro_LEDS() {

    // Create datarefs..

    _dref_leds_vnav = XPDataref("goflight/mcp_pro/leds/vnav");
    _dref_leds_lnav = XPDataref("goflight/mcp_pro/leds/lnav");
    _dref_leds_ap_cmd_a = XPDataref("goflight/mcp_pro/leds/ap_cmd_a");
    _dref_leds_ap_cmd_b = XPDataref("goflight/mcp_pro/leds/ap_cmd_b");
    _dref_leds_at_arm = XPDataref("goflight/mcp_pro/leds/at_arm");
    _dref_leds_vor_loc = XPDataref("goflight/mcp_pro/leds/vor_loc");



}





void GFMCPPro_LEDS::_init_led_flags() {

    _led_vnav = 0;
    _led_lnav = 0;
    _led_ap_cmd_a = 0;
    _led_ap_cmd_b = 0;
    _led_at_arm = 0;
    _led_vor_loc = 0;

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