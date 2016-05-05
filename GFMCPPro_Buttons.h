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




};


#endif //GF_MCP_PRO_GFMCPPRO_BUTTONS_H
