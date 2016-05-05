//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_GFUTILS_H
#define GF_MCP_PRO_GFUTILS_H


#include <hidapi.h>

#include <string.h>








class GFUtils {
public:
    void set3f( hid_device* handle, unsigned char target, unsigned char *value );
    void set5f( hid_device* handle, unsigned char target, unsigned char *value );

    void set_leds( hid_device* handle, unsigned char target, unsigned char *values );

    unsigned char translateCharTo7Seg( unsigned char raw );

};


#endif //GF_MCP_PRO_GFUTILS_H
