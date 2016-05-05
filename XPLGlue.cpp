//
// Created by Ben on 5/05/2016.
//

#include "XPLGlue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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

    return 1; //allow start.
}




PLUGIN_API void XPluginDisable(void) {


}






PLUGIN_API void XPluginReceiveMessage(
        XPLMPluginID   inFromWho,
        intptr_t        inMessage,
        void *      inParam){



}