/* Webcamod, webcam capture plasmoid.
 * Copyright (C) 2011-2012  Gonzalo Exequiel Pedone
 *
 * Webcamod is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamod is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamod. If not, see <http://www.gnu.org/licenses/>.
 *
 * Email     : hipersayan DOT x AT gmail DOT com
 * Web-Site 1: http://github.com/hipersayanX/Webcamoid
 * Web-Site 2: http://kde-apps.org/content/show.php/Webcamoid?content=144796
 */

#ifndef VIDEOSTREAM_H
#define VIDEOSTREAM_H

#include <QtGui>

extern "C"
{
    #include <libswscale/swscale.h>
}

#include "abstractstream.h"

class VideoStream: public AbstractStream
{
    Q_OBJECT

    public:
        explicit VideoStream(QObject *parent=NULL);
        VideoStream(AVFormatContext *formatContext, uint index);
        VideoStream(const VideoStream &other);
        ~VideoStream();

        VideoStream &operator =(const VideoStream &other);

        Q_INVOKABLE QImage readFrame(AVPacket *packet);

    private:
        struct SwsContext *m_scaleContext;
        AVFrame *m_picture;
        AVFrame *m_pictureRgb;
        uint8_t *m_bufferRgb;
};

#endif // VIDEOSTREAM_H