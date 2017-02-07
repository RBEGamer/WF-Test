// WF SERVER MAIN

#define PLATTFORM_LINUX
#define ARCH_ARM




#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>


#include "ini_parser/ini_parser.h"

int main(int argc, char* argv[]){

std::cout << "WF SERVER TEST " << std::cin;




   FRM::ini_parser* parser = new FRM::ini_parser();
   parser->load_ini_file("wf_basic_conf.ini");
   std::string* test =parser->get_value("spi_settings", "spi_speed");
   std::string* test1 =parser->get_value("spi_settings", "spi_mode");
   std::string* test2 =parser->get_value("spi_settings", "spi_port");
   delete  parser;
   parser = nullptr;



std::cout << std::endl;
}
