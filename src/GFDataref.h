//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_GFDataref_H
#define GF_MCP_PRO_GFDataref_H


#include <XPLMDataAccess.h>

#include <string>
#include <vector>


class GFDataref {
public:
	GFDataref( const std::string dref_name );
	GFDataref( const std::string dref_name, int element_count );


	//stores a handle to the registered custom dref.
    XPLMDataRef _dref;
    std::string _name;


	int _int_value;


	static const size_t _blob_size = 8;
    unsigned char _blob[8];


	static std::vector<std::string*> _deferred_registration_pool;


private:


    static int xp_getDatai(void * inRefcon);
    static void xp_setDatai(void * inRefcon, int inValue);


    //if an array dref, how many items?
    int _element_count;

    static int xp_getBytes(
            void* inRefcon,
            void* outValues, /* Can be NULL */
            int inOffset,
            int inMax
    );
    static void xp_setBytes(
            void* inRefcon,
            void* inValues, /* Can be NULL */
            int inOffset,
            int inCount
    );


};


#endif //GF_MCP_PRO_GFDataref_H
