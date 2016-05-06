#include <hidapi/hidapi.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>


// USB ID tags.
#define GOFLIGHT 0x09f3

// Device type
#define MCP_PRO 0x0064



#define MCP_CRS_LEFT 3
#define MCP_IAS 5
#define MCP_HDG 7
#define MCP_ALT 9
#define MCP_VS 11
#define MCP_CRS_RIGHT 13

#define MCP_BTNS 15




#define neg_sign = 0x40;

static const unsigned char gaTransTblDigits[] = 
    {
	0x3F, // '0'
	0x06, // '1'
	0x5B, // '2'
	0x4F, // '3'
	0x66, // '4'
	0x6D, // '5'
	0x7D, // '6'
	0x07, // '7'
	0x7F, // '8'
	0x67  // '9'
	};



// Human ID string data buffers.
#define MAX_STR 255
wchar_t wstr[MAX_STR];



//result flag for various ops
int res;




unsigned char  get_trans_index( unsigned char target ){

	//printf("target  in: %c/%i\n", target,target);

	//translate human text into decimal data by using the ascii table offset.
	unsigned char ret = target - 48;
	
	//out chars may be invisible in a terminal
	//printf("target out: %c/%i\n", ret,ret);
	
	return ret;

}



//USB tmp buffer
#define buf_size 16


//use this for MCP_CRS_LEFT || MCP_CRS_RIGHT || MCP_HDG
void set3f( hid_device *handle, unsigned char target, int value ){

	char caTmp[4];
	snprintf( caTmp, 4, "%03d", value );
	//printf( "set3f string:(%s)\n", caTmp);
	
	
	unsigned char buf[buf_size];
	
	memset( buf, 0, buf_size );
	buf[0] = target; //MCP_CRS_LEFT;
	
	buf[1] = gaTransTblDigits[ get_trans_index( caTmp[0] ) ];
	buf[2] = gaTransTblDigits[ get_trans_index( caTmp[1] ) ];
	buf[3] = gaTransTblDigits[ get_trans_index( caTmp[2] ) ];
	
	
	
	//printf("buf: 0x%02x : %02x %02x %02x %02x %02x\n", buf[0], buf[1],buf[2],buf[3],buf[4],buf[5] );

	res = hid_write( handle, buf, 8 );
	if (res < 0)
		printf("Unable to write..\n");	



}





// MCP_IAS || MCP_ALT || MCP_VS
void set5f( hid_device *handle, unsigned char target, int value ){

	char caTmp[8];
	snprintf( caTmp, 8, "%05d", value );
	//printf( "set5f string:(%s)\n", caTmp);
	
	
	unsigned char buf[buf_size];
	
	memset( buf, 0, buf_size );
	buf[0] = target; //MCP_CRS_LEFT;
	
	buf[1] = gaTransTblDigits[ get_trans_index( caTmp[0] ) ];
	buf[2] = gaTransTblDigits[ get_trans_index( caTmp[1] ) ];
	buf[3] = gaTransTblDigits[ get_trans_index( caTmp[2] ) ];
	buf[4] = gaTransTblDigits[ get_trans_index( caTmp[3] ) ];
	buf[5] = gaTransTblDigits[ get_trans_index( caTmp[4] ) ];
	
	
	
	//printf("buf: 0x%02x : %02x %02x %02x %02x %02x\n", buf[0], buf[1],buf[2],buf[3],buf[4],buf[5] );

	res = hid_write( handle, buf, 8 );
	if (res < 0)
		printf("Unable to write..\n");	



}




void set_leds( hid_device *handle, unsigned char a, unsigned char b, unsigned char c  ){

	unsigned char buf[buf_size];
	

		memset( buf, 0, buf_size );
		buf[0] = MCP_BTNS;		
		
		buf[1] = 0;
		
		//byte ordering makes no sense relative to physical layout
		buf[2] = a;// lower
		buf[3] = b;// midde
		buf[4] = c;// top row of LED's
		
		buf[5] = 0;
		
		hid_write( handle, buf, 16 );

}


void xsleep( int x ){
	usleep( x * 1000 );
}


int flag_vnav = 0;
int hdg=45;
	

int main( int argc, char* argv ){

	printf( "MCP Pro Hackery v0.5\n" );

	hid_device *handle = hid_open( GOFLIGHT, MCP_PRO, NULL );
	if( handle == 0 ){
		printf("dev busy: sudo?\n");
		exit(0);
	}


	// Read the Manufacturer String
    res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
    printf("Maker: %ls\n", wstr);

    // Read the Product String
    res = hid_get_product_string(handle, wstr, MAX_STR);
    printf("Product: %ls\n", wstr);

    // Read the Serial Number String
    res = hid_get_serial_number_string(handle, wstr, MAX_STR);
    printf("Serial: %ls", wstr);
    printf("\n");







	printf("static packet..\n");
	printf("size of uint: %d\n", sizeof(unsigned long));



	set3f( handle, MCP_CRS_LEFT, 888 );
	
	set5f( handle, MCP_IAS, 88888 );
	
	set3f( handle, MCP_HDG, 888 );
	
	set5f( handle, MCP_ALT, 88888 );
	
	set5f( handle, MCP_VS, 88888 );		
	
	set3f( handle, MCP_CRS_RIGHT, 888 );



	xsleep( 1000 );




	set3f( handle, MCP_CRS_LEFT, 45 );
	
	set5f( handle, MCP_IAS, 123 );
	
	set3f( handle, MCP_HDG, 45 );
	
	set5f( handle, MCP_ALT, 1234 );
	
	set5f( handle, MCP_VS, 5678 );		
	
	set3f( handle, MCP_CRS_RIGHT, 45 );


	
	

	
	
	
	
	

/*	
		char caTmp[8];
	snprintf( caTmp, 8, "%05d", value );
	//printf( "set5f string:(%s)\n", caTmp);
	
	
	unsigned char buf[buf_size];
	
	memset( buf, 0, buf_size );
	buf[0] = target; //MCP_CRS_LEFT;
	
	buf[1] = gaTransTblDigits[ get_trans_index( caTmp[0] ) ];
	buf[2] = gaTransTblDigits[ get_trans_index( caTmp[1] ) ];
	buf[3] = gaTransTblDigits[ get_trans_index( caTmp[2] ) ];
	buf[4] = gaTransTblDigits[ get_trans_index( caTmp[3] ) ];
	buf[5] = gaTransTblDigits[ get_trans_index( caTmp[4] ) ];
	
	
	
	//printf("buf: 0x%02x : %02x %02x %02x %02x %02x\n", buf[0], buf[1],buf[2],buf[3],buf[4],buf[5] );

	res = hid_write( handle, buf, 8 );
	if (res < 0)
		printf("Unable to write..\n");	

*/


	unsigned char buf[buf_size];
	memset( buf, 0, buf_size );

	set3f( handle, MCP_HDG, hdg );





// used to figure out the button combos.
	unsigned int a = 1;
	unsigned int b = 2;
	unsigned int c = 4;
	unsigned int d = 8;
	unsigned int e = 16;
	unsigned int f = 32;
	unsigned int g = 64;
	unsigned int h = 128;
	
	
	unsigned char btn_a = 0 | b | c | d | e | f | g | h;
	unsigned char btn_b = a | 0 | c | d | e | f | g | h;
	unsigned char btn_c = a | b | 0 | d | e | f | g | h;
	unsigned char btn_d = a | b | c | 0 | e | f | g | h;
	unsigned char btn_e = a | b | c | d | 0 | f | g | h;
	unsigned char btn_f = a | b | c | d | e | 0 | g | h;
	unsigned char btn_g = a | b | c | d | e | f | 0 | h;
	unsigned char btn_h = a | b | c | d | e | f | g | 0;
	

	unsigned char btns_loop[] = { 
		btn_a, btn_b, btn_c, btn_d,
		btn_e, btn_f, btn_g, btn_h
		};





	//reset our lights.
	set_leds( handle, 255, 255, 255 );
	xsleep( 1000 );
	set_leds( handle, 0, 0, 0 );





	printf("read loop..\n");
	while(1){
	
		memset( buf, 0, buf_size );
	
		// Read requested state
        res = hid_read(handle, buf, 16);
        if (res < 0){
            printf("Unable to read()\n");

        }else{
        
            // Print out the returned buffer.
            for(int i = 0; i < res; i++) {
                printf("% 4d    ", buf[i]);
                //printf("%d  % 4d    ", i, buf[i]);
                
            }

            if( res > 0 ) {
            	//a report has been rxd and dumped, we should put a new line
                printf("\n");
            }            
            
            
            //parse the report fields.
            
            
            //parse for CRS_RIGHT knob
	             if( buf[3] == 1 || buf[3] == 2 ){
                	hdg++;
                	
            	}else if( buf[3] == 14 || buf[3] == 15 ){
            		hdg--;
            		
            	}
            
            

				//VNAV button pressed            
            	if( buf[7] & 1 ){
            		//turn VNAV led ON
            		
            		if( flag_vnav ){
            			//turn off
            			flag_vnav = 0;
            		}else{
            			//turn on
            			flag_vnav = 1;
            		}
            		
            		
            	}
            
            
        } //checking for packet read
	
	
	

		// push data back to the device.
		const int max = 359;
		if( hdg > max ){ hdg = 0; };
		if( hdg < 0 ){ hdg = max; };
		
		set3f( handle, MCP_HDG, hdg );
		set3f( handle, MCP_CRS_RIGHT, hdg );
		
		
		unsigned char a,b,c;
		
		if( flag_vnav ){			
			a = 0;
			b = 0;
			c = 1;			
			
		}else{
			a = 0;
			b = 0;
			c = 0;			
			
		}
		set_leds( handle, a,b,c );
	

		
	
		usleep(10 * 1000);
	}	
	
	
	
	
	

	return 1;
}
