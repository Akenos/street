#pragma once
#include "Fahrausnahme.h"

class Losfahren : public Fahrausnahme {

public:
  // Fahrausnahme(Fahrzeug &x, Weg &y) : aFzg(x), road(y){};
  void Bearbeiten() override { cout << aFzg << road; };
}