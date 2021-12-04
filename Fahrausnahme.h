#pragma once
#include "Fahrzeug.h"
#include "Weg.h"
#include <exception>

class Fahrausnahme : public std::exception {

protected:
  Fahrzeug &aFzg;
  Weg &road;

public:
  Fahrausnahme(Fahrzeug &x, Weg &y) : aFzg(x), road(y){};
  virtual void Bearbeiten(){};
};