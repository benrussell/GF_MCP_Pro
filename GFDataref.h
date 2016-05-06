//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_GFDataref_H
#define GF_MCP_PRO_GFDataref_H


#include <XPLMDataAccess.h>


#include <string>


class GFDataref {
public:
    //GFDataref();
    GFDataref( char* dref_name );
    GFDataref( char* dref_name, int element_count );

    XPLMDataRef _dref;

    std::string _name;

    static const int _blob_size = 8;


    int _int_value;
    unsigned char _blob[8];


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
