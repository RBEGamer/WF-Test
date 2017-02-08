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

#define MO_LINUX
#include "debug_logger/debug_logger.h"

#include "bitmap_loader/bitmap.h"



int main(int argc, char* argv[]){

std::cout << "WF SERVER TEST " << std::endl;


   FRM::debug_logger::get_instance()->enable_direct_print = true;
  // FRM::debug_logger::get_instance()->log_info("res", "42");
//OPEN THE SPI PORT

   //SEND MATRIX CONFIG TO FPGA
BitMap example_bmp("test.bmp");
//example_bmp.dispPixelData();
for (size_t y = 0; y < 32; y++) {
  for (size_t x = 0; x < 32; x++) {
    std::vector<unsigned int> example_vector = example_bmp.getPixel(x,y);

  }
}
   //GOTO MAINLOOP







std::cout << std::endl;
}
