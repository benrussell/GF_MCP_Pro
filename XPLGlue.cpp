//
// Created by Ben on 5/05/2016.
//

#include "XPLGlue.h"


#include <XPLMPlugin.h>

#include <XPLMProcessing.h>



#include "GFMCPPro.h"




GFMCPPro *mcp_pro;


PLUGIN_API int XPluginStart(
        char *		outName,
        char *		outSig,
        char *		outDesc) {


	const char* name = "GoFlight MCP Pro v0.0.4";
	const char* sig = "goflightinc.com/mcp_pro";
	const char* desc = "Built: 2016.05.07.1529";

    sprintf( outName, "%s", name );
    sprintf( outSig, "%s", sig );
    sprintf( outDesc, "%s", desc );


	char caTmp[1024];
	snprintf( caTmp, 1024, "%s - %s\n", name, desc );
	XPLMDebugString( caTmp );


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


	static int do_deferred_init = 1;
	if( do_deferred_init ){

		// ---- Run through our list of datarefs and inform DRE ---
		XPLMDebugString("GF_MCP_Pro: Registering datarefs with DRE..\n");

		//modified to use broadcast message so we can send to DRE and DRT with one call
		const int MSG_ADD_DATAREF = 0x01000000;

		std::string* tmp_string;
		for( size_t x=0; x < GFDataref::_deferred_DRE_registration_pool.size(); x++ ){

			tmp_string = GFDataref::_deferred_DRE_registration_pool[x];
			XPLMSendMessageToPlugin( XPLM_NO_PLUGIN_ID, MSG_ADD_DATAREF, (void*)tmp_string->c_str() );

		}

		do_deferred_init = 0;
	}



    mcp_pro->flcb();

    return -1.f;

}



int GFMCPPro_cmdHandler(    XPLMCommandRef        inCommand,
                            XPLMCommandPhase     inPhase,
                            void *               inRefcon) {

    GFCommand *cmd = (GFCommand*)inRefcon;

    char caTmp[1024];
    snprintf( caTmp, 1024, "GF_MCP_Pro: phase:%i cmdHandler: %s\n", inPhase, cmd->_name.c_str() );
	XPLMDebugString( caTmp );


    return 0;

}

// eof

