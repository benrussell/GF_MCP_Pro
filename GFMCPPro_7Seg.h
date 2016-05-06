//
// Created by Ben on 6/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_7SEG_H
#define GF_MCP_PRO_GFMCPPRO_7SEG_H


#include <hidapi.h>


#include "GFDataref.h"

#include "GFUtils.h"



class GFMCPPro_7Seg {
public:
    GFMCPPro_7Seg();
    ~GFMCPPro_7Seg();

    void update();

    // 7 Seg byte arrays.
    GFDataref* _dref_crs_left;
    GFDataref* _dref_ias_mach;
    GFDataref* _dref_heading;
    GFDataref* _dref_altitude;
    GFDataref* _dref_vert_speed;
    GFDataref* _dref_crs_right;


    hid_device* _handle;

private:
    // USB Endpoint Targets
    const unsigned char target_crs_left   = 3;
    const unsigned char target_ias        = 5;
    const unsigned char target_hdg        = 7;
    const unsigned char target_alt        = 9;
    const unsigned char target_vs         = 11;
    const unsigned char target_crs_right  = 13;



    const char* label_crs_left      = "goflight/mcp_pro/7seg/crs_left";
    const char* label_ias_mach      = "goflight/mcp_pro/7seg/ias_mach";
    const char* label_heading       = "goflight/mcp_pro/7seg/heading";
    const char* label_altitude      = "goflight/mcp_pro/7seg/altitude";
    const char* label_vert_speed    = "goflight/mcp_pro/7seg/vert_speed";
    const char* label_crs_right     = "goflight/mcp_pro/7seg/crs_right";




};


#endif //GF_MCP_PRO_GFMCPPRO_7SEG_H
