#include "PitchCompass.h"

PitchCompass::PitchCompass(TruePoint *comp) {
    compass = comp;
}

double PitchCompass::PIDGet() {
    return compass->pitch;
}
