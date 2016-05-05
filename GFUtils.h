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





#define neg_sign = 0x40;

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





unsigned char  get_trans_index( unsigned char target ){

    //printf("target  in: %c/%i\n", target,target);

    //translate human text into decimal data by using the ascii table offset.
    unsigned char ret = target - 48;

    //out chars may be invisible in a terminal
    //printf("target out: %c/%i\n", ret,ret);

    return ret;

}







class GFUtils {
public:
    void set3f( hid_device* handle, unsigned char target, int value );
    void set5f( hid_device* handle, unsigned char target, int value );

    void set_leds( hid_device* handle, unsigned char *text );

};


#endif //GF_MCP_PRO_GFUTILS_H
