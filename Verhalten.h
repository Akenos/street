#pragma once

#include "SimulationsObjekt.h"

class Fahrzeug;
class Weg;
class Parken;

class Verhalten {

protected:
  Weg &zam;

public:
  Verhalten() = default;
  Verhalten(Weg &road) : zam(road) {}

  // how far can we drive in current street within zeitinterval?
  virtual double Strecke(Fahrzeug &aFzg, double Zeitintervall);
  // double SpeedLimit();
  Weg &getWeg() { return zam; };
};