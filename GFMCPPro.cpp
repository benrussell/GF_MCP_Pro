//
// Created by Ben on 5/05/2016.
//

#include "GFMCPPro.h"

#include <XPLMUtilities.h>

#include <string.h>


#include "XPDataref.h"
#include "XPCommand.h"




GFMCPPro::GFMCPPro() {

    _gf_mcp_pro_buttons = new GFMCPPro_Buttons();

    _gf_mcp_pro_leds = new GFMCPPro_LEDS();
    _gf_mcp_pro_7seg = new GFMCPPro_7Seg();

}



GFMCPPro::~GFMCPPro() {

    delete( _gf_mcp_pro_buttons );

    delete( _gf_mcp_pro_leds );
    delete( _gf_mcp_pro_7seg );

}



void GFMCPPro::Connect() {

    this->_open_usb_dev();

}



void GFMCPPro::Disconnect() {

    this->_close_usb_dev();

}



int GFMCPPro::_close_usb_dev() {

    hid_close( _handle );
    return 0;

}



int GFMCPPro::_open_usb_dev() {

    int res; //ops results.


    _handle = hid_open( USB_GOFLIGHT, USB_GOFLIGHT__MCP_PRO, NULL );
    if( _handle == 0 ){
        XPLMDebugString("GF_MCP_Pro: Device not available.\n");

        return 0;
    }



    // Human ID string data buffers.
    #define MAX_STR 255
    wchar_t wstr[MAX_STR];


    // Read the Manufacturer String
    res = hid_get_manufacturer_string(_handle, wstr, MAX_STR);
    printf("Maker: %ls\n", wstr);

    // Read the Product String
    res = hid_get_product_string(_handle, wstr, MAX_STR);
    printf("Product: %ls\n", wstr);

    // Read the Serial Number String
    res = hid_get_serial_number_string(_handle, wstr, MAX_STR);
    printf("Serial: %ls", wstr);
    printf("\n");




    return 1;

}







void GFMCPPro::flcb() {

    _gf_mcp_pro_buttons->update();

    _gf_mcp_pro_leds->update();

    _gf_mcp_pro_7seg->update();

}


