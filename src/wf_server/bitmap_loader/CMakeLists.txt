# CMAKE LISTS TXT FOR INI PARSER
cmake_minimum_required(VERSION 2.7)
project(FRM_BITMAP_LOADER_LIB)
file(GLOB Sources "*.cpp")
ADD_LIBRARY( _bitmap_loader STATIC ${Sources})
TARGET_LINK_LIBRARIES( _bitmap_loader )
