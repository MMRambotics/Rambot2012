#ifndef AZIMUTH_COMPASS_H
#define AZIMUTH_COMPASS_H

#include "WPILib.h"
#include "TruePoint.h"

class AzimuthCompass : public PIDSource {
    TruePoint *compass;
    float refAngle;
public:
    AzimuthCompass(TruePoint *comp);
    double GetAngle();
    virtual double PIDGet();
    void SetReference();
};

#endif
