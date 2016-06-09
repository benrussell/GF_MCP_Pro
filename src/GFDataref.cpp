//
// Created by Ben on 5/05/2016.
//

#include "GFDataref.h"

#include <XPLMUtilities.h>

#include "GFUtils.h"

#include "Windows_snprintf.h"



std::vector<std::string*> GFDataref::_deferred_registration_pool;




GFDataref::GFDataref( const std::string dref_name ){

	//convert bool argument into int var usable for XP SDK.
	//cant use int var in sig because conflics with element_count sig for creating arrays.

	char caTmp[1024];
	snprintf( caTmp, 1024, "dref:(%s)\n", dref_name.c_str() );
	GFUtils::Log( caTmp );

	_deferred_registration_pool.push_back( new std::string(dref_name) );

    _name = dref_name;

    _element_count = -1;

	_int_value = 0;

	snprintf( (char*)_blob, GFDataref::_blob_size, "12345" );

    _dref =
            XPLMRegisterDataAccessor(
                    dref_name.c_str(), //name
                    xplmType_Int, //type
					1, //writable

                    GFDataref::xp_getDatai,	GFDataref::xp_setDatai, //integer
					//NULL, NULL //integers

                    NULL, NULL, //floats
                    NULL, NULL, //doubles

                    NULL, NULL, //integer vectors
                    NULL, NULL, //float vectors

                    NULL, NULL, //byte vectors
                    //GFDataref::xp_getBytes, GFDataref::xp_setBytes, //byte vectors


                    reinterpret_cast<void*>(this), //read refcon
                    reinterpret_cast<void*>(this)  //write refcon
            );

}



GFDataref::GFDataref( const std::string dref_name, int element_count ) {

	char caTmp[1024];
	snprintf( caTmp, 1024, "dref:(%s[%i])\n", dref_name.c_str(), element_count );
	GFUtils::Log( caTmp );

	_deferred_registration_pool.push_back( new std::string(dref_name) );

    _name = dref_name;

    _element_count = element_count;

	_int_value = 0;

	snprintf( (char*)_blob, GFDataref::_blob_size, "88888" );

	_dref = XPLMRegisterDataAccessor(
                    dref_name.c_str(), //name
                    xplmType_Data, // | xplmType_Int, //type
					1, //writable

                    GFDataref::xp_getDatai,	GFDataref::xp_setDatai, //integer
                    //NULL, NULL, //integer

                    NULL, NULL, //floats
                    NULL, NULL, //doubles

                    NULL, NULL, //integer vectors
                    NULL, NULL, //float vectors

                    GFDataref::xp_getBytes, GFDataref::xp_setBytes, //byte vectors
					//NULL, NULL //byte vectors


                    reinterpret_cast<void*>(this), //read refcon
                    reinterpret_cast<void*>(this)  //write refcon
            );

}











int GFDataref::xp_getDatai(void *inRefcon) {
    //get
    GFDataref *tmp = static_cast<GFDataref*>(inRefcon);

    return tmp->_int_value;
}


void GFDataref::xp_setDatai(void * inRefcon, int inValue){
    //set
    GFDataref *tmp = static_cast<GFDataref*>(inRefcon);

    tmp->_int_value = inValue;

}





int GFDataref::xp_getBytes(
        void* inRefcon,
        void* outValues, /* Can be NULL */
        int inOffset,
        int inMax
){

    GFDataref *tmp = static_cast<GFDataref*>(inRefcon);

	size_t bytes_to_copy = GFDataref::_blob_size - inOffset;

    if( inOffset > (int)GFDataref::_blob_size ){
        // overflow..
		GFUtils::Log("byte-dataref read for OOB data. Aborted.\n");

		return 0;
    }

    if( outValues != NULL ) {
        memcpy(outValues, tmp->_blob + inOffset, bytes_to_copy);
    }

    return tmp->_element_count;
}



void GFDataref::xp_setBytes(
        void* inRefcon,
        void* inValues, /* Can be NULL */
        int inOffset,
        int inCount
){

    GFDataref *tmp = static_cast<GFDataref*>(inRefcon);

    int max_byte_offset = inOffset+inCount;
    if( max_byte_offset > (int)GFDataref::_blob_size ){
        //do nothing
		GFUtils::Log("byte-dataref write for OOB data. Aborted.\n");
        return;
    }

    if( inValues != NULL ) {
        memcpy(tmp->_blob + inOffset, inValues, (size_t) inCount);
    }
}
