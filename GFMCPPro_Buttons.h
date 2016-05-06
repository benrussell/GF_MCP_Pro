//
// Created by Ben on 6/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_BUTTONS_H
#define GF_MCP_PRO_GFMCPPRO_BUTTONS_H


#include <hidapi.h>

#include "XPCommand.h"




class GFMCPPro_Buttons {
public:

    GFMCPPro_Buttons();


    // ---- Buttons and Switches ----
    // Packet 5
    XPCommand _btn_Speed;
    XPCommand _btn_LVL_CHG;
    XPCommand _btn_HDG_SEL;
    XPCommand _btn_APP;
    XPCommand _btn_ALT_HLD;
    XPCommand _btn_VS;
    XPCommand _btn_AP_Disengage;
    XPCommand _btn_FD_Right;

    // Packet 6
    XPCommand _btn_ALT_INV;
    XPCommand _btn_CWS_A;
    XPCommand _btn_CWS_B;
    XPCommand _btn_IAS_Dial;
    XPCommand _btn_HDG_Dial;
    XPCommand _btn_ALT_Dial;
    XPCommand _btn_FD_Left;
    XPCommand _btn_N1;

    // Packet 7
    XPCommand _btn_VNAV;
    XPCommand _btn_LNAV;
    XPCommand _btn_CMD_A;
    XPCommand _btn_CMD_B;
    XPCommand _btn_AT_Arm;
    XPCommand _btn_CO;
    XPCommand _btn_SPD_INTV;
    XPCommand _btn_VOR_LOC;



    // ---- Scroll Wheels and Rotaries ----
    XPCommand _btn_crs_left_inc;
    XPCommand _btn_crs_left_dec;

    XPCommand _btn_ias_mach_inc;
    XPCommand _btn_ias_mach_dec;

    XPCommand _btn_heading_inc;
    XPCommand _btn_heading_dec;

    XPCommand _btn_altitude_inc;
    XPCommand _btn_altitude_dec;

    XPCommand _btn_vert_speed_inc;
    XPCommand _btn_vert_speed_dec;

    XPCommand _btn_crs_right_inc;
    XPCommand _btn_crs_right_dec;
    // -----------------------------------




    void update();

    hid_device* _handle;


private:

    void _read_usb();

    void _proc_buttons( int res, unsigned char* buf );

    void _dump_button_packet( int res, unsigned char* buf );








    const char* label_crs_left_inc = "goflight/mcp_pro/emit/crs_left_inc";
    const char* label_crs_left_dec = "goflight/mcp_pro/emit/crs_left_dec";

    const char* label_ias_mach_inc = "goflight/mcp_pro/emit/ias_mach_inc";
    const char* label_ias_mach_dec = "goflight/mcp_pro/emit/ias_mach_dec";

    const char* label_heading_inc = "goflight/mcp_pro/emit/heading_inc";
    const char* label_heading_dec = "goflight/mcp_pro/emit/heading_dec";

    const char* label_altitude_inc = "goflight/mcp_pro/emit/altitude_inc";
    const char* label_altitude_dec = "goflight/mcp_pro/emit/altitude_dec";

    const char* label_vert_speed_inc = "goflight/mcp_pro/emit/vert_speed_inc";
    const char* label_vert_speed_dec = "goflight/mcp_pro/emit/vert_speed_dec";

    const char* label_crs_right_inc = "goflight/mcp_pro/emit/crs_right_inc";
    const char* label_crs_right_dec = "goflight/mcp_pro/emit/crs_right_dec";



};


#endif //GF_MCP_PRO_GFMCPPRO_BUTTONS_H
