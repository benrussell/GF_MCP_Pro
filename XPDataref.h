//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_XPDATAREF_H
#define GF_MCP_PRO_XPDATAREF_H


#include <XPLMDataAccess.h>


#include <string>


class XPDataref {
public:
    XPDataref();
    XPDataref( char* dref_name );

    XPLMDataRef _dref;


    std::string _name;


private:
    static int xp_getDatai(void * inRefcon);
    static void xp_setDatai(void * inRefcon, int inValue);

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


#endif //GF_MCP_PRO_XPDATAREF_H
