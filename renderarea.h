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

    void setBackgroundColor(QColor color){ this->main_render_backgroundcolor =  color;};

    void set_main_shape_color(QColor color){ this->main_shape_color =  color;};

    QColor getBackgroundColor() const {return this->main_render_backgroundcolor;};
protected:
    void paintEvent(QPaintEvent *E) Q_DECL_OVERRIDE;

signals:

private:
    QColor main_render_backgroundcolor;
    QColor main_shape_color;



};

#endif // RENDERAREA_H
