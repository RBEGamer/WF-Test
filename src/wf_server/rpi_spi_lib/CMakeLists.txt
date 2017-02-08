# CMAKE LISTS TXT FOR INI PARSER
cmake_minimum_required(VERSION 2.7)
project(FRM_RPI_SPI_LIB)
file(GLOB Sources "*.cpp")
ADD_LIBRARY( _rpi_spi STATIC ${Sources})
TARGET_LINK_LIBRARIES( _rpi_spi )
