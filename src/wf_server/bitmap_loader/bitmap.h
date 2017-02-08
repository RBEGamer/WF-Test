#ifndef BMP_H
#define BMP_H

#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>
class BitMap {

    private:
        unsigned char m_bmpFileHeader[14];
        unsigned int m_pixelArrayOffset;
        unsigned char m_bmpInfoHeader[40];

        int m_height;
        int m_width;
        int m_bitsPerPixel;

        int m_rowSize;
        int m_pixelArraySize;

        unsigned char* m_pixelData;

        char * m_copyname;
        const char * m_filename;
    public:
        BitMap(const char * filename);
        ~BitMap();

        std::vector<unsigned int> getPixel(int i,int j);

        void makeCopy(char * filename);
        void writePixel(int i,int j, int R, int G, int B);

        void swapPixel(int i, int j, int i2, int j2);

        void dispPixelData();

        int width() {return m_width;}
        int height() {return m_height;}

        int vd(int i, int j);
        int hd(int i, int j);

        bool isSorted();
};
#endif
