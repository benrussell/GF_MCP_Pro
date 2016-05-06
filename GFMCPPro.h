//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_H
#define GF_MCP_PRO_GFMCPPRO_H


// XPlane Utils
#include "GFCommand.h"
#include "GFDataref.h"


#include "GFMCPPro_Buttons.h"
#include "GFMCPPro_7Seg.h"
#include "GFMCPPro_LEDS.h"



// USB ID tags.
#define USB_GOFLIGHT 0x09f3

// Device type
#define USB_GOFLIGHT__MCP_PRO 0x0064



// hid_write channels.

#define MCP_BTNS 15




#include <hidapi.h>


class GFMCPPro {
private:
    hid_device *_handle;

    int _open_usb_dev();
    int _close_usb_dev();


    GFMCPPro_Buttons *_gf_mcp_pro_buttons;

    GFMCPPro_LEDS *_gf_mcp_pro_leds;
    GFMCPPro_7Seg *_gf_mcp_pro_7seg;



public:

    GFMCPPro();
    ~GFMCPPro();

    void Connect();
    void Disconnect();



    void flcb();


};


#endif //GF_MCP_PRO_GFMCPPRO_H
