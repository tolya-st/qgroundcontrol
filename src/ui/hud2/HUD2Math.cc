#include "HUD2Math.h"

int percent2pix_h(QSize size, qreal percent){
    return round(percent * size.height() / 100.0);
}

int percent2pix_w(QSize size, qreal percent){
    return round(percent * size.width() / 100.0);
}

int percent2pix_d(QSize size, qreal percent){
    qreal d; // diagonal
    d = sqrt(size.width() * size.width() + size.height() * size.height());
    return round(percent * d / 100.0);
}

qreal percent2pix_hF(QSize size, qreal percent){
    return percent * size.height() / 100.0;
}

qreal percent2pix_wF(QSize size, qreal percent){
    return percent * size.width() / 100.0;
}

qreal percent2pix_dF(QSize size, qreal percent){
    qreal d; // diagonal
    d = sqrt(size.width() * size.width() + size.height() * size.height());
    return percent * d / 100.0;
}

qreal rad2deg(qreal rad){
    return rad * (180.0 / M_PI);
}

qreal deg2rad(qreal deg){
    return (deg * M_PI) / 180.0;
}

/**
 * @brief rotatePoint
 * @param phi           angle in degrees
 * @param p
 * @return
 */
QPoint rotatePoint(qreal phi, QPoint p){
    qreal x = p.x();
    qreal y = p.y();
    qreal x_, y_;

    x_ = round(x * cos(deg2rad(phi)) - y * sin(deg2rad(phi)));
    y_ = round(x * sin(deg2rad(phi)) + y * cos(deg2rad(phi)));

    return QPoint(x_, y_);
}

QPointF rotatePoint(qreal phi, QPointF p){
    qreal x = p.x();
    qreal y = p.y();
    qreal x_, y_;

    x_ = (x * cos(deg2rad(phi)) - y * sin(deg2rad(phi)));
    y_ = (x * sin(deg2rad(phi)) + y * cos(deg2rad(phi)));

    return QPointF(x_, y_);
}

QLine rotateLine(qreal phi, QLine line){
    return QLine(rotatePoint(phi, line.p1()), rotatePoint(phi, line.p2()));
}

QLineF rotateLine(qreal phi, QLineF line){
    return QLineF(rotatePoint(phi, line.p1()), rotatePoint(phi, line.p2()));
}

/**
 * @brief wrap_360
 * @param angle
 * @return
 */
double wrap_360(double angle){
    if (angle > 360)
        angle -= 360;
    else if (angle < 0)
        angle += 360;
    else if (angle == 360)
        angle = 0;
    return angle;
}

/**
 * @brief wrap_360
 * @param angle
 * @return
 */
int wrap_360(int angle){
    if (angle > 360)
        angle -= 360;
    else if (angle < 0)
        angle += 360;
    else if (angle == 360)
        angle = 0;
    return angle;
}

/**
 * @brief modulusF
 * @param dividend
 * @param divisor
 * @return
 */
double modulusF(double dividend, double divisor){
    double n = floor(dividend / divisor);
    return dividend - n * divisor;
}

