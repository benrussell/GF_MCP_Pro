//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_XPLGLUE_H
#define GF_MCP_PRO_XPLGLUE_H



#include <XPLMDefs.h>


#include <XPLMUtilities.h>



#include "GFMCPPro.h"



class XPLGlue {

};





//Standard X-Plane plugin function hooks.
PLUGIN_API int XPluginStart(
        char *		outName,
        char *		outSig,
        char *		outDesc);

PLUGIN_API void XPluginStop(void);

PLUGIN_API int XPluginEnable(void);

PLUGIN_API void XPluginDisable(void);

PLUGIN_API void XPluginReceiveMessage(
        XPLMPluginID   inFromWho,
        intptr_t        inMessage,
        void *      inParam);






#endif //GF_MCP_PRO_XPLGLUE_H
