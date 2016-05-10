//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_7Seg.h"


void GFMCPPro_7Seg::update(){


    unsigned char caTmp[16];


    //CRS Left
    GFUtils::set3f(
            _handle,
            GFMCPPro_7Seg::target_crs_left,
            caTmp
            );


    //IAS Mach
    GFUtils::set5f(
            _handle,
            GFMCPPro_7Seg::target_ias,
            caTmp
    );


    //Heading
    GFUtils::set3f(
            _handle,
            GFMCPPro_7Seg::target_hdg,
            caTmp
    );


    //Altitude
    GFUtils::set5f(
            _handle,
            GFMCPPro_7Seg::target_alt,
            caTmp
    );


    //Vert Speed
    GFUtils::set5f(
            _handle,
            GFMCPPro_7Seg::target_vs,
            caTmp
    );


    //CRS Right
    GFUtils::set3f(
            _handle,
            GFMCPPro_7Seg::target_crs_right,
            caTmp
    );



}