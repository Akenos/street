#pragma once
#include "Parken.h"
#include "SimulationsObjekt.h"
#include "Verhalten.h"
#include <iomanip>
#include <iostream>
#include <limits>


extern double Globaltime;

using namespace std;

class Fahrzeug : public SimulationsObjekt {

protected:
  const int maxSpeed;
  double abschnittstrecke;
  double totalStreet;
  double totalTime;
  unique_ptr<Verhalten> verhalten;

public:
  Fahrzeug(string nameP, int maxSpeedParam)
      : SimulationsObjekt(nameP),
        maxSpeed(maxSpeedParam < 0 ? 0 : maxSpeedParam), totalStreet(0),
        totalTime(0) {
    // cout << "Const" << iD << name << maxSpeed;
  }

  ostream &vAusgeben(ostream &os) const override {
    SimulationsObjekt::vAusgeben(os);
    os << setw(30) << maxSpeed << setw(25) << totalStreet << setw(35)
       << Speed();
    return os;
  }

  double getTotatStreet() const;

  void setTotalSteet(double ts);

  void vSimulieren() override;

  virtual double Speed() const { return maxSpeed; }

  virtual double Tanken(double Menge = numeric_limits<double>::infinity());

  double getAbschnittstrecke();

  bool operator<(const Fahrzeug &other);

  void neueStrecke(Weg &a);

  void neueStrecke(Weg &a, double time);

  void Zeichnen();
};

// ostream& operator<<(ostream& os, const Fahrzeug& fz){
// 	return fz.vAusgeben(os);
// }
