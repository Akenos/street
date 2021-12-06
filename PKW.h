#pragma once

#include "Fahrzeug.h"
#include "GUI/SimuClient.h"
#include "Weg.h"
using namespace std;

class PKW : public Fahrzeug {

protected:
  double Tankinhalt;
  double Tankvolumen;
  double Verbrauch;

public:
  PKW(string nameP, int maxSpeedParam, double VerbrauchParam,
      double TankenvolParam = 55);

  double Tanken(double Menge = numeric_limits<double>::infinity()) override;
  double getInhalt() const;
  double Gesamtverbrauch() const;

  static void vKopf();
  ostream &vAusgeben(ostream &os) const override;
  void vSimulieren() override;
  void Zeichnen(Weg &a);
};

// ostream& operator<<(ostream& os, const PKW& pkw){
// 	return pkw.vAusgeben(os);
// };