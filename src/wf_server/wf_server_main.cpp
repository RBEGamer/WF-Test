// WF SERVER MAIN

#define PLATTFORM_LINUX
#define ARCH_ARM




#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

#include "wf_config.h"

#define INI_PARSER_USE_STD_MAP
#include "ini_parser/ini_parser.h"

#define FRM_LINUX
#include "debug_logger/debug_logger.h"

//#include "bitmap_loader/bitmap.h"

#include "rpi_spi_lib/rpi_spi_lib.h"







/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1<<(b)))
#define BIT_CHECK(a,b) ((a) & (1<<(b)))

/* x=target variable, y=mask */
#define BITMASK_SET(x,y) ((x) |= (y))
#define BITMASK_CLEAR(x,y) ((x) &= (~(y)))
#define BITMASK_FLIP(x,y) ((x) ^= (y))
#define BITMASK_CHECK(x,y) (((x) & (y)) == (y))



int main(int argc, char* argv[]){

std::cout << "WF SERVER TEST " << std::endl;


   FRM::debug_logger::get_instance()->enable_direct_print = true;


   rpi_spi* spi0 = new rpi_spi(0,0,8,500000);


char test_data[2] = {0,0};


//C0 C1 C2 C3 C4 R G B      Y,Y,Y,Y X,X,X,X

BIT_SET(test_data[1], 0); //BLUE
BIT_SET(test_data[0], 0); // 1
BIT_SET(test_data[0], 4); // 1

spi0->write_read(&test_data,2);
  // FRM::debug_logger::get_instance()->log_info("res", "42");
//OPEN THE SPI PORT

   //SE MATRIX CONFIG TO FPGA
//BitMap example_bmp("test.bmp");
//example_bmp.dispPixelData();
for (size_t y = 0; y < 32; y++) {
  for (size_t x = 0; x < 32; x++) {
    //std::vector<unsigned int> example_vector = example_bmp.getPixel(x,y);

//SEND PIXEL VIA SPI WITH POS
  }
}
   //GOTO MAINLOOP





delete spi0;


std::cout << std::endl;
}
