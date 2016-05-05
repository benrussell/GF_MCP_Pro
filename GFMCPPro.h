//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_H
#define GF_MCP_PRO_GFMCPPRO_H


class GFMCPPro {
public:
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



        return ret;

    };


};


#endif //GF_MCP_PRO_GFMCPPRO_H
