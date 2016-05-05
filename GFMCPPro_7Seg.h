//
// Created by Ben on 6/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_7SEG_H
#define GF_MCP_PRO_GFMCPPRO_7SEG_H


#include <hidapi.h>


#include "XPDataref.h"

#include "GFUtils.h"



class GFMCPPro_7Seg {
public:
    GFMCPPro_7Seg();
    ~GFMCPPro_7Seg();

    void update();

    // 7 Seg byte arrays.
    XPDataref _dref_crs_left;
    XPDataref _dref_ias_mach;
    XPDataref _dref_heading;
    XPDataref _dref_altitude;
    XPDataref _dref_vert_speed;
    XPDataref _dref_crs_right;


    hid_device* _handle;


    // USB Endpoint Targets
    unsigned char target_crs_left   = 3;
    unsigned char target_ias        = 5;
    unsigned char target_hdg        = 7;
    unsigned char target_alt        = 9;
    unsigned char target_vs         = 11;
    unsigned char target_crs_right  = 13;



    const char* label_crs_left      = "goflight/mcp_pro/7seg/crs_left";
    const char* label_ias_mach      = "goflight/mcp_pro/7seg/ias_mach";
    const char* label_heading       = "goflight/mcp_pro/7seg/heading";
    const char* label_altitude      = "goflight/mcp_pro/7seg/altitude";
    const char* label_vert_speed    = "goflight/mcp_pro/7seg/vert_speed";
    const char* label_crs_right     = "goflight/mcp_pro/7seg/crs_right";




};


#endif //GF_MCP_PRO_GFMCPPRO_7SEG_H
