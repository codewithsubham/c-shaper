#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    QSize minimunSizeHint() const;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum Render_shapes { shape1 ,shape2 ,shape3 ,shape4};
    void setBackgroundColor(QColor color){ this->main_render_backgroundcolor =  color;};

    void set_shape(Render_shapes shape){main_shape = shape;};

    Render_shapes get_shape(){return main_shape;};

    QColor getBackgroundColor() const {return this->main_render_backgroundcolor;};
protected:
    void paintEvent(QPaintEvent *E) Q_DECL_OVERRIDE;

signals:

private:
    QColor main_render_backgroundcolor;
    QColor main_shape_color;
    Render_shapes main_shape;


};

#endif // RENDERAREA_H
