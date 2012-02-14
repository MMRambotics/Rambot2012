#ifndef PITCH_COMPASS_H
#define PITCH_COMPASS_H

#include "WPILib.h"
#include "TruePoint.h"

class PitchCompass : public PIDSource {
    TruePoint *compass;
public:
    PitchCompass(TruePoint *comp);
    virtual double PIDGet();
};

#endif
