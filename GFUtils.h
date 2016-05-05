//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_GFUTILS_H
#define GF_MCP_PRO_GFUTILS_H


#include <hidapi.h>

#include <string.h>



// USB ID tags.
#define USB_GOFLIGHT 0x09f3

// Device type
#define USB_GOFLIGHT__MCP_PRO 0x0064



// hid_write channels.
#define MCP_CRS_LEFT 3
#define MCP_IAS 5
#define MCP_HDG 7
#define MCP_ALT 9
#define MCP_VS 11
#define MCP_CRS_RIGHT 13

#define MCP_BTNS 15







class GFUtils {
public:
    void set3f( hid_device* handle, unsigned char target, unsigned char *value );
    void set5f( hid_device* handle, unsigned char target, unsigned char *value );

    void set_leds( hid_device* handle, unsigned char *values );

    unsigned char translateCharTo7Seg( unsigned char raw );

};


#endif //GF_MCP_PRO_GFUTILS_H
