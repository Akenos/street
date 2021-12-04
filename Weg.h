#pragma once
#include "Fahrausnahme.h"
#include "Fahrzeug.h"
#include "Kreuzung.h"
#include "SimulationsObjekt.h"
#include "Tempolimit.h"
#include "Verhalten.h"
#include <list>
#include <memory>
#include <ostream>
#include <vector>

using namespace std;

class Weg : public SimulationsObjekt {

protected:
  bool Uberholverbot;
  double Laenge;
  double Schranke;
  Tempolimit tempolimit;
  list<unique_ptr<Fahrzeug>> Fahrzeuge;
  shared_ptr<Weg> Ruekweg;
  shared_ptr<Kreuzung> Ziel;

public:
  Weg() = default;
  Weg(string nameP, double mlange, Tempolimit tlimit = Autobahn)
      : SimulationsObjekt(nameP), Laenge(mlange),
        tempolimit(tlimit){
            // cout << "Const" << iD << name << maxSpeed;
        };
  void vSimulieren() override {
    try {
      for (auto &i : Fahrzeuge) {
        i->vSimulieren();
      }
    } catch (Fahrausnahme &e) {
      e.Bearbeiten();
    }
  };
  ostream &vAusgeben(ostream &os) const override {
    SimulationsObjekt::vAusgeben(os);
    os << setw(30) << Laenge << setw(25) << "(";
    for (auto &fz : Fahrzeuge)
      os << fz->getName() << ":" << fz->getAbschnittstrecke() << ", ";
    os << ")";
    return os;
  };
  static void vKopf() {
    SimulationsObjekt::vKopf();
    cout << setw(30) << "Laenge" << setw(25) << "Fahrzuege" << endl;
    cout << "----------------------------------------------------------------"
            "--"
            "------------------------------"
         << endl;
  };

  void Annahme(unique_ptr<Fahrzeug> a) {
    a->neueStrecke(*this);
    Fahrzeuge.push_back(std::move(a));
  }
  void Annahme(unique_ptr<Fahrzeug> a, double strt_time) {
    a->neueStrecke(*this, strt_time);
    Fahrzeuge.push_back(std::move(a));
  }

  double getLange() const { return Laenge; };
  double getSchranke() const { return Schranke; };
  bool getUeberholverbot() { return Uberholverbot; };
  shared_ptr<Kreuzung> getZielkreuzung() { return Ziel; };
  shared_ptr<Weg> getRuekweg() { return Ruekweg; };
  double getTempolimit() {
    switch (tempolimit) {
    case Landstr:
      return 100;
    case Innerorts:
      return 50;
    case Autobahn:
      return numeric_limits<double>::infinity();
    }
  };
};