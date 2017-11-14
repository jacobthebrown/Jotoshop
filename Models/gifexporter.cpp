#include "gifexporter.h"
#include "image.h"

#include <QImage>

/*
 * GIF Exporter which uses the gif-h and Image libraries created by
 * Charlie Tangora and Marco Aurélio G. da Silva respectively to export a
 * vector of QImage* frames to a GIF format
 */
GifExporter::GifExporter()
{
}

/*
 * Slot for an exportToGIF signal from the main window. Loops through each QImage* in images, converts it into
 * a frame for of the gif, combines the frames and cleans up
 */
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
    }

    return GifEnd(&writer);

}
