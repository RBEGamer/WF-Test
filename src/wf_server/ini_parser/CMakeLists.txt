# CMAKE LISTS TXT FOR INI PARSER
cmake_minimum_required(VERSION 2.7)
project(FRM_INI_PARSER_LIB)
file(GLOB Sources "*.cpp")
ADD_LIBRARY( _ini_parser STATIC ${Sources})
TARGET_LINK_LIBRARIES( _ini_parser )
