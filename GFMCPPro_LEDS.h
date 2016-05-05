//
// Created by Ben on 6/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_LEDS_H
#define GF_MCP_PRO_GFMCPPRO_LEDS_H


#include "XPDataref.h"


class GFMCPPro_LEDS {

private:
    //dataref names
    const char* label_vnav = "goflight/mcp_pro/leds/vnav";
    const char* label_lnav = "goflight/mcp_pro/leds/lnav";
    const char* label_ap_cmd_a = "goflight/mcp_pro/leds/ap_cmd_a";
    const char* label_ap_cmd_b = "goflight/mcp_pro/leds/ap_cmd_b";
    const char* label_at_arm = "goflight/mcp_pro/leds/at_arm";
    const char* label_vor_loc = "goflight/mcp_pro/leds/vor_loc";




public:
    GFMCPPro_LEDS();


    void _init_led_flags();


    //get blob for export to hware unit
    unsigned char* get_led_blob();




    //LED top row
    XPDataref _dref_leds_vnav;
    XPDataref _dref_leds_lnav;
    XPDataref _dref_leds_ap_cmd_a;
    XPDataref _dref_leds_ap_cmd_b;
    XPDataref _dref_leds_at_arm;
    //?
    //?
    XPDataref _dref_leds_vor_loc;




    XPDataref _dref_leds_ap_a_cws;
    XPDataref _dref_leds_ap_b_cws;
    XPDataref _dref_leds_l_side_fd;
    XPDataref _dref_leds_n1;

    //LED mid row
    //?
    int _led_ap_a_cws;
    int _led_ap_b_cws;
    //?
    //?
    //?
    int _led_l_side_fd;
    int _led_n1;



    XPDataref _dref_leds_speed;
    XPDataref _dref_leds_lvl_chg;
    XPDataref _dref_leds_hdg_sel;
    XPDataref _dref_leds_app;
    XPDataref _dref_leds_alt_hld;
    XPDataref _dref_leds_vs;
    XPDataref _dref_leds_r_side_fd;

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
