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




int main(int argc, char* argv[]){

std::cout << "WF SERVER TEST " << std::endl;


   FRM::debug_logger::get_instance()->enable_direct_print = true;
   FRM::debug_logger::get_instance()->log_info("res", "42");
//OPEN THE SPI PORT

   //SEND MATRIX CONFIG TO FPGA


   //GOTO MAINLOOP



   //CLEANUP
   delete  parser;
   parser = nullptr;



std::cout << std::endl;
}
