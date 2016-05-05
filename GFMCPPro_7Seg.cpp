//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_7Seg.h"


GFMCPPro_7Seg::GFMCPPro_7Seg(){

    _dref_crs_left      = XPDataref( (char*)GFMCPPro_7Seg::label_crs_left,   3);
    _dref_ias_mach      = XPDataref( (char*)GFMCPPro_7Seg::label_ias_mach,   5);
    _dref_heading       = XPDataref( (char*)GFMCPPro_7Seg::label_heading,    3);
    _dref_altitude      = XPDataref( (char*)GFMCPPro_7Seg::label_altitude,   5);
    _dref_vert_speed    = XPDataref( (char*)GFMCPPro_7Seg::label_vert_speed, 5);
    _dref_crs_right     = XPDataref( (char*)GFMCPPro_7Seg::label_crs_right,  3);

}



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