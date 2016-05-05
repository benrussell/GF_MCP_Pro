//
// Created by Ben on 5/05/2016.
//

#include "XPLGlue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "GFMCPPro.h"

GFMCPPro *mcp_pro;


PLUGIN_API int XPluginStart(
        char *		outName,
        char *		outSig,
        char *		outDesc) {


    sprintf( outName, "GF MCP Pro v0.0.1" );
    sprintf( outSig, "goflight.com/mcp_pro" );
    sprintf( outDesc, "GoFlight MCP Pro Driver" );


    mcp_pro = new GFMCPPro();

    XPLMRegisterFlightLoopCallback( GFMCPPro_flcb, -1.f, NULL );


    return 1;
}



PLUGIN_API void XPluginStop(void){

    XPLMDebugString("GF_MCP_Pro: XPluginStrop\n");


    delete( mcp_pro );

}



PLUGIN_API int XPluginEnable(void) {

    XPLMDebugString("GF_MCP_Pro: Connecting to USB device..\n");
    mcp_pro->Connect();


    return 1; //allow start.

}



PLUGIN_API void XPluginDisable(void) {

    XPLMDebugString("GF_MCP_Pro: Disconnecting from USB device.\n");
    mcp_pro->Disconnect();

}



PLUGIN_API void XPluginReceiveMessage(
        XPLMPluginID   inFromWho,
        intptr_t        inMessage,
        void *      inParam){

    //no msg support yet

}



// ---------------------------------------------------------------------



float GFMCPPro_flcb(
        float                inElapsedSinceLastCall,
        float                inElapsedTimeSinceLastFlightLoop,
        int                  inCounter,
        void *               inRefcon) {

    mcp_pro->flcb();

    return -1.f;

}



int GFMCPPro_cmdHandler(    XPLMCommandRef        inCommand,
                            XPLMCommandPhase     inPhase,
                            void *               inRefcon) {

    XPCommand *cmd = (XPCommand*)inRefcon;

    char caTmp[1024];
    snprintf( caTmp, 1024, "GF MCP Pro: cmdHandler: %s\n", cmd->_name.c_str() );



    return 0;

}

// eof

