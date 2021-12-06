#pragma once

#include "PKW.h"
#include "Fahrzeug.h"
#include "GUI/SimuClient.h"
#include "Weg.h"
using namespace std;

PKW::PKW(string nameP, int maxSpeedParam, double VerbrauchParam,
         double TankenvolParam)
    : Fahrzeug(nameP, maxSpeedParam), Verbrauch(VerbrauchParam),
      Tankvolumen(TankenvolParam),
      Tankinhalt(TankenvolParam / 2){
          // std::cout << "Const" << iD << name << maxSpeed;
      };

double PKW::Tanken(double Menge) {
  double leertank = Tankvolumen - Tankinhalt;

  if (Menge >= leertank) {
    Tankinhalt += leertank;
    return leertank;
  } else if (Menge < leertank && Menge > 0) {
    Tankinhalt += Menge;
    return Menge;
  } else
    return 0;
};
double PKW::getInhalt() const { return Tankinhalt; };
double PKW::Gesamtverbrauch() const { return totalStreet * (Verbrauch / 100); };

void PKW::vKopf() {

  Fahrzeug::vKopf();
  cout << std::setw(25) << "Gesamtverbrauch [l]" << std::setw(25)
       << "akt. Tankinhalt [l]";
  // cout <<
  // "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
  // <<   endl;
}
ostream &PKW::vAusgeben(ostream &os) const {
  Fahrzeug::vAusgeben(os);
  os << setw(25) << Gesamtverbrauch() << setw(25) << getInhalt();
  return os;
};
void PKW::vSimulieren() {
  if (Globaltime > zeit) {
    double time_flowd = Globaltime - zeit;

    double how_long_tank = Tankinhalt / (Speed() * (Verbrauch / 100));

    double time_driven =
        how_long_tank < time_flowd ? how_long_tank : time_flowd;

    double Tankverbrauch = time_driven * Speed() * (Verbrauch / 100);

    Tankinhalt -= Tankverbrauch;

    Fahrzeug::vSimulieren();
  }
};
void PKW::Zeichnen(Weg &a) {
  // double long = a.getLange();
  double pos = abschnittstrecke / a.getLange();
  if (pos < 0)
    pos = 0;
  pos = 1;
  bZeichnePKW(name, a.getName(), pos, Speed(), Tankinhalt);
};
