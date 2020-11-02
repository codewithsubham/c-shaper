#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
RenderArea::RenderArea(QWidget *parent) : QWidget(parent) , main_shape (shape1) , main_shape_color(255 , 255 , 255) , step_count(0) , scale(0) , interval_length(0)
{
    changeShape();
}

QSize RenderArea::minimunSizeHint() const
{
    return  QSize(100 , 100);
}

QSize RenderArea::sizeHint() const
{
    return  QSize(400 , 200) ;
}

void RenderArea::computeShape(float point){
    switch (main_shape) {
    case shape1:
        drawAsteroids(point);
        break;
    case shape2:
        drawCycloid(point);
        break;
    case shape3:
        drawHuygen(point);
        break;
    case shape4:
        drawHypo(point);
        break;
    default:
        break;
    }



}
void  RenderArea::drawAsteroids(float point)
{
    // this function computer for Asteroids shaope and set the value of private member of rendarea.h MQpointf();

     this->MQPointF.setX(2 * pow(cos(point) , 3));
     this->MQPointF.setY(2 * pow(sin(point) , 3));

}

void RenderArea::drawHuygen(float point){
    this->MQPointF.setX(4 * (3 * cos(point) - cos(3 * point)));
    this->MQPointF.setY(4 * (3 * sin(point) - sin(3 * point)));
}

void RenderArea::drawHypo(float point){
    this->MQPointF.setX(1.5 * (2 * cos(point) + cos(2 * point)));
    this->MQPointF.setY(1.5 * (2 * sin(point) - sin(2 * point)));
}

void RenderArea::drawCycloid(float point){

    this->MQPointF.setX(1.5 * (1 - cos(point)));
    this->MQPointF.setY(1.5 * (point - sin(point)));

}

void RenderArea::changeShape()
{

    switch (main_shape) {
    case shape1:
        main_render_backgroundcolor = {255 ,0 ,0};
        this->step_count = 400;
        this->scale = 40;
        this->interval_length = 2 * M_PI;
        break;
    case shape2:
        main_render_backgroundcolor = {0 , 0 , 255};
        this->step_count = 256;
        this->scale = 4;
        this->interval_length = 6 * M_PI;
        break;
    case shape3:
        this->step_count = 256;
        this->scale = 4;
        this->interval_length = 4 * M_PI;
        main_render_backgroundcolor = {0 , 255 , 0};
        break;
    case shape4:
        this->step_count = 256;
        this->scale = 15;
        this->interval_length = 2 * M_PI;
        main_render_backgroundcolor = {225 , 255 , 0};
        break;
    default:
        break;
    }
}


void RenderArea::paintEvent(QPaintEvent *E)
{
    Q_UNUSED(E);


    QPainter painter(this);
    QPen pen;
    painter.setRenderHint(QPainter::Antialiasing , true);
    painter.setBrush(this->main_shape_color);

    painter.drawRect(this->rect());
    pen.setMiterLimit(20);
    pen.setWidth(2);
    pen.setBrush(this->main_render_backgroundcolor);

    painter.setPen(pen);

    QPoint center = this->rect().center();
    float step =  interval_length / step_count;

    computeShape(0);
    QPointF saveLastPoint(this->MQPointF.x() * this->scale + center.x(), this->MQPointF.y() * this->scale + center.y());




    for(float i = 0 ; i < interval_length; i += step){

        computeShape(i);
        QPoint pixel;

        pixel.setX(this->MQPointF.x() * scale + center.x());
        pixel.setY(this->MQPointF.y() * scale + center.y());

        painter.drawLine(pixel , saveLastPoint);
        saveLastPoint.setX(this->MQPointF.x() * scale + center.x());
        saveLastPoint.setY(this->MQPointF.y() * scale + center.y());

    }

}
