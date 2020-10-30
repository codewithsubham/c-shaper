#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent) , main_render_backgroundcolor(255,22 , 255) , main_shape_color(255 , 255 , 255)
{

}

QSize RenderArea::minimunSizeHint() const
{
    return  QSize(100 , 100);
}

QSize RenderArea::sizeHint() const
{
    return  QSize(400 , 200) ;
}



void RenderArea::paintEvent(QPaintEvent *E)
{
    QPainter painter(this);
    painter.setBrush(this->main_render_backgroundcolor);

    painter.setRenderHint(QPainter::Antialiasing , true);

    painter.setPen(this->main_shape_color);
    painter.drawRect(this->rect());
    painter.drawLine(this->rect().topLeft() , this->rect().bottomRight()/2);

    painter.drawLine(this->rect().bottomRight()/2, this->rect().bottomLeft());
}
