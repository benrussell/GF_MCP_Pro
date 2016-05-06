//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_Buttons.h"


#include <hidapi.h>



const char* crs_left_inc = "goflight/mcp_pro/crs_left_inc";

const char* label_no_description = "No description.";




GFMCPPro_Buttons::GFMCPPro_Buttons(){
    // Create commands..
    // Need both ..._inc and ..._dec versions of thes

    _btn_crs_left_inc = XPCommand( (char*)GFMCPPro_Buttons::label_crs_left_inc, (char*)label_no_description );
    _btn_crs_left_dec = XPCommand( (char*)GFMCPPro_Buttons::label_crs_left_dec, (char*)label_no_description );

    _btn_ias_mach_inc = XPCommand( (char*)GFMCPPro_Buttons::label_ias_mach_inc, (char*)label_no_description );
    _btn_ias_mach_dec = XPCommand( (char*)GFMCPPro_Buttons::label_ias_mach_dec, (char*)label_no_description );

    _btn_heading_inc = XPCommand( (char*)GFMCPPro_Buttons::label_heading_inc, (char*)label_no_description );
    _btn_heading_dec = XPCommand( (char*)GFMCPPro_Buttons::label_heading_dec, (char*)label_no_description );

    _btn_altitude_inc = XPCommand( (char*)GFMCPPro_Buttons::label_altitude_inc, (char*)label_no_description );
    _btn_altitude_dec = XPCommand( (char*)GFMCPPro_Buttons::label_altitude_dec, (char*)label_no_description );

    _btn_vert_speed_inc = XPCommand( (char*)GFMCPPro_Buttons::label_vert_speed_inc, (char*)label_no_description );
    _btn_vert_speed_dec = XPCommand( (char*)GFMCPPro_Buttons::label_vert_speed_dec, (char*)label_no_description );

    _btn_crs_right_inc = XPCommand( (char*)GFMCPPro_Buttons::label_crs_right_inc, (char*)label_no_description );
    _btn_crs_right_dec = XPCommand( (char*)GFMCPPro_Buttons::label_crs_right_dec, (char*)label_no_description );

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

    //packet to inspect
    int bx=0;


    // Channel
    // packet, value

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

    bx=5;

    if( buf[bx] & 1 ){
        //Speed
        _btn_Speed.Begin();
    }else{
        _btn_Speed.Stop();
    }

    if( buf[bx] & 2 ){
        //LVL CHG
        _btn_LVL_CHG.Begin();
    }else{
        _btn_LVL_CHG.Stop();
    }

    if( buf[bx] & 4 ){
        //HDG SEL
        _btn_HDG_SEL.Begin();
    }else{
        _btn_HDG_SEL.Stop();
    }

    if( buf[bx] & 8 ){
        //APP
        _btn_APP.Begin();
    }else{
        _btn_APP.Stop();
    }

    if( buf[bx] & 16 ){
        //ALT HLD
        _btn_ALT_HLD.Begin();
    }else{
        _btn_ALT_HLD.Stop();
    }

    if( buf[bx] & 32 ){
        //VS
        _btn_VS.Begin();
    }else{
        _btn_VS.Stop();
    }

    if( buf[bx] & 64 ){
        //AP Disengage
        _btn_AP_Disengage.Begin();
    }else{
        _btn_AP_Disengage.Stop();
    }

    if( buf[bx] & 128 ){
        //FD Right
        _btn_FD_Right.Begin();
    }else{
        _btn_FD_Right.Stop();
    }








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






    // -------- knobs ---

    //parse for CRS_RIGHT knob
    if (buf[3] == 1 || buf[3] == 2) {
        //hdg++;

    } else if (buf[3] == 14 || buf[3] == 15) {
        //hdg--;

    }


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
