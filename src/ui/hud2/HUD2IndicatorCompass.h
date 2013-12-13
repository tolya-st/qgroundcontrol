#ifndef HUD2COMPASS_H
#define HUD2COMPASS_H

#include "HUD2Ribbon.h"

class HUD2IndicatorCompass : public HUD2Ribbon
{
public:
    HUD2IndicatorCompass(const HUD2Data *huddata, QWidget *parent);

private:
    const QString &getLabelTop(void);
    const QString &getLabelBot(void);
    double processData(void);

private:
    const HUD2Data *huddata;
    QString label;
};

#endif // HUD2COMPASS_H
