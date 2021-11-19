#pragma once

#include "Fahrzeug.h"

using namespace std;

class PKW : public Fahrzeug {

protected:
	double Tankinhalt;
	double Tankvolumen;
	double Verbrauch;
public:
	PKW(string nameP, int maxSpeedParam, double VerbrauchParam, double TankenvolParam = 55) : Fahrzeug(nameP, maxSpeedParam), Verbrauch(VerbrauchParam), Tankvolumen(TankenvolParam), Tankinhalt(TankenvolParam/2)  {
		//std::cout << "Const" << iD << name << maxSpeed;
	};

	double Tanken(double Menge = numeric_limits<double>::infinity()) override {
		double leertank = Tankvolumen - Tankinhalt;

		if (Menge >= leertank)  
		{
			Tankinhalt += leertank;
			return leertank;
		}
		else if (Menge < leertank && Menge > 0) {
			Tankinhalt += Menge;
			return Menge;
		}
		else
			return 0;

	};
	double getInhalt() const {
		return Tankinhalt;
	};
	double Gesamtverbrauch() const {
		return totalStreet * (Verbrauch / 100);
	};

	static void vKopf() {

		Fahrzeug::vKopf();
		cout  << std::setw(25) << "Gesamtverbrauch [l]" << std::setw(25) << "akt. Tankinhalt [l]";
		//cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" <<   endl;
	}
	ostream& vAusgeben(ostream& os) const override  {
		Fahrzeug::vAusgeben(os);
		os << setw(25) << Gesamtverbrauch() << setw(25) << getInhalt();
		return os;
	};
	void vSimulieren() override {
		if (Globaltime > zeit) {
			double time_flowd = Globaltime - zeit;

			double how_long_tank = Tankinhalt / (Speed() * (Verbrauch/100));

			double time_driven = how_long_tank < time_flowd ? how_long_tank : time_flowd;

			double Tankverbrauch = time_driven * Speed() * (Verbrauch / 100);

			Tankinhalt -= Tankverbrauch;

			Fahrzeug::vSimulieren();
		}
	};
	void Zeichnen();



};

ostream& operator<<(ostream& os, const PKW& pkw){
	return pkw.vAusgeben(os);
};