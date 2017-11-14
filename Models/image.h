/*
 * 2016 - Marco Aurélio G. da Silva ( marcoc2@gmail.com )
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include "Pixel.h"

#ifdef _WIN32
#define u_int uint32_t
#define u_char uint8_t
#elif defined __clang__
typedef uint32_t u_int;
typedef uint8_t u_char;
#endif

class Image
{
public:

    Image();
    Image( u_int width, u_int height );
    Image( QImage* qImage );
    Image( const char* fileName );
    ~Image();
    u_int getSize();
    u_int getWidth();
    u_int getHeight();
    QImage* getQImage();
    QImage* getQImageFromBuffer();
    void getBufferRGBA8( uint8_t* buffer);
    void fillBufferRGB();


private:

    Pixel* _buffer;
    QImage* _qImage;
    u_int _size;
    u_int _width;
    u_int _height;
    u_int _widthStep;
    u_int _nChannels;
};

#endif // IMAGE_H
