//
// Created by Ben on 5/05/2016.
//

#include "GFMCPPro.h"

#include <XPLMUtilities.h>

#include <string.h>

#include <hidapi.h>



#include "XPDataref.h"
#include "XPCommand.h"





GFMCPPro::GFMCPPro() {

    this->_open_usb_dev();



    this->_init_led_flags();

    this->_create_xp_datarefs();

    this->_create_xp_commands();





}



void GFMCPPro::_init_led_flags() {

    _led_vnav = 0;
    _led_lnav = 0;
    _led_ap_cmd_a = 0;
    _led_ap_cmd_b = 0;
    _led_at_arm = 0;
    _led_vor_loc = 0;

    _led_ap_a_cws = 0;
    _led_ap_b_cws = 0;
    _led_l_side_fd = 0;
    _led_n1 = 0;

    _led_speed = 0;
    _led_lvl_chg = 0;
    _led_hdg_sel = 0;
    _led_app = 0;
    _led_alt_hld = 0;
    _led_vs = 0;
    _led_r_side_fd = 0;

}




void GFMCPPro::_create_xp_datarefs() {
    // Create datarefs..
    
     XPDataref("goflight/mcp_pro/leds/vnav");
     XPDataref("goflight/mcp_pro/leds/lnav");
     XPDataref("goflight/mcp_pro/leds/ap_cmd_a");
     XPDataref("goflight/mcp_pro/leds/ap_cmd_b");
     XPDataref("goflight/mcp_pro/leds/at_arm");
     XPDataref("goflight/mcp_pro/leds/vor_loc");

     /*
     XPDataref("goflight/mcp_pro/7seg/crs_left[3]");
     XPDataref("goflight/mcp_pro/7seg/ias_mach[5]");
     XPDataref("goflight/mcp_pro/7seg/heading[3]");
     XPDataref("goflight/mcp_pro/7seg/altitude[5]");
     XPDataref("goflight/mcp_pro/7seg/vert_speed[5]");
     XPDataref("goflight/mcp_pro/7seg/crs_right[3]");
     */
}




void GFMCPPro::_create_xp_commands() {

    // Create commands..
    // Need both ..._inc and ..._dec versions of thes

    _cmd_crs_left_inc = XPCommand("goflight/mcp_pro/crs_left_inc");
    _cmd_crs_left_dec = XPCommand("goflight/mcp_pro/crs_left_dec");

    _cmd_ias_mach_inc = XPCommand("goflight/mcp_pro/ias_mach_inc");
    _cmd_ias_mach_dec = XPCommand("goflight/mcp_pro/ias_mach_dec");

    _cmd_heading_inc = XPCommand("goflight/mcp_pro/heading_inc");
    _cmd_heading_dec = XPCommand("goflight/mcp_pro/heading_dec");

    _cmd_altitude_inc = XPCommand("goflight/mcp_pro/altitude_inc");
    _cmd_altitude_dec = XPCommand("goflight/mcp_pro/altitude_dec");

    _cmd_vert_speed_inc = XPCommand("goflight/mcp_pro/vert_speed_inc");
    _cmd_vert_speed_dec = XPCommand("goflight/mcp_pro/vert_speed_dec");

    _cmd_crs_right_inc = XPCommand("goflight/mcp_pro/crs_right_inc");
    _cmd_crs_right_dec = XPCommand("goflight/mcp_pro/crs_right_dec");

}




int GFMCPPro::_open_usb_dev() {

    int res; //ops results.


    hid_device *handle = hid_open( USB_GOFLIGHT, USB_GOFLIGHT__MCP_PRO, NULL );
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
