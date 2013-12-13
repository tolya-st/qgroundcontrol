#ifndef HUD2RIBBON_H
#define HUD2RIBBON_H

#include <QWidget>
#include <QPen>
#include <QFont>

#include "HUD2Data.h"

typedef enum {
    POSITION_LEFT = 0,
    POSITION_RIGHT = 1,
    POSITION_TOP = 2,
    POSITION_BOTTOM = 3
}screen_position;

class HUD2Ribbon : public QWidget
{
    Q_OBJECT
public:
    explicit HUD2Ribbon(screen_position position, bool wrap360, QString name, QWidget *parent);
    void paint(QPainter *painter);
    bool getOpacityNeedle(void){return opaqueNeedle;}
    bool getOpacityRibbon(void){return opaqueRibbon;}
    bool getOpacityTags(void){return opaqueTags;}
    bool getEnabled(void){return enabled;}
    double getBigScratchLenStep(void){return bigScratchLenStep;}
    int getBigScratchValueStep(void){return bigScratchValueStep;}
    int getStepsSmall(void){return stepsSmall;}
    int getStepsBig(void){return stepsBig / 2;}

signals:
    void geometryChanged(const QSize *size);

public slots:
    void updateGeometry(const QSize &size);
    void setColor(QColor color);
    void setOpacityNeedle(bool op);
    void setOpacityRibbon(bool op);
    void setOpacityTags(bool op);
    void setEnabled(bool checked);
    void setBigScratchLenStep(double);
    void setBigScratchValueStep(int);
    void setStepsSmall(int);
    void setStepsBig(int);
    void syncSettings(void);

private:
    void updateRibbon(const QSize &size, int gap, int len);
    void updateNumIndicator(const QSize &size, qreal num_w_percent, int fntsize, int len, int gap);
    void assertBigGood(int s, const char *where);
    /** @brief Process data personally for subclass. For example, convert from rad to deg */
    virtual double processData(void) = 0;
    virtual const QString &getLabelTop(void) = 0;
    virtual const QString &getLabelBot(void) = 0;

protected:
    QString name;

private:
    screen_position position;
    bool wrap360; // suitable for compass like device
    bool enabled;

    qreal bigScratchLenStep;    // step in percents of widget sizes
    qreal big_pixstep;          // percentage recalculated to pixels (internal use only)
    int bigScratchValueStep;    // numerical value step
    int stepsSmall;             // how many small scratches between 2 big. Can be 0.
    int small_steps_total;      // overall count of small scratches in ribbon (internal use only).
    int stepsBig;               // value must be even AND more than 0
    qreal small_pixstep;        // percentage recalculated to pixels (internal use only)
    QRect clipRect;             // clipping rectangle
    QRect tagRectTop;           // rectangle for top tag
    QRect tagRectBot;           // rectangle for bottom tag
    QSize size_cached;          // cached value to recalculate all sizes after changing of settings

    QPen bigPen;
    QPen arrowPen;
    QPen smallPen;
    QLine *scratchBig;
    QLine *scratchSmall;
    QRect *labelRect;
    QFont labelFont;
    QPolygon needlePoly;
    bool opaqueNeedle;
    bool opaqueRibbon;
    bool opaqueTags;
};

#endif // HUD2RIBBON_H
