#pragma once
#include "Fahrzeug.h"
#include "Kreuzung.h"
#include "SimulationsObjekt.h"
#include "Tempolimit.h"
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
    for (auto &i : Fahrzeuge) {
      i->vSimulieren();
    }
  };
  ostream &vAusgeben(ostream &os) const override {
    SimulationsObjekt::vAusgeben(os);
    os << setw(30) << Laenge << setw(25) << "(";
    for (auto &fz : Fahrzeuge)
      os << fz->getName() << ", ";
    os << ")";
    return os;
  };
  static void vKopf() {

    SimulationsObjekt::vKopf();
    cout << setw(30) << "Laenge" << setw(25) << "Fahrzuege" << endl;
    cout << "------------------------------------------------------------------"
            "------------------------------"
         << endl;
  };

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