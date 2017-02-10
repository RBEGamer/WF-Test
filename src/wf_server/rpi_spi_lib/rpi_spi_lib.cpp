//
//  rpi_spi_lib.cpp
//
//
//  Created by Marcel Ochsendorf on 08.02.17.
//
//

#include "rpi_spi_lib.h"

//#define TODO #error "bla"




rpi_spi(int _device_id, uint8_t _mode, uint8_t _wordlen, _uint32_t _speed){
  mode = _mode;
  bits = _wordlen;
  speed = _speed;
  switch (_device_id) {
    case 0:use_device = device_0; break;
    case 1:use_device = device_1;break;
    default:use_device = device_0;break;
  }
_open();
}
rpi_spi(){
bits = 8;
mode = 0660;
speed = 500000;
use_device = device_0;
_open();
}


~rpi_spi(){
if(fd >= 0){
  ret = close(fd);
}
}

int write_read (unsigned char *data, int length){
  struct spi_ioc_transfer spi[length]; /* Bibliotheksstruktur fuer Schreiben/Lesen */

  	int i, ret;                          /* Zaehler, Returnwert */

    /* Wortlaenge abfragen */
    ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
    if (ret < 0)
      {
      perror("Fehler Get Wortlaenge");
      exit(1);
      }

    /* Datenrate abfragen */
    ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
    if (ret < 0)
      {
      perror("Fehler Get Speed");
      exit(1);
      }
    /* Daten uebergeben */
  	for (i = 0; i < length; i++)
  	  {
  		spi[i].tx_buf        = (unsigned long)(data + i); // transmit from "data"
  		spi[i].rx_buf        = (unsigned long)(data + i); // receive into "data"
  		spi[i].len           = sizeof(*(data + i));
  		spi[i].delay_usecs   = 0;
  		spi[i].speed_hz      = speed;
  		spi[i].bits_per_word = bits;
  		spi[i].cs_change     = 0;
  	  }
  	ret = ioctl(fd, SPI_IOC_MESSAGE(length), &spi) ;
  	if(ret < 0)
      {
  		perror("Fehler beim Senden/Empfangen - ioctl");
  		exit(1);
      }
  	return ret;
}

int _close(){
  return close(fd);
}

int _open(){
  /* Device oeffen */
  if ((fd = open(use_device, O_RDWR)) < 0)
    {
    perror("Fehler Open Device");
    exit(1);
    }
  /* Mode setzen */
  ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
  if (ret < 0)
    {
    perror("Fehler Set SPI-Modus");
    exit(1);
    }

  /* Mode abfragen */
  ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
  if (ret < 0)
    {
    perror("Fehler Get SPI-Modus");
    exit(1);
    }

  /* Wortlaenge setzen */
  ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
  if (ret < 0)
    {
    perror("Fehler Set Wortlaenge");
    exit(1);
    }

  /* Wortlaenge abfragen */
  ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
  if (ret < 0)
    {
    perror("Fehler Get Wortlaenge");
    exit(1);
    }

  /* Datenrate setzen */
  ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
  if (ret < 0)
    {
    perror("Fehler Set Speed");
    exit(1);
    }

  /* Datenrate abfragen */
  ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
  if (ret < 0)
    {
    perror("Fehler Get Speed");
    exit(1);
    }

  /* Kontrollausgabe */
  printf("SPI-Device.....: %s\n", device);
  printf("SPI-Mode.......: %d\n", mode);
  printf("Wortlaenge.....: %d\n", bits);
  printf("Geschwindigkeit: %d Hz (%d kHz)\n", speed, speed/1000);

return fd;
}
