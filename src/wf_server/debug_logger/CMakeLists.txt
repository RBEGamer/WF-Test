# CMAKE LISTS TXT FOR INI PARSER
cmake_minimum_required(VERSION 2.7)
project(FRM_DEBUG_LOGGER)
file(GLOB Sources "*.cpp")
ADD_LIBRARY( _debug_logger STATIC ${Sources})
TARGET_LINK_LIBRARIES( _debug_logger )
