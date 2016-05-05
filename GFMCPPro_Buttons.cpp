//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_Buttons.h"

const char* crs_left_inc = "goflight/mcp_pro/crs_left_inc";

const char* label_no_description = "No description.";

GFMCPPro_Buttons::GFMCPPro_Buttons(){
    // Create commands..
    // Need both ..._inc and ..._dec versions of thes

    _cmd_crs_left_inc = XPCommand( (char*)crs_left_inc, (char*)label_no_description );
    _cmd_crs_left_dec = XPCommand("goflight/mcp_pro/crs_left_dec", (char*)label_no_description );

    _cmd_ias_mach_inc = XPCommand("goflight/mcp_pro/ias_mach_inc", (char*)label_no_description );
    _cmd_ias_mach_dec = XPCommand("goflight/mcp_pro/ias_mach_dec", (char*)label_no_description );

    _cmd_heading_inc = XPCommand("goflight/mcp_pro/heading_inc", (char*)label_no_description );
    _cmd_heading_dec = XPCommand("goflight/mcp_pro/heading_dec", (char*)label_no_description );

    _cmd_altitude_inc = XPCommand("goflight/mcp_pro/altitude_inc", (char*)label_no_description );
    _cmd_altitude_dec = XPCommand("goflight/mcp_pro/altitude_dec", (char*)label_no_description );

    _cmd_vert_speed_inc = XPCommand("goflight/mcp_pro/vert_speed_inc", (char*)label_no_description );
    _cmd_vert_speed_dec = XPCommand("goflight/mcp_pro/vert_speed_dec", (char*)label_no_description );

    _cmd_crs_right_inc = XPCommand("goflight/mcp_pro/crs_right_inc", (char*)label_no_description );
    _cmd_crs_right_dec = XPCommand(  "goflight/mcp_pro/crs_right_dec", (char*)label_no_description );

}