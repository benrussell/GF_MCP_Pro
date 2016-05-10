//
// Created by Ben on 5/05/2016.
//

#include "GFMCPPro.h"

#include <XPLMUtilities.h>

#include <string.h>




GFMCPPro::GFMCPPro() {

	_mcp_state = new GFMCPPro_State();


	_mcp_leds = new GFMCPPro_LEDS( _mcp_state );

	_mcp_7seg = new GFMCPPro_7Seg( _mcp_state );

    _mcp_buttons = new GFMCPPro_Buttons( _mcp_state );




}



GFMCPPro::~GFMCPPro() {

    delete( _mcp_buttons );
    delete( _mcp_leds );
    delete( _mcp_7seg );

	delete( _mcp_state );


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
    _mcp_buttons->_handle = _handle;
    _mcp_leds->_handle = _handle;
    _mcp_7seg->_handle = _handle;




    // Human ID string data buffers.
    #define MAX_STR 255
    wchar_t wstr[MAX_STR];

	char caTmp[1024];

    // Read the Manufacturer String
    res = hid_get_manufacturer_string(_handle, wstr, MAX_STR);
    snprintf(caTmp, 1024, "GF_MCP_Pro: Maker: (%ls)\n", wstr);
	XPLMDebugString( caTmp );

    // Read the Product String
    res = hid_get_product_string(_handle, wstr, MAX_STR);
	snprintf(caTmp, 1024, "GF_MCP_Pro: Product: (%ls)\n", wstr);
	XPLMDebugString( caTmp );

    // Read the Serial Number String
    res = hid_get_serial_number_string(_handle, wstr, MAX_STR);
	snprintf(caTmp, 1024, "GF_MCP_Pro: Serial: (%ls)\n", wstr);
	XPLMDebugString( caTmp );



    return 1;

}



void GFMCPPro::flcb() {

    if( _handle == NULL ) {
        //_handle is null, ignore!
        //TODO: set dref to 0 to indicate disconnect?

    }else {

		// all state is stored in x-p datarefs.
		// any external state changes are automatically in the dataref storage already.
		// no ops needed to update/interchange.

		//buttons and dials affect state changes, read them in before updating the displays
		_mcp_buttons->read();

		//all state changes are now effective, push current to hardware.
        _mcp_leds->write();
        _mcp_7seg->write();

    }

}


// eof
