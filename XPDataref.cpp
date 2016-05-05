//
// Created by Ben on 5/05/2016.
//

#include "XPDataref.h"

#include <XPLMUtilities.h>


XPDataref::XPDataref() {
}

XPDataref::XPDataref(char *dref_name) {

    XPLMDebugString("GF_MCP_Pro: Create dref..\n");

    _name = std::string( dref_name );

    _dref =
            XPLMRegisterDataAccessor(
                    dref_name, //name
                    xplmType_Int | xplmType_Data, //type
                    1, //writable

                    XPDataref::xp_getDatai,	XPDataref::xp_setDatai,
                    NULL, NULL, //floats
                    NULL, NULL, //doubles

                    NULL, NULL, //integer vectors
                    NULL, NULL, //float vectors

                    XPDataref::xp_getBytes, XPDataref::xp_setBytes, //byte vectors

                    (void *)this, //read refcon
                    (void *)this  //write refcon
            );

}


int XPDataref::xp_getDatai(void *inRefcon) {
    //get

    return 0;
}


void XPDataref::xp_setDatai(void * inRefcon, int inValue){
    //set

    XPDataref *dref = (XPDataref*)inRefcon;




}




int XPDataref::xp_getBytes(
        void* inRefcon,
        void* outValues, /* Can be NULL */
        int inOffset,
        int inMax
){

    return 0;
}

void XPDataref::xp_setBytes(
        void* inRefcon,
        void* inValues, /* Can be NULL */
        int inOffset,
        int inCount
){

}
