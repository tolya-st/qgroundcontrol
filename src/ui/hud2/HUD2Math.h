#ifndef HUD2MATH_H
#define HUD2MATH_H

#include <math.h>
#include <QSize>
#include <QLine>

int percent2pix_h(QSize size, qreal percent);
int percent2pix_w(QSize size, qreal percent);
int percent2pix_d(QSize size, qreal percent);
qreal percent2pix_hF(QSize size, qreal percent);
qreal percent2pix_wF(QSize size, qreal percent);
qreal percent2pix_dF(QSize size, qreal percent);

qreal rad2deg(qreal rad);
qreal deg2rad(qreal deg);
QPoint rotatePoint(qreal phi, QPoint p);
QPointF rotatePoint(qreal phi, QPointF p);
QLine rotateLine(qreal phi, QLine line);
QLineF rotateLine(qreal phi, QLineF line);
double wrap_360(double angle);
int wrap_360(int angle);
double modulusF(double dividend, double divisor);

#endif // HUD2MATH_H
