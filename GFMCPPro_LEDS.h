//
// Created by Ben on 6/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_LEDS_H
#define GF_MCP_PRO_GFMCPPRO_LEDS_H


#include "XPDataref.h"


class GFMCPPro_LEDS {

public:
    GFMCPPro_LEDS();


    XPDataref _dref_leds_vnav;
    XPDataref _dref_leds_lnav;
    XPDataref _dref_leds_ap_cmd_a;
    XPDataref _dref_leds_ap_cmd_b;
    XPDataref _dref_leds_at_arm;
    XPDataref _dref_leds_vor_loc;



    void _init_led_flags();

    unsigned char* get_led_blob();

    //LED top row
    int _led_vnav;
    int _led_lnav;
    int _led_ap_cmd_a;
    int _led_ap_cmd_b;
    int _led_at_arm;
    //?
    //?
    int _led_vor_loc;


    //LED mid row
    //?
    int _led_ap_a_cws;
    int _led_ap_b_cws;
    //?
    //?
    //?
    int _led_l_side_fd;
    int _led_n1;


    //LED bottom row
    int _led_speed;
    int _led_lvl_chg;
    int _led_hdg_sel;
    int _led_app;
    int _led_alt_hld;
    int _led_vs;
    //?
    int _led_r_side_fd;


};


#endif //GF_MCP_PRO_GFMCPPRO_LEDS_H
