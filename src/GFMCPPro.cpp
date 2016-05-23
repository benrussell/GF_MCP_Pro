//
// Created by Ben on 5/05/2016.
//

#include "GFMCPPro.h"

//#include <XPLMUtilities.h>


#include "Windows_snprintf.h"



GFMCPPro::GFMCPPro() {

	_handle = 0; //init GFMCPPro

	_mcp_state = new GFMCPPro_State();

	#if  LIGHT_TEST_ENABLE
	_tmr_LightTest = new GFTimer_LightTest( _mcp_state );
	#endif //  LIGHT_TEST_ENABLE

	_mcp_leds = new GFMCPPro_LEDS( _mcp_state );
	_mcp_7seg = new GFMCPPro_7Seg( _mcp_state );
    _mcp_buttons = new GFMCPPro_Buttons( _mcp_state );

	_create_xp_root_menu();

}



GFMCPPro::~GFMCPPro() {

    delete( _mcp_buttons );
    delete( _mcp_7seg );
	delete( _mcp_leds );

	#if  LIGHT_TEST_ENABLE
	delete( _tmr_LightTest );
	#endif //  LIGHT_TEST_ENABLE

	delete( _mcp_state );

}



void GFMCPPro::Connect() {

	GFUtils::Log("Connecting to USB device..\n");
    int res = this->_open_usb_dev();



	if( 0 == res ){
		//open failed.
		GFUtils::Log("Device not available.\n");
		XPLMSpeakString("There was an error connecting to the MCP unit.");

		_mcp_state->_dref_connected->_int_value = 0;

		return;
	}

	GFUtils::Log("Connected.\n");
	_mcp_state->_dref_connected->_int_value = 1;


	#if  LIGHT_TEST_ENABLE
	// Init light test.
	GFUtils::Log("Starting Light-Test..\n");
	_mcp_state->_dref_light_test->_int_value = 1;
	_tmr_LightTest->reset();
	#endif //  LIGHT_TEST_ENABLE


	//update menu item with a check mark
	XPLMCheckMenuItem(
			_mnu_root, //XPLMMenuID
			0, //menu id number
			xplm_Menu_Checked //XPLMMenuCheck * flag state
	);

}



void GFMCPPro::Disconnect() {





	GFUtils::Log("Disconnecting from USB device.\n");
    this->_close_usb_dev();

	_mcp_state->_dref_connected->_int_value = 0;

	//FIXME: Kill light test.

	XPLMCheckMenuItem(
			_mnu_root, //XPLMMenuID
			0, //menu id number
			xplm_Menu_Unchecked //XPLMMenuCheck * flag state
	);

}



int GFMCPPro::_close_usb_dev() {

    hid_close( _handle );
    _handle = 0; //_close_usb_deb()

    return 1;

}



int GFMCPPro::_open_usb_dev() {

    _handle = hid_open( USB_GOFLIGHT, USB_GOFLIGHT__MCP_PRO, NULL ); //_open_usb_dev()
    if( 0 == _handle ){ //check hid_open call response..
        return 0;
    }

	hid_set_nonblocking(_handle, 1);



    // Human ID string data buffers.
    #define MAX_STR 255
    wchar_t wstr[MAX_STR];

	char caTmp[1024];

	int res; //tracks responses from hid read ops below.

    // Read the Manufacturer String
    res = hid_get_manufacturer_string(_handle, wstr, MAX_STR);
    snprintf(caTmp, 1024, "Manufacturer: (%ls)\n", wstr);
	GFUtils::Log( caTmp );

    // Read the Product String
    res = hid_get_product_string(_handle, wstr, MAX_STR);
	snprintf(caTmp, 1024, "Product Name: (%ls)\n", wstr);
	GFUtils::Log( caTmp );

    // Read the Serial Number String
    res = hid_get_serial_number_string(_handle, wstr, MAX_STR);
	snprintf(caTmp, 1024, "    Serial #: (%ls)\n", wstr);
	GFUtils::Log( caTmp );


	//blank statement to mute compiler warning.
	if( res ){}



    return 1;

}



void GFMCPPro::flcb() {


	#if 0
	//debug code:
	//translate managed values into 7seg values...
	//normally handled automatically by _mcp_7seg->write();
	_mcp_7seg->_update_7seg_drefs();
	#endif



	if( 0 == _handle ) { //flcb check handle is valid..
        // disconnected state.
		_mcp_state->_dref_connected->_int_value = 0;

		// check to see if a connection request has been filed.
		if( 1 == _mcp_state->_wants_connection ){
			_mcp_state->_wants_connection = 0;
			this->Connect();
		}

    }else {
		// all state is stored in x-p datarefs.
		// any external state changes are automatically in the dataref storage already.
		// no ops needed to update/interchange.
		_mcp_state->_dref_connected->_int_value = 1;

		#if LIGHT_TEST_ENABLE
		// update the light_test timer
		if( _tmr_LightTest->_enabled ){
			_tmr_LightTest->run();
		}else{
			//FIXME: this flag detection will enforce a timer on any external logic trying to run a light test by taking the flag high.
			// we have effectively disabled any chance of a custom light test period.
			// expose duration of light test via dataref?
			if( 1 == _mcp_state->_dref_light_test->_int_value ){
				//this only runs if we're currently disabled.
				//it will enable us so we do not run this branch again.
				_tmr_LightTest->reset();
			}
		}
		#endif //  LIGHT_TEST_ENABLE


		//buttons and dials affect state changes, read them in before updating the displays
		_mcp_buttons->read( _handle );

		//all state changes are now effective, push current to hardware.
        _mcp_leds->write( _handle );
        _mcp_7seg->write( _handle );


		// check to see if a disconnection request has been filed.
		if( 1 == _mcp_state->_wants_disconnection ){
			_mcp_state->_wants_disconnection = 0;
			this->Disconnect();
		}

	}

}









void GFMCPPro::_create_xp_root_menu() {

	//GZDebugString("Creating menus..\n");


	_mnu_root = XPLMCreateMenu(
			"GoFlight MCP Pro",
			NULL, //parent menu item - plugins menu
			1, //index value - auto assigned.
			GFMCPPro_menuHandler,
			0
	);



	//id:0
	XPLMAppendMenuItem(
			_mnu_root,
			"Connect",
			(void *) "mnu_connected", //item ref
			1 //force english
	);
		//apply checkmark
		XPLMCheckMenuItem(
				_mnu_root, //XPLMMenuID
				0, //menu id number
				xplm_Menu_Unchecked //XPLMMenuCheck * flag state
		);



	/*
	//id:1
	XPLMAppendMenuItem(
			_mnu_root,
			"blank",
			(void *) "mnu_gf_", //item ref
			1 //force english
	);
	*/


}



void GFMCPPro::menuHandler(
		void *               inMenuRef,
		void *               inItemRef){


	std::string sLabel = std::string( (char*)inItemRef );


	if( sLabel == "mnu_connected" ){

		XPLMMenuCheck current_state = xplm_Menu_Checked;

		XPLMCheckMenuItemState(
				_mnu_root, //XPLMMenuID
				0, //menu id number
				&current_state  //XPLMMenuCheck * flag state
			);


		if( xplm_Menu_Checked == current_state ){
			//disconnect.
			Disconnect();

		}else if( xplm_Menu_Unchecked == current_state ) {
			//connect.
			Connect();

		}


	}



}


// eof
