//
// Created by Ben on 5/05/2016.
//

#include "GFUtils.h"




//USB tmp buffer
#define buf_size 16



//use this for MCP_CRS_LEFT || MCP_CRS_RIGHT || MCP_HDG
void GFUtils::set3f( hid_device *handle, unsigned char target, int value ){

    int res;

    char caTmp[4];
    snprintf( caTmp, 4, "%03d", value );
    //printf( "set3f string:(%s)\n", caTmp);


    unsigned char buf[buf_size];

    memset( buf, 0, buf_size );
    buf[0] = target; //MCP_CRS_LEFT;

    buf[1] = gaTransTblDigits[ get_trans_index( caTmp[0] ) ];
    buf[2] = gaTransTblDigits[ get_trans_index( caTmp[1] ) ];
    buf[3] = gaTransTblDigits[ get_trans_index( caTmp[2] ) ];



    //printf("buf: 0x%02x : %02x %02x %02x %02x %02x\n", buf[0], buf[1],buf[2],buf[3],buf[4],buf[5] );

    res = hid_write( handle, buf, 8 );
    if (res < 0)
        printf("Unable to write..\n");



}







// MCP_IAS || MCP_ALT || MCP_VS
void GFUtils::set5f( hid_device *handle, unsigned char target, int value ){

    int res;

    char caTmp[8];
    snprintf( caTmp, 8, "%05d", value );
    //printf( "set5f string:(%s)\n", caTmp);


    unsigned char buf[buf_size];

    memset( buf, 0, buf_size );
    buf[0] = target; //MCP_CRS_LEFT;

    buf[1] = gaTransTblDigits[ get_trans_index( caTmp[0] ) ];
    buf[2] = gaTransTblDigits[ get_trans_index( caTmp[1] ) ];
    buf[3] = gaTransTblDigits[ get_trans_index( caTmp[2] ) ];
    buf[4] = gaTransTblDigits[ get_trans_index( caTmp[3] ) ];
    buf[5] = gaTransTblDigits[ get_trans_index( caTmp[4] ) ];



    //printf("buf: 0x%02x : %02x %02x %02x %02x %02x\n", buf[0], buf[1],buf[2],buf[3],buf[4],buf[5] );

    res = hid_write( handle, buf, 8 );
    if (res < 0)
        printf("Unable to write..\n");



}






void GFUtils::set_leds( hid_device *handle, unsigned char *text ){

    unsigned char a,b,c;
    a = text[0];
    b = text[1];
    c = text[2];


    unsigned char buf[buf_size];


    memset( buf, 0, buf_size );
    buf[0] = MCP_BTNS;

    buf[1] = 0;

    //byte ordering makes no sense relative to physical layout
    buf[2] = a;// lower
    buf[3] = b;// midde
    buf[4] = c;// top row of LED's

    buf[5] = 0;

    hid_write( handle, buf, 16 );

}