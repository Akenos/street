#pragma once
#include "Fahrzeug.h"
#include "SimulationsObjekt.h"
#include "Verhalten.h"
#include "Weg.h"
#include <iomanip>
#include <iostream>
#include <limits>

extern double Globaltime;

using namespace std;

double Fahrzeug::getTotatStreet() const { return totalStreet; }

void Fahrzeug::setTotalSteet(double ts) { totalStreet = ts; }

void Fahrzeug::vSimulieren() {
  if (abschnittstrecke == verhalten->getWeg().getLange()) {
    cout << endl << name << ": at the end" << endl;
    return;
  }

  // if (Globaltime > zeit) {
  double time_flowd = Globaltime - zeit;
  // 	for (size_t i = 0; i < time_flowd; i++)
  // 	{
  // 		totalStreet += Speed();
  // 	}
  totalTime += time_flowd;
  // }
  double fahrbareStrecke = verhalten->Strecke(*this, time_flowd);
  totalStreet += fahrbareStrecke;
  abschnittstrecke += fahrbareStrecke;
  SimulationsObjekt::vSimulieren();
}

double Fahrzeug::Tanken(double Menge) { return 0; };

double Fahrzeug::getAbschnittstrecke() { return abschnittstrecke; };

bool Fahrzeug::operator<(const Fahrzeug &other) {
  return totalStreet < other.totalStreet;
}

void Fahrzeug::neueStrecke(Weg &a) {
  verhalten = std::make_unique<Verhalten>(a);
  abschnittstrecke = 0;
};

void Zeichnen(){};

// ostream& operator<<(ostream& os, const Fahrzeug& fz){
// 	return fz.vAusgeben(os);
// }
