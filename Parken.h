#pragma once

#include "Verhalten.h"

class Parken : public Verhalten {
protected:
  double sTime;

public:
  Parken() = default;
  Parken(Weg &a, double start_time);
  double Strecke(Fahrzeug &aFzg, double Zeitintervall) override;
};