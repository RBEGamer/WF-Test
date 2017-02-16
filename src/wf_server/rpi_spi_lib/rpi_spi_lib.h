//
//  rpi_spi_lib.hpp
//
//
//  Created by Marcel Ochsendorf on 08.02.17.
//
//

#ifndef rpi_spi_lib_hpp
#define rpi_spi_lib_hpp

#include <fcntl.h>				//Needed for SPI port
#include <sys/ioctl.h>			//Needed for SPI port
#include <linux/spi/spidev.h>	//Needed for SPI port
#include <unistd.h>			//Needed for SPI port
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <cstring>


class rpi_spi{

public:

rpi_spi(unsigned char _device_id, unsigned char _mode, unsigned char _wordlen, unsigned int _speed);
rpi_spi();
~rpi_spi();

int write_read (unsigned char *data, int length);
int _close();
int _open();

private:
 int spi_cs0_fd;				//file descriptor for the SPI device
int spi_cs1_fd;				//file descriptor for the SPI device
unsigned char spi_mode;
unsigned char spi_bitsPerWord;
unsigned int spi_speed;
int spi_device;
};



#endif /* rpi_spi_lib_hpp */
