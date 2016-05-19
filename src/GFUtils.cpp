//
// Created by Ben on 5/05/2016.
//

#include "GFUtils.h"

#include <string>

#include <XPLMUtilities.h>


//USB tmp buffer
#define GF_usb_buffer_size 8



//use this for MCP_CRS_LEFT || MCP_CRS_RIGHT || MCP_HDG
void GFUtils::set3f( hid_device *handle, unsigned char target, unsigned char *value ){

	if( 0 == handle ){
		GFUtils::Log("GFUtils::set3f(..) write failure. handle is 0.\n");
		return;
	}

    unsigned char buf[GF_usb_buffer_size];
    memset( buf, 0, GF_usb_buffer_size );

    buf[0] = target; //MCP_CRS_LEFT;
    buf[1] = GFUtils::translateCharTo7Seg( value[0] );
    buf[2] = GFUtils::translateCharTo7Seg( value[1] );
    buf[3] = GFUtils::translateCharTo7Seg( value[2] );

    //printf("buf: 0x%02x : %02x %02x %02x %02x %02x\n", buf[0], buf[1],buf[2],buf[3],buf[4],buf[5] );

    int res = hid_write( handle, buf, GF_usb_buffer_size );
    if (res < 0) {
		GFUtils::Log("GFUtils::set3f(..) : Unable to write 3f..\n"); //FIXME: usb write fail, propagate
	}

}



// MCP_IAS || MCP_ALT || MCP_VS
void GFUtils::set5f( hid_device *handle, unsigned char target, unsigned char *value ){

	if( 0 == handle ){
		GFUtils::Log("GFUtils::set5f(..) write failure.\n");
		return;
	}

    unsigned char buf[GF_usb_buffer_size];
    memset( buf, 0, GF_usb_buffer_size );

    buf[0] = target; //MCP_CRS_LEFT;
    buf[1] = GFUtils::translateCharTo7Seg( value[0] );
    buf[2] = GFUtils::translateCharTo7Seg( value[1] );
    buf[3] = GFUtils::translateCharTo7Seg( value[2] );
    buf[4] = GFUtils::translateCharTo7Seg( value[3] );
    buf[5] = GFUtils::translateCharTo7Seg( value[4] );

    //printf("buf: 0x%02x : %02x %02x %02x %02x %02x\n", buf[0], buf[1],buf[2],buf[3],buf[4],buf[5] );

	int res = hid_write( handle, buf, GF_usb_buffer_size );
	if (res < 0) {
		GFUtils::Log("GFUtils::set5f(..) : Unable to write 5f..\n"); //FIXME: usb write fail, propagate
	}

}



void GFUtils::set_leds( hid_device *handle, unsigned char target, unsigned char *values ){

	if( 0 == handle ){
		GFUtils::Log("GFUtils::set_leds(..) write failure.\n");
		return;
	}

    unsigned char buf[GF_usb_buffer_size];
    memset( buf, 0, GF_usb_buffer_size );

	//byte ordering makes no sense relative to physical layout
	buf[0] = target;
    buf[1] = 0; //not used
    buf[2] = values[0]; // lower
    buf[3] = values[1]; // midde
    buf[4] = values[2]; // top row of LED's

    int res = hid_write( handle, buf, GF_usb_buffer_size ); //FIXME: why was this 16?
	if (res < 0) {
		GFUtils::Log("GFUtils::set_leds(..) : Unable to write packet..\n"); //FIXME: usb write fail, propagate
	}

}



unsigned char GFUtils::translateCharTo7Seg( unsigned char raw ) {

    unsigned char ret=0;

    //translation table for 7 seg LCD's
    static const unsigned char gaTransTblDigits[] =
            {
                    0x3F, // '0'
                    0x06, // '1'
                    0x5B, // '2'
                    0x4F, // '3'
                    0x66, // '4'
                    0x6D, // '5'
                    0x7D, // '6'
                    0x07, // '7'
                    0x7F, // '8'
                    0x67  // '9'
            };


    switch( raw ){
        case '-':
            ret = 0x40;
            break;

        case ' ':
            ret = 0;
            break;

        default:
            int target = raw - 48;
            if( target < 0 ){ target=0; }
            ret = gaTransTblDigits[ target ];
            break;

    } //switch(..)


    return  ret;

} //unsigned char GFUtils::translateCharTo7Seg( unsigned char raw )




#ifndef GOFLIGHT_XPL_PRODUCT_NAME
#error GOFLIGHT_XPL_PRODUCT_NAME is not defined.
#endif


void GFUtils::Log( const char *message ) {

	std::string sMessage = std::string(GOFLIGHT_XPL_PRODUCT_NAME) + ": " + std::string(message);
	XPLMDebugString( sMessage.c_str() );

}





//eof
