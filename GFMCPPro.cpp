//
// Created by Ben on 5/05/2016.
//

#include "GFMCPPro.h"

#include <XPLMUtilities.h>

#include <string.h>




GFMCPPro::GFMCPPro() {

	_gf_mcp_pro_leds = new GFMCPPro_LEDS();

	_gf_mcp_pro_7seg = new GFMCPPro_7Seg();


    _gf_mcp_pro_buttons = new GFMCPPro_Buttons();
	_gf_mcp_pro_buttons->_leds = _gf_mcp_pro_leds;
	_gf_mcp_pro_buttons->_7seg = _gf_mcp_pro_7seg;




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

    _handle = NULL;


    return 0;

}



int GFMCPPro::_open_usb_dev() {

    int res; //ops results.


    _handle = hid_open( USB_GOFLIGHT, USB_GOFLIGHT__MCP_PRO, NULL );
    if( _handle == 0 ){
        XPLMDebugString("GF_MCP_Pro: Device not available.\n");

        return 0;
    }

	XPLMDebugString("GF_MCP_Pro: Connected.\n");

	hid_set_nonblocking(_handle, 1);

    //Push the usb device handle into sub modules so they can write via GFUtils
    _gf_mcp_pro_buttons->_handle = _handle;
    _gf_mcp_pro_leds->_handle = _handle;
    _gf_mcp_pro_7seg->_handle = _handle;




    // Human ID string data buffers.
    #define MAX_STR 255
    wchar_t wstr[MAX_STR];

	char caTmp[1024];

    // Read the Manufacturer String
    res = hid_get_manufacturer_string(_handle, wstr, MAX_STR);
    snprintf(caTmp, 1024, "GF_MCP_Pro: Maker: %ls\n", wstr);
	XPLMDebugString( caTmp );

    // Read the Product String
    res = hid_get_product_string(_handle, wstr, MAX_STR);
	snprintf(caTmp, 1024, "GF_MCP_Pro: Product: %ls\n", wstr);
	XPLMDebugString( caTmp );

    // Read the Serial Number String
    res = hid_get_serial_number_string(_handle, wstr, MAX_STR);
	snprintf(caTmp, 1024, "GF_MCP_Pro: Serial: %ls\n", wstr);
	XPLMDebugString( caTmp );



    return 1;

}



void GFMCPPro::flcb() {

    if( _handle == NULL ) {
        //_handle is null, ignore!
        //TODO: set dref to 0 to indicate disconnect?

    }else {
        _gf_mcp_pro_buttons->update();

        _gf_mcp_pro_leds->update();

        _gf_mcp_pro_7seg->update();

    }

}


// eof
