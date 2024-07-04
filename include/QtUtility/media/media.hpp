#pragma once

#include <QIcon>
#include <QPixmap>
#include <QImage>

namespace Media
{
    // recolor all non transparent pixels to the chosen color
    QIcon recolor(const QIcon &icon, const QColor &color, const QSize &size = QSize(256, 256));
    QPixmap recolor(const QPixmap &pixmap, const QColor &color);
    QImage recolor(const QImage &image, const QColor &color);
}