#pragma once

#include "SimulationsObjekt.h"

class Fahrzeug;
class Weg;

class Verhalten {

protected:
  Weg &zam;

public:
  Verhalten() = default;
  Verhalten(Weg &road) : zam(road) {}

  // how far can we drive in current street within zeitinterval?
  double Strecke(Fahrzeug &aFzg, double Zeitintervall);
  Weg &getWeg() { return zam; };
};