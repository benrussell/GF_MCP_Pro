//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_Buttons.h"


#include <hidapi.h>




const char* label_no_description = "No description.";




GFMCPPro_Buttons::GFMCPPro_Buttons(){
    // Create commands..
    // Need both ..._inc and ..._dec versions of thes

    _btn_crs_left_inc = GFCommand( (char*)GFMCPPro_Buttons::label_crs_left_inc, (char*)label_no_description );
    _btn_crs_left_dec = GFCommand( (char*)GFMCPPro_Buttons::label_crs_left_dec, (char*)label_no_description );

    _btn_ias_mach_inc = GFCommand( (char*)GFMCPPro_Buttons::label_ias_mach_inc, (char*)label_no_description );
    _btn_ias_mach_dec = GFCommand( (char*)GFMCPPro_Buttons::label_ias_mach_dec, (char*)label_no_description );

    _btn_heading_inc = GFCommand( (char*)GFMCPPro_Buttons::label_heading_inc, (char*)label_no_description );
    _btn_heading_dec = GFCommand( (char*)GFMCPPro_Buttons::label_heading_dec, (char*)label_no_description );

    _btn_altitude_inc = GFCommand( (char*)GFMCPPro_Buttons::label_altitude_inc, (char*)label_no_description );
    _btn_altitude_dec = GFCommand( (char*)GFMCPPro_Buttons::label_altitude_dec, (char*)label_no_description );

    _btn_vert_speed_inc = GFCommand( (char*)GFMCPPro_Buttons::label_vert_speed_inc, (char*)label_no_description );
    _btn_vert_speed_dec = GFCommand( (char*)GFMCPPro_Buttons::label_vert_speed_dec, (char*)label_no_description );

    _btn_crs_right_inc = GFCommand( (char*)GFMCPPro_Buttons::label_crs_right_inc, (char*)label_no_description );
    _btn_crs_right_dec = GFCommand( (char*)GFMCPPro_Buttons::label_crs_right_dec, (char*)label_no_description );

}




void GFMCPPro_Buttons::update() {

    _read_usb();

}




void GFMCPPro_Buttons::_read_usb() {

    const int buf_size=16;
    unsigned char buf[buf_size];

    int res;


    memset(buf, 0, buf_size);

    // Read requested state
    res = hid_read( _handle, buf, buf_size);
    if (res < 0) {
        XPLMDebugString("GF MCP Pro: USB Read Failed.\n");

    } else {

        _dump_button_packet( res, buf );
        _proc_buttons( res, buf );

    } //checking for packet read

} // read_usb()




void GFMCPPro_Buttons::_proc_buttons( int res, unsigned char* buf ){


    // Channel
    // packet, value

    // ------------------ Knobs ----------------

    // Packet 1
    // --------------------
    // HDG
    buf[1] & 14 ? _btn_heading_inc.Begin()         : _btn_heading_inc.Stop();
    buf[1] & 1 ? _btn_heading_dec.Begin()          : _btn_heading_dec.Stop();
    // CRS Left
    buf[1] & 224 ? _btn_crs_left_inc.Begin()       : _btn_crs_left_inc.Stop();
    buf[1] & 16 ? _btn_crs_left_dec.Begin()        : _btn_crs_left_dec.Stop();

    // Packet 2
    // --------------------
    // VS
    buf[2] & 14 ? _btn_vert_speed_inc.Begin()         : _btn_vert_speed_inc.Stop();
    buf[2] & 1 ? _btn_vert_speed_dec.Begin()          : _btn_vert_speed_dec.Stop();
    // IAS
    buf[2] & 224 ? _btn_ias_mach_inc.Begin()           : _btn_ias_mach_inc.Stop();
    buf[2] & 16 ? _btn_ias_mach_dec.Begin()            : _btn_ias_mach_dec.Stop();

    // Packet 3
    // --------------------
    // CRS Right
    buf[3] & 14 ? _btn_crs_right_inc.Begin()         : _btn_crs_right_inc.Stop();
    buf[3] & 1 ? _btn_crs_right_dec.Begin()          : _btn_crs_right_dec.Stop();
    // ALT
    buf[3] & 224 ? _btn_altitude_inc.Begin()         : _btn_altitude_inc.Stop();
    buf[3] & 16 ? _btn_altitude_dec.Begin()          : _btn_altitude_dec.Stop();





    // ------------------ Buttons ----------------

    // Packet 5
    // --------------------
    // Speed            1
    // LVL CHG          2
    // HDG SEL          4
    // APP              8
    // ALT HLD          16
    // V/S              32
    // AP Disengage     64
    // FD Right         128

    buf[5] & 1 ? _btn_Speed.Begin()            : _btn_Speed.Stop();
    buf[5] & 2 ? _btn_LVL_CHG.Begin()          : _btn_LVL_CHG.Stop();
    buf[5] & 4 ? _btn_HDG_SEL.Begin()          : _btn_HDG_SEL.Stop();
    buf[5] & 8 ? _btn_APP.Begin()              : _btn_APP.Stop();
    buf[5] & 16 ? _btn_ALT_HLD.Begin()         : _btn_ALT_HLD.Stop();
    buf[5] & 32 ? _btn_VS.Begin()              : _btn_VS.Stop();
    buf[5] & 64 ? _btn_AP_Disengage.Begin()    : _btn_AP_Disengage.Stop();
    buf[5] & 128 ? _btn_FD_Right.Begin()       : _btn_FD_Right.Stop();



    // Packet 6
    // --------------------
    // ALT INV          1
    // CWS A            2
    // CWS B            4
    // IAS Dial         8
    // HDG Dial         16
    // ALT Dial         32
    // FD Left          64
    // N1               128

    buf[6] & 1 ? _btn_ALT_INV.Begin()          : _btn_ALT_INV.Stop();
    buf[6] & 2 ? _btn_CWS_A.Begin()            : _btn_CWS_A.Stop();
    buf[6] & 4 ? _btn_CWS_B.Begin()            : _btn_CWS_B.Stop();

    buf[6] & 8 ? _btn_IAS_Dial.Begin()         : _btn_IAS_Dial.Stop();
    buf[6] & 16 ? _btn_HDG_Dial.Begin()        : _btn_HDG_Dial.Stop();
    buf[6] & 32 ? _btn_ALT_Dial.Begin()        : _btn_ALT_Dial.Stop();

    buf[6] & 64 ? _btn_FD_Left.Begin()         : _btn_FD_Left.Stop();
    buf[6] & 128 ? _btn_N1.Begin()             : _btn_N1.Stop();



    // Packet 7
    // --------------------
    // VNAV             1
    // LNAV             2
    // CMD A            4
    // CMD B            8
    // AT Arm           16
    // C/O              32
    // SPD INTV         64
    // VOR LOC          128

    buf[7] & 1 ? _btn_VNAV.Begin()             : _btn_VNAV.Stop();
    buf[7] & 2 ? _btn_LNAV.Begin()             : _btn_LNAV.Stop();
    buf[7] & 4 ? _btn_CMD_A.Begin()            : _btn_CMD_A.Stop();
    buf[7] & 8 ? _btn_CMD_B.Begin()            : _btn_CMD_B.Stop();
    buf[7] & 16 ? _btn_AT_Arm.Begin()          : _btn_AT_Arm.Stop();
    buf[7] & 32 ? _btn_CO.Begin()              : _btn_CO.Stop();
    buf[7] & 64 ? _btn_SPD_INTV.Begin()        : _btn_SPD_INTV.Stop();
    buf[7] & 128 ? _btn_VOR_LOC.Begin()        : _btn_VOR_LOC.Stop();




} //_proc_button_packet



void GFMCPPro_Buttons::_dump_button_packet( int res, unsigned char* buf ){

    // Print out the returned buffer.
    for (int i = 0; i < res; i++) {
        printf("% 4d    ", buf[i]);
    }
    //if a report has been rxd and dumped, we should put a new line
    if (res > 0) {
        printf("\n");
    }

}






// eof
