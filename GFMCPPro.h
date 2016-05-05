//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_H
#define GF_MCP_PRO_GFMCPPRO_H


// XPlane Utils
#include "XPCommand.h"
#include "XPDataref.h"




// USB ID tags.
#define USB_GOFLIGHT 0x09f3

// Device type
#define USB_GOFLIGHT__MCP_PRO 0x0064



// hid_write channels.
#define MCP_CRS_LEFT 3
#define MCP_IAS 5
#define MCP_HDG 7
#define MCP_ALT 9
#define MCP_VS 11
#define MCP_CRS_RIGHT 13

#define MCP_BTNS 15






class GFMCPPro {
public:

    GFMCPPro();

    int _open_usb_dev();

    void _flcb();


    void _init_led_flags();
    void _create_xp_commands();
    void _create_xp_datarefs();




    XPCommand _cmd_crs_left_inc;
    XPCommand _cmd_crs_left_dec;

    XPCommand _cmd_ias_mach_inc;
    XPCommand _cmd_ias_mach_dec;

    XPCommand _cmd_heading_inc;
    XPCommand _cmd_heading_dec;

    XPCommand _cmd_altitude_inc;
    XPCommand _cmd_altitude_dec;

    XPCommand _cmd_vert_speed_inc;
    XPCommand _cmd_vert_speed_dec;

    XPCommand _cmd_crs_right_inc;
    XPCommand _cmd_crs_right_dec;










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


    unsigned char* get_led_blob(){

        unsigned char ret[3];
        ret[0] = 1;
        ret[1] = 4;
        ret[2] = 8;



        return ret; //FIXME

    };






};


#endif //GF_MCP_PRO_GFMCPPRO_H
