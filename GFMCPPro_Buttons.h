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


    void update();

    hid_device* _handle;


private:

    void _read_usb();

    void _proc_button_packet( int res, unsigned char* buf );

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
