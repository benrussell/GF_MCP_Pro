//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_7Seg.h"

#include <string.h>

#include "Windows_snprintf.h"


GFMCPPro_7Seg::GFMCPPro_7Seg( GFMCPPro_State* state ){

	_handle = 0;

	_mcp_state = state;

}



void GFMCPPro_7Seg::write(){

	if( 1 == _mcp_state->_dref_mcp_light_test->_int_value ){
		_write_light_test();

	}else{
		if( 0 == _mcp_state->_dref_mcp_override->_int_value ){
			// MCP is NOT in managed mode.
			// We have state stored for the knobs and dials actions.
			// This call will translate that state into char* data to push to the 7seg displays.
			// Next call does not push to MCP, only updates dref blob data.
			_update_7seg_drefs();
		}

		//always push the dref char* blob to the MCP.
		_write_dref_state();
	}

}



//write dataref state to 7 seg LED's
void GFMCPPro_7Seg::_write_dref_state(){

	// Override Mode.
	// Reads back bytes from dataref contents and pushes them to the 7seg displays.

	//CRS Left
	GFUtils::set3f(
			_handle,
			GFMCPPro_7Seg::_usb_report_crs_left,
			_mcp_state->_dref_crs_left->_blob
	);


	//IAS Mach
	GFUtils::set5f(
			_handle,
			GFMCPPro_7Seg::_usb_report_ias,
			_mcp_state->_dref_ias_mach->_blob
	);


	//Heading
	GFUtils::set3f(
			_handle,
			GFMCPPro_7Seg::_usb_report_hdg,
			_mcp_state->_dref_heading->_blob
	);


	//Altitude
	GFUtils::set5f(
			_handle,
			GFMCPPro_7Seg::_usb_report_alt,
			_mcp_state->_dref_altitude->_blob
	);


	//Vert Speed
	GFUtils::set5f(
			_handle,
			GFMCPPro_7Seg::_usb_report_vs,
			_mcp_state->_dref_vert_speed->_blob
	);


	//CRS Right
	GFUtils::set3f(
			_handle,
			GFMCPPro_7Seg::_usb_report_crs_right,
			_mcp_state->_dref_crs_right->_blob
	);

}



//write managed state to the 7seg blob dref's
void GFMCPPro_7Seg::_update_7seg_drefs(){
	
	const size_t max_bytes = (size_t)GFDataref::_blob_size;

	//CRS Left
	snprintf( (char*)_mcp_state->_dref_crs_left->_blob, max_bytes, "%03i", _mcp_state->_dref_crs_left->_int_value );

	//IAS Mach
	snprintf( (char*)_mcp_state->_dref_ias_mach->_blob, max_bytes, "%05i", _mcp_state->_dref_ias_mach->_int_value );

	//Heading
	snprintf( (char*)_mcp_state->_dref_heading->_blob, max_bytes, "%03i", _mcp_state->_dref_heading->_int_value );

	//Altitude
	snprintf( (char*)_mcp_state->_dref_altitude->_blob, max_bytes, "%05i", _mcp_state->_dref_altitude->_int_value );

	//Vert Speed
	snprintf( (char*)_mcp_state->_dref_vert_speed->_blob, max_bytes, "%05i", _mcp_state->_dref_vert_speed->_int_value );

	//CRS Right
	snprintf( (char*)_mcp_state->_dref_crs_right->_blob, max_bytes, "%03i", _mcp_state->_dref_crs_right->_int_value );

}


//write light test data to 7 seg LED's
void GFMCPPro_7Seg::_write_light_test(){

	unsigned char caTmp[16];

	//write a full set of 8's to the display buffer.
	snprintf( (char*)caTmp, 16, "88888" );

	//CRS Left
	GFUtils::set3f(
			_handle,
			GFMCPPro_7Seg::_usb_report_crs_left,
			caTmp
	);


	//IAS Mach
	GFUtils::set5f(
			_handle,
			GFMCPPro_7Seg::_usb_report_ias,
			caTmp
	);


	//Heading
	GFUtils::set3f(
			_handle,
			GFMCPPro_7Seg::_usb_report_hdg,
			caTmp
	);


	//Altitude
	GFUtils::set5f(
			_handle,
			GFMCPPro_7Seg::_usb_report_alt,
			caTmp
	);


	//Vert Speed
	GFUtils::set5f(
			_handle,
			GFMCPPro_7Seg::_usb_report_vs,
			caTmp
	);


	//CRS Right
	GFUtils::set3f(
			_handle,
			GFMCPPro_7Seg::_usb_report_crs_right,
			caTmp
	);

}





const unsigned char GFMCPPro_7Seg::_usb_report_crs_left   = 3;
const unsigned char GFMCPPro_7Seg::_usb_report_ias        = 5;
const unsigned char GFMCPPro_7Seg::_usb_report_hdg        = 7;
const unsigned char GFMCPPro_7Seg::_usb_report_alt        = 9;
const unsigned char GFMCPPro_7Seg::_usb_report_vs         = 11;
const unsigned char GFMCPPro_7Seg::_usb_report_crs_right  = 13;






//eof
