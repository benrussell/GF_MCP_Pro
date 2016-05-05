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




void GFMCPPro_Buttons::update() {


    unsigned char *buf;
    int buf_size=16;
    int res;
    int hdg;



    memset(buf, 0, buf_size);

// Read requested state
    res = hid_read( _handle, buf, 16);
    if (res < 0) {
        printf("Unable to read()\n");

    } else {

// Print out the returned buffer.
        for (int i = 0; i < res; i++) {
            printf("% 4d    ", buf[i]);
//printf("%d  % 4d    ", i, buf[i]);

        }

        if (res > 0) {
//a report has been rxd and dumped, we should put a new line
            printf("\n");
        }


//parse the report fields.


//parse for CRS_RIGHT knob
        if (buf[3] == 1 || buf[3] == 2) {
            hdg++;

        } else if (buf[3] == 14 || buf[3] == 15) {
            hdg--;

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



    } //checking for packet read






}