//
//  rpi_spi_lib.hpp
//
//
//  Created by Marcel Ochsendorf on 08.02.17.
//
//

#ifndef rpi_spi_lib_hpp
#define rpi_spi_lib_hpp

#include <stdio.h>


#include <fcntl.h>                // Needed for SPI port
#include <sys/ioctl.h>            // Needed for SPI port
#include <linux/spi/spidev.h>     // Needed for SPI port


class rpi_spi{

public:

rpi_spi(int _device_id, uint8_t _mode, uint8_t _wordlen, _uint32_t _speed);
rpi_spi();
~rpi_spi();

int write_read (unsigned char *data, int length);
int _close();
int _open();

private:
  char* use_device;
  const char *device_0 = "/dev/spidev0.0";
  const char *device_1 = "/dev/spidev0.0";
  static uint8_t mode;
  static uint8_t bits;
  static uint32_t speed;
  static uint16_t delay;
  int ret;
  int fd;
};



#endif /* rpi_spi_lib_hpp */
