#include "gifexporter.h"
#include "image.h"

#include <QImage>

GifExporter::GifExporter()
{
    QString test;
}

bool GifExporter::exportToGIF(const QString& fileName, const QVector<QImage*>& images, int width, int height)
{
    QVector<uint8_t*> bufferVector;

    GifWriter writer;
    GifBegin(&writer, fileName.toStdString().c_str(), width, height, 10);


    foreach (QImage* image, images)
    {
        Image* outputFrame = new Image(image);

        const int rgbaSize = 4;
        uint8_t* outputFrameBuffer = new uint8_t[ outputFrame->getWidth() * outputFrame->getHeight() * rgbaSize ];

        outputFrame->getBufferRGBA8( outputFrameBuffer );

        bufferVector.push_back( outputFrameBuffer );

        GifWriteFrame( &writer,
                               outputFrameBuffer,
                               outputFrame->getWidth(),
                               outputFrame->getHeight(), 10 );

        delete outputFrame;
        delete[] outputFrameBuffer;

//        QByteArray alpha8((char *) image->bits(),image->byteCount());
//        GifWriteFrame(&writer, (uint8_t *)alpha8.data(), width, height, 10);
    }

    GifEnd(&writer);

}
