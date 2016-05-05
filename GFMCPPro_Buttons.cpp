//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_Buttons.h"



GFMCPPro_Buttons::GFMCPPro_Buttons(){
    // Create commands..
    // Need both ..._inc and ..._dec versions of thes

    _cmd_crs_left_inc = XPCommand( (char*)crs_left_inc,"" );
    _cmd_crs_left_dec = XPCommand("goflight/mcp_pro/crs_left_dec","");

    _cmd_ias_mach_inc = XPCommand("goflight/mcp_pro/ias_mach_inc","");
    _cmd_ias_mach_dec = XPCommand("goflight/mcp_pro/ias_mach_dec","");

    _cmd_heading_inc = XPCommand("goflight/mcp_pro/heading_inc","");
    _cmd_heading_dec = XPCommand("goflight/mcp_pro/heading_dec","");

    _cmd_altitude_inc = XPCommand("goflight/mcp_pro/altitude_inc","");
    _cmd_altitude_dec = XPCommand("goflight/mcp_pro/altitude_dec","");

    _cmd_vert_speed_inc = XPCommand("goflight/mcp_pro/vert_speed_inc","");
    _cmd_vert_speed_dec = XPCommand("goflight/mcp_pro/vert_speed_dec","");

    _cmd_crs_right_inc = XPCommand("goflight/mcp_pro/crs_right_inc","");
    _cmd_crs_right_dec = XPCommand(  "goflight/mcp_pro/crs_right_dec","");

}