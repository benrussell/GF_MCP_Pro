//
// Created by Ben on 5/05/2016.
//

#include "XPDataref.h"

#include <XPLMUtilities.h>



#include <string.h>
#include <stdlib.h>
#include <stdio.h>





XPDataref::XPDataref() {
}

XPDataref::XPDataref(char *dref_name) {

    XPLMDebugString("GF_MCP_Pro: Create dref..\n");

    _name = std::string( dref_name );

    _element_count = -1;

    _dref =
            XPLMRegisterDataAccessor(
                    dref_name, //name
                    xplmType_Int, //type
                    1, //writable

                    XPDataref::xp_getDatai,	XPDataref::xp_setDatai,
                    NULL, NULL, //floats
                    NULL, NULL, //doubles

                    NULL, NULL, //integer vectors
                    NULL, NULL, //float vectors

                    NULL, NULL, //float vectors
                    //XPDataref::xp_getBytes, XPDataref::xp_setBytes, //byte vectors


                    (void *)this, //read refcon
                    (void *)this  //write refcon
            );

}



XPDataref::XPDataref(char *dref_name, int element_count) {

    XPLMDebugString("GF_MCP_Pro: Create dref array..\n");

    _name = std::string( dref_name );

    _element_count = element_count;

    _dref = XPLMRegisterDataAccessor(
                    dref_name, //name
                    xplmType_Data, //type
                    1, //writable

                    //XPDataref::xp_getDatai,	XPDataref::xp_setDatai,
                    NULL, NULL, //integer
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
    XPDataref *tmp = (XPDataref*)inRefcon;

    return tmp->_int_value;
}


void XPDataref::xp_setDatai(void * inRefcon, int inValue){
    //set
    XPDataref *tmp = (XPDataref*)inRefcon;

    tmp->_int_value = inValue;

}




int XPDataref::xp_getBytes(
        void* inRefcon,
        void* outValues, /* Can be NULL */
        int inOffset,
        int inMax
){

    XPDataref *tmp = (XPDataref*)inRefcon;

    int max_byte_offset = inOffset+inMax;
    if( max_byte_offset > XPDataref::_blob_size ){
        // overflow..
    }

    //memset( outValues, tmp->_blob, inMax );


    return tmp->_element_count;
}

void XPDataref::xp_setBytes(
        void* inRefcon,
        void* inValues, /* Can be NULL */
        int inOffset,
        int inCount
){

    XPDataref *tmp = (XPDataref*)inRefcon;

    int max_byte_offset = inOffset+inCount;
    if( max_byte_offset > XPDataref::_blob_size ){
        //do nothing
        return;
    }

    unsigned char* blob_ptr = tmp->_blob + inOffset;


    memcpy( (void*)blob_ptr, inValues, inCount );


}
