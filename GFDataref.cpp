//
// Created by Ben on 5/05/2016.
//

#include "GFDataref.h"

#include <XPLMUtilities.h>



#include <string.h>
#include <stdlib.h>
#include <stdio.h>





GFDataref::GFDataref(char *dref_name) {

	char caTmp[1024];
	snprintf( caTmp, 1024, "GF_MCP_Pro: Create dref:(%s)\n", dref_name );
	XPLMDebugString( caTmp );


    _name = std::string( dref_name );

    _element_count = -1;

    _dref =
            XPLMRegisterDataAccessor(
                    dref_name, //name
                    xplmType_Int, //type
                    1, //writable

                    GFDataref::xp_getDatai,	GFDataref::xp_setDatai,
                    NULL, NULL, //floats
                    NULL, NULL, //doubles

                    NULL, NULL, //integer vectors
                    NULL, NULL, //float vectors

                    NULL, NULL, //float vectors
                    //GFDataref::xp_getBytes, GFDataref::xp_setBytes, //byte vectors


                    (void *)this, //read refcon
                    (void *)this  //write refcon
            );

}



GFDataref::GFDataref(char *dref_name, int element_count) {

	char caTmp[1024];
	snprintf( caTmp, 1024, "GF_MCP_Pro: Create dref:(%s[%i])\n", dref_name, element_count );
	XPLMDebugString( caTmp );


    _name = std::string( dref_name );

    _element_count = element_count;

    _dref = XPLMRegisterDataAccessor(
                    dref_name, //name
                    xplmType_Data, //type
                    1, //writable

                    //GFDataref::xp_getDatai,	GFDataref::xp_setDatai,
                    NULL, NULL, //integer
                    NULL, NULL, //floats
                    NULL, NULL, //doubles

                    NULL, NULL, //integer vectors
                    NULL, NULL, //float vectors

                    GFDataref::xp_getBytes, GFDataref::xp_setBytes, //byte vectors

                    (void *)this, //read refcon
                    (void *)this  //write refcon
            );

}











int GFDataref::xp_getDatai(void *inRefcon) {
    //get
    GFDataref *tmp = (GFDataref*)inRefcon;

    return tmp->_int_value;
}


void GFDataref::xp_setDatai(void * inRefcon, int inValue){
    //set
    GFDataref *tmp = (GFDataref*)inRefcon;

    tmp->_int_value = inValue;

}




int GFDataref::xp_getBytes(
        void* inRefcon,
        void* outValues, /* Can be NULL */
        int inOffset,
        int inMax
){

    GFDataref *tmp = (GFDataref*)inRefcon;

    int max_byte_offset = inOffset+inMax;
    if( max_byte_offset > GFDataref::_blob_size ){
        // overflow..
    }

    //memset( outValues, tmp->_blob, inMax );


    return tmp->_element_count;
}

void GFDataref::xp_setBytes(
        void* inRefcon,
        void* inValues, /* Can be NULL */
        int inOffset,
        int inCount
){

    GFDataref *tmp = (GFDataref*)inRefcon;

    int max_byte_offset = inOffset+inCount;
    if( max_byte_offset > GFDataref::_blob_size ){
        //do nothing
        return;
    }

    unsigned char* blob_ptr = tmp->_blob + inOffset;


    memcpy( (void*)blob_ptr, inValues, inCount );


}
