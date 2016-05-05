//
// Created by Ben on 5/05/2016.
//

#include "GFMCPPro.h"

#include <XPLMUtilities.h>

#include <string.h>


#include "XPDataref.h"
#include "XPCommand.h"




GFMCPPro::GFMCPPro() {




}


void GFMCPPro::Connect() {

    this->_open_usb_dev();

}


void GFMCPPro::Disconnect() {

    this->_close_usb_dev();

}




void GFMCPPro::_create_xp_datarefs() {

     /*
     XPDataref("goflight/mcp_pro/7seg/crs_left[3]");
     XPDataref("goflight/mcp_pro/7seg/ias_mach[5]");
     XPDataref("goflight/mcp_pro/7seg/heading[3]");
     XPDataref("goflight/mcp_pro/7seg/altitude[5]");
     XPDataref("goflight/mcp_pro/7seg/vert_speed[5]");
     XPDataref("goflight/mcp_pro/7seg/crs_right[3]");
     */
}





int GFMCPPro::_close_usb_dev() {

    hid_close( handle );

    return 0;

}



int GFMCPPro::_open_usb_dev() {

    int res; //ops results.


    handle = hid_open( USB_GOFLIGHT, USB_GOFLIGHT__MCP_PRO, NULL );
    if( handle == 0 ){
        XPLMDebugString("GF_MCP_Pro: Device not available.\n");

        return 0;
    }





    // Human ID string data buffers.
    #define MAX_STR 255
    wchar_t wstr[MAX_STR];


    // Read the Manufacturer String
    res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
    printf("Maker: %ls\n", wstr);

    // Read the Product String
    res = hid_get_product_string(handle, wstr, MAX_STR);
    printf("Product: %ls\n", wstr);

    // Read the Serial Number String
    res = hid_get_serial_number_string(handle, wstr, MAX_STR);
    printf("Serial: %ls", wstr);
    printf("\n");


    return 1;

}







void GFMCPPro::_flcb() {

#if 0
    char *buf;
    int buf_size;
    int res;
    int handle;
    int hdg;



    memset(buf, 0, buf_size);

// Read requested state
    res = hid_read(handle, buf, 16);
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


    } //checking for packet read
#endif

}


