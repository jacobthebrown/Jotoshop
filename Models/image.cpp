/*
 * Created by:
 * 2016 - Marco Aurélio G. da Silva ( marcoc2@gmail.com )
 */

#include <stdio.h>
#include "Image.h"

Image::Image() :
    _buffer( 0 ),
    _qImage( 0 ),
    _size( 0 ),
    _width( 0 ),
    _height( 0 ),
    _widthStep( 0 ),
    _nChannels( 0 )
{
}


Image::Image( u_int width, u_int height ) :
    _size( width * height ),
    _width( width ),
    _height( height ),
    _widthStep( width )
{
    _qImage = new QImage( width, height, QImage::Format_RGB888 ),
    _nChannels = _qImage->depth() / 8; //sizeof(uchar);
    _buffer = new Pixel[ _size ];
}


Image::Image( QImage* qImage ) :
    _qImage( qImage ),
    _size( qImage->size().width() * qImage->size().height() ),
    _width( qImage->width() ),
    _height( qImage->height() ),
    _widthStep( qImage->bytesPerLine() / ( qImage->depth() / 8 ) ),
    _nChannels( qImage->depth() / 8 )
{
    //_buffer = reinterpret_cast<Pixel*>( _qImage->bits() );
    _buffer = new Pixel[ _size ];
    fillBufferRGB();
}


Image::Image( const char* fileName )
{
    _qImage = new QImage( fileName );
    if( _qImage->isNull() )
    {
        return;
    }
    _size = _qImage->size().width() * _qImage->size().height();
    _width = _qImage->width();
    _height = _qImage->height();
    _widthStep = _qImage->bytesPerLine() / ( _qImage->depth() / 8 );
    _nChannels = _qImage->depth() / 8;
    //_buffer = reinterpret_cast<Pixel*>( _qImage->bits() );

    _buffer = new Pixel[ _size ];
    fillBufferRGB();
}


Image::~Image()
{
    delete[] _buffer;
    delete _qImage;
}


u_int Image::getSize()
{
    return _size;
}


u_int Image::getWidth()
{
    return _width;
}


u_int Image::getHeight()
{
    return _height;
}


void Image::getBufferRGBA8( uint8_t* buffer)
{
    for( size_t i = 0; i < ( _width * _height ); i++ )
    {
        size_t j = i * 4;
        buffer[ j ] = _buffer[ i ].red;
        buffer[ j + 1 ] = _buffer[ i ].green;
        buffer[ j + 2 ] = _buffer[ i ].blue;
        buffer[ j + 3 ] = 255;
    }
}


void Image::fillBufferRGB()
{
    #pragma omp for
    for( u_int w = 0; w < _width; w++ )
    {
        for( u_int h = 0; h < _height; h++ )
        {
            unsigned int index = ( h * _widthStep ) + ( w );
            QRgb pixel = _qImage->pixel( w, h );
            _buffer[ index ].red = ( u_char ) qRed( pixel );
            _buffer[ index ].green = ( u_char ) qGreen( pixel );
            _buffer[ index ].blue = ( u_char ) qBlue( pixel );
        }
    }
}

