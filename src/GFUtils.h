//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_GFUTILS_H
#define GF_MCP_PRO_GFUTILS_H


#include <hidapi.h>

#include <string.h>








class GFUtils {
public:
    static void set3f( hid_device* handle, unsigned char target, unsigned char *value );
    static void set5f( hid_device* handle, unsigned char target, unsigned char *value );

    static void set_leds( hid_device* handle, unsigned char target, unsigned char *values );

    static unsigned char translateCharTo7Seg( unsigned char raw );


	static void Log( const char* message );



	static int hdg_wrap( int new_hdg );


};


#endif //GF_MCP_PRO_GFUTILS_H
