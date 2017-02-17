// WF SERVER MAIN

#define FRM_LINUX
#define FRM_ARCH_ARM
#define FRM_RPI




#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>



#include "wf_config.h"
//bit set clear
#include "helper/bitoperations.h"
//to execute some shell cmds
//#include "helper/linux_shell_cmd.cpp"
//ini parser for config
#define INI_PARSER_USE_STD_MAP
//#include "ini_parser/ini_parser.h"
//debug logger for html logging
//#define FRM_LINUX
//#include "debug_logger/debug_logger.h"

//#include "bitmap_loader/bitmap.h"
//spi interface for pi
#include "rpi_spi_lib/rpi_spi_lib.h"












int main(int argc, char* argv[]){

std::cout << "WF SERVER TEST " << std::endl;


   //FRM::debug_logger::get_instance()->enable_direct_print = true;


   rpi_spi* spi0 = new rpi_spi(0,0,8,500000);


unsigned char test_data* = new unsigned char[2]();

*(test_data+0) = 65;
 *(test_data+1) = 42;  

//C0 C1 C2 C3 C4 R G B      Y,Y,Y,Y X,X,X,X

BIT_SET(test_data[1], 0); //BLUE
BIT_SET(test_data[0], 0); // 1
BIT_SET(test_data[0], 4); // 1

spi0->write_read(test_data,2);
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
