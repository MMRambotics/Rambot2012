#include "AzimuthCompass.h"

AzimuthCompass::AzimuthCompass(TruePoint *comp) {
    compass = comp;
    refAngle = compass->azimuth;
}

double AzimuthCompass::PIDGet() {
    float curAngle = compass->azimuth;
    float error = refAngle - curAngle;
    if (error < 360) error += 360;
    if (error > 360) error -= 360;
    return error;
}

void AzimuthCompass::SetReference() {
    refAngle = compass->azimuth;
}
