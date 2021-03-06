#ifndef HUD2RENDERNATIVE_H
#define HUD2RENDERNATIVE_H

#include <QWidget>
#include "HUD2Data.h"
#include "HUD2Drawer.h"

class HUD2Drawer;
QT_BEGIN_NAMESPACE
class QPaintEvent;
QT_END_NAMESPACE

class HUD2RenderNative : public QWidget
{
    Q_OBJECT

public:
    HUD2RenderNative(HUD2Drawer *huddrawer, QWidget *parent);

signals:
    void geometryChanged(const QSize *size);

public slots:
    void paint(void);
    void toggleAntialiasing(bool aa);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    HUD2Drawer *huddrawer;
    bool antiAliasing;
    QPalette plt;
};

#endif /* HUD2RENDERNATIVE_H */
