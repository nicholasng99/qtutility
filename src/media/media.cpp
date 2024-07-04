#include "QtUtility/media/media.hpp"

QIcon Media::recolor(const QIcon &icon, const QColor &color, const QSize &size)
{
    return QIcon(recolor(icon.pixmap(size), color));
}

QPixmap Media::recolor(const QPixmap &pixmap, const QColor &color)
{
    return QPixmap::fromImage(recolor(pixmap.toImage(), color));
}

QImage Media::recolor(const QImage &image, const QColor &color)
{
    QImage result(image.size(), image.format());
    auto mutableColor = color; // necessary to reassign alpha value
    for (int y = 0; y < image.height(); y++)
        for (int x = 0; x < image.width(); x++)
        {
            mutableColor.setAlpha(image.pixelColor(x, y).alpha());
            result.setPixelColor(x, y, mutableColor);
        }
    return result;
}
