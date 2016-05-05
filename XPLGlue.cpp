//
// Created by Ben on 5/05/2016.
//

#include "XPLGlue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include <hidapi.h>




PLUGIN_API int XPluginStart(
        char *		outName,
        char *		outSig,
        char *		outDesc) {


    sprintf( outName, "GF MCP Pro v0.0.1" );
    sprintf( outSig, "goflight.com/mcp_pro" );
    sprintf( outDesc, "GoFlight MCP Pro Driver" );




    return 1;
}


PLUGIN_API void XPluginStop(void){

    XPLMDebugString("GF_MCP_Pro: XPluginStrop\n");

}




PLUGIN_API int XPluginEnable(void) {


    int res; //ops results.


    hid_device *handle = hid_open( USB_GOFLIGHT, USB_GOFLIGHT__MCP_PRO, NULL );
    if( handle == 0 ){
        printf("dev busy: sudo?\n");
        exit(0);
    }





    // Human ID string data buffers.
    #define MAX_STR 255
    wchar_t wstr[MAX_STR];


    // Read the Manufacturer String
    res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
    printf("Maker: %ls\n", wstr);

    // Read the Product String
    res = hid_get_product_string(handle, wstr, MAX_STR);
    printf("Product: %ls\n", wstr);

    // Read the Serial Number String
    res = hid_get_serial_number_string(handle, wstr, MAX_STR);
    printf("Serial: %ls", wstr);
    printf("\n");






    return 1; //allow start.
}




PLUGIN_API void XPluginDisable(void) {


}






PLUGIN_API void XPluginReceiveMessage(
        XPLMPluginID   inFromWho,
        intptr_t        inMessage,
        void *      inParam){



}