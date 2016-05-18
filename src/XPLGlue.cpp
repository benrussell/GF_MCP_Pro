//
// Created by Ben on 5/05/2016.
//

#include "XPLGlue.h"


#include <XPLMPlugin.h>

#include <XPLMProcessing.h>

#include "GFMCPPro.h"

#include "Windows_snprintf.h"




GFMCPPro *mcp_pro;


PLUGIN_API int XPluginStart(
        char *		outName,
        char *		outSig,
        char *		outDesc) {


	const char* name = "GoFlight MCP Pro v0.0.122";
	const char* sig = "goflightinc.com/mcp_pro";
	const char* desc = "Built: " __DATE__ " " __TIME__;

    sprintf( outName, "%s", name );
    sprintf( outSig, "%s", sig );
    sprintf( outDesc, "%s", desc );


	char caTmp[1024];
	snprintf( caTmp, 1024, "%s - %s\n", name, desc );
	GFUtils::Log( caTmp );


    mcp_pro = new GFMCPPro();

    XPLMRegisterFlightLoopCallback( GFMCPPro_flcb, -1.f, NULL );


    return 1;
}



PLUGIN_API void XPluginStop(void){

	GFUtils::Log("XPluginStrop\n");

    delete( mcp_pro );

}



PLUGIN_API int XPluginEnable(void) {

    //mcp_pro->Connect();

    return 1; //allow start.

}



PLUGIN_API void XPluginDisable(void) {

    //mcp_pro->Disconnect();

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
		GFUtils::Log("Registering datarefs with DRE..\n");

		//modified to use broadcast message so we can send to DRE and DRT with one call
		const int MSG_ADD_DATAREF = 0x01000000;

		std::string* tmp_string;
		for( size_t x=0; x < GFDataref::_deferred_registration_pool.size(); x++ ){

			tmp_string = GFDataref::_deferred_registration_pool[x];
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

	GFMCPPro_Buttons *btn_router = (GFMCPPro_Buttons*)cmd->_button_router;


#if 1
	char caTmp[1024];
	snprintf( caTmp, 1024, "phase:%i cmdHandler: %s\n", inPhase, cmd->_name.c_str() );
	GFUtils::Log( caTmp );
#endif


	return btn_router->xp_cmd_action_handler( inPhase, cmd );


}




void GFMCPPro_menuHandler(
		void *               inMenuRef,
		void *               inItemRef) {

	//push menu clicks into the mcp_pro instance.
	mcp_pro->menuHandler( inMenuRef, inItemRef );

}









// eof

