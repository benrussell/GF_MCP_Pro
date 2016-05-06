//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_Buttons.h"


#include <hidapi.h>



const char* crs_left_inc = "goflight/mcp_pro/crs_left_inc";

const char* label_no_description = "No description.";




GFMCPPro_Buttons::GFMCPPro_Buttons(){
    // Create commands..
    // Need both ..._inc and ..._dec versions of thes

    _cmd_crs_left_inc = XPCommand( (char*)GFMCPPro_Buttons::label_crs_left_inc, (char*)label_no_description );
    _cmd_crs_left_dec = XPCommand( (char*)GFMCPPro_Buttons::label_crs_left_dec, (char*)label_no_description );

    _cmd_ias_mach_inc = XPCommand( (char*)GFMCPPro_Buttons::label_ias_mach_inc, (char*)label_no_description );
    _cmd_ias_mach_dec = XPCommand( (char*)GFMCPPro_Buttons::label_ias_mach_dec, (char*)label_no_description );

    _cmd_heading_inc = XPCommand( (char*)GFMCPPro_Buttons::label_heading_inc, (char*)label_no_description );
    _cmd_heading_dec = XPCommand( (char*)GFMCPPro_Buttons::label_heading_dec, (char*)label_no_description );

    _cmd_altitude_inc = XPCommand( (char*)GFMCPPro_Buttons::label_altitude_inc, (char*)label_no_description );
    _cmd_altitude_dec = XPCommand( (char*)GFMCPPro_Buttons::label_altitude_dec, (char*)label_no_description );

    _cmd_vert_speed_inc = XPCommand( (char*)GFMCPPro_Buttons::label_vert_speed_inc, (char*)label_no_description );
    _cmd_vert_speed_dec = XPCommand( (char*)GFMCPPro_Buttons::label_vert_speed_dec, (char*)label_no_description );

    _cmd_crs_right_inc = XPCommand( (char*)GFMCPPro_Buttons::label_crs_right_inc, (char*)label_no_description );
    _cmd_crs_right_dec = XPCommand( (char*)GFMCPPro_Buttons::label_crs_right_dec, (char*)label_no_description );

}




void GFMCPPro_Buttons::update() {

    _read_usb();

}




void GFMCPPro_Buttons::_read_usb() {

    const int buf_size=16;
    unsigned char buf[buf_size];

    int res;


    memset(buf, 0, buf_size);

    // Read requested state
    res = hid_read( _handle, buf, buf_size);
    if (res < 0) {
        XPLMDebugString("GF MCP Pro: USB Read Failed.\n");

    } else {

        _dump_button_packet( res, buf );
        _proc_button_packet( res, buf );

    } //checking for packet read

} // read_usb()




void GFMCPPro_Buttons::_proc_button_packet( int res, unsigned char* buf ){

    //parse for CRS_RIGHT knob
    if (buf[3] == 1 || buf[3] == 2) {
        //hdg++;

    } else if (buf[3] == 14 || buf[3] == 15) {
        //hdg--;

    }


    /*

//VNAV button pressed
    if (buf[7] && 1) {
//turn VNAV led ON

        if (flag_vnav) {
//turn off
            flag_vnav = 0;
        } else {
//turn on
            flag_vnav = 1;
        }


    }

*/


}



void GFMCPPro_Buttons::_dump_button_packet( int res, unsigned char* buf ){

    // Print out the returned buffer.
    for (int i = 0; i < res; i++) {
        printf("% 4d    ", buf[i]);
    }
    //if a report has been rxd and dumped, we should put a new line
    if (res > 0) {
        printf("\n");
    }

}






// eof
