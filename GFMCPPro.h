//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_GFMCPPRO_H
#define GF_MCP_PRO_GFMCPPRO_H


// XPlane Utils
#include "XPCommand.h"
#include "XPDataref.h"



#include "GFMCPPro_7Seg.h"
#include "GFMCPPro_Buttons.h"
#include "GFMCPPro_LEDS.h"




// USB ID tags.
#define USB_GOFLIGHT 0x09f3

// Device type
#define USB_GOFLIGHT__MCP_PRO 0x0064



// hid_write channels.
#define MCP_CRS_LEFT 3
#define MCP_IAS 5
#define MCP_HDG 7
#define MCP_ALT 9
#define MCP_VS 11
#define MCP_CRS_RIGHT 13

#define MCP_BTNS 15




#include <hidapi.h>


class GFMCPPro {
private:

    hid_device *handle;

    int _open_usb_dev();
    int _close_usb_dev();

    void _create_xp_commands();
    void _create_xp_datarefs();


public:

    GFMCPPro();

    void Connect();
    void Disconnect();

    void _flcb();


    XPCommand _cmd_crs_left_inc;
    XPCommand _cmd_crs_left_dec;

    XPCommand _cmd_ias_mach_inc;
    XPCommand _cmd_ias_mach_dec;

    XPCommand _cmd_heading_inc;
    XPCommand _cmd_heading_dec;

    XPCommand _cmd_altitude_inc;
    XPCommand _cmd_altitude_dec;

    XPCommand _cmd_vert_speed_inc;
    XPCommand _cmd_vert_speed_dec;

    XPCommand _cmd_crs_right_inc;
    XPCommand _cmd_crs_right_dec;




};


#endif //GF_MCP_PRO_GFMCPPRO_H
