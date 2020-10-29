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
protected:
    void paintEvent(QPaintEvent *E) Q_DECL_OVERRIDE;

signals:

private:
    QColor main_render_backgroundcolor;
    QColor main_shape_color;



};

#endif // RENDERAREA_H
