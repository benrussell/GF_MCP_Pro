//
// Created by Ben on 6/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_BUTTONS_H
#define GF_MCP_PRO_GFMCPPRO_BUTTONS_H


#include <hidapi.h>

#include "GFCommand.h"




class GFMCPPro_Buttons {
public:

    GFMCPPro_Buttons();


    // ---- Buttons and Switches ----
    // Packet 5
    GFCommand _btn_Speed;
    GFCommand _btn_LVL_CHG;
    GFCommand _btn_HDG_SEL;
    GFCommand _btn_APP;
    GFCommand _btn_ALT_HLD;
    GFCommand _btn_VS;
    GFCommand _btn_AP_Disengage;
    GFCommand _btn_FD_Right;

    // Packet 6
    GFCommand _btn_ALT_INV;
    GFCommand _btn_CWS_A;
    GFCommand _btn_CWS_B;
    GFCommand _btn_IAS_Dial;
    GFCommand _btn_HDG_Dial;
    GFCommand _btn_ALT_Dial;
    GFCommand _btn_FD_Left;
    GFCommand _btn_N1;

    // Packet 7
    GFCommand _btn_VNAV;
    GFCommand _btn_LNAV;
    GFCommand _btn_CMD_A;
    GFCommand _btn_CMD_B;
    GFCommand _btn_AT_Arm;
    GFCommand _btn_CO;
    GFCommand _btn_SPD_INTV;
    GFCommand _btn_VOR_LOC;



    // ---- Scroll Wheels and Rotaries ----
    GFCommand _btn_crs_left_inc;
    GFCommand _btn_crs_left_dec;

    GFCommand _btn_ias_mach_inc;
    GFCommand _btn_ias_mach_dec;

    GFCommand _btn_heading_inc;
    GFCommand _btn_heading_dec;

    GFCommand _btn_altitude_inc;
    GFCommand _btn_altitude_dec;

    GFCommand _btn_vert_speed_inc;
    GFCommand _btn_vert_speed_dec;

    GFCommand _btn_crs_right_inc;
    GFCommand _btn_crs_right_dec;
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
