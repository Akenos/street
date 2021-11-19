#pragma once
#include "SimulationsObjekt.h"
#include<iomanip>
#include<iostream>
#include <limits>

extern double Globaltime;

using namespace std;

class Fahrzeug : public SimulationsObjekt {

protected:
	const int maxSpeed;
	double totalStreet;
	double totalTime;

public:
	
	
	Fahrzeug(string nameP, int maxSpeedParam) : SimulationsObjekt(nameP), maxSpeed(maxSpeedParam < 0 ? 0 : maxSpeedParam), totalStreet(0), totalTime(0) {
		//cout << "Const" << iD << name << maxSpeed;
	}

	ostream& vAusgeben(ostream& os) const override {
		SimulationsObjekt::vAusgeben(os);
		os << setw(30) << maxSpeed << setw(25) << totalStreet << setw(35) << Speed();
		return os;
	}
	static void vKopf() {
		  
		  SimulationsObjekt::vKopf();
		  cout  << setw(30) << "MaxGeschwindigkeit (km/h)" <<   setw(25) << "Gesamtstrecke [km/h]" <<   setw(35) << "akt. Geschwindigkeit [km]";
		  //cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" <<   endl;
	}
	virtual void vSimulieren() {
		if (Globaltime > zeit) {
			double time_flowd = Globaltime - zeit;
			for (size_t i = 0; i < time_flowd; i++)
			{
				totalStreet += Speed();
			}
			totalTime += time_flowd;
			SimulationsObjekt::vSimulieren();
		}
	}

	virtual double Speed() const {
		return maxSpeed;
	}

	virtual double Tanken(double Menge = numeric_limits<double>::infinity()) {
		return 0;
	};

	double getAbschnittstrecke(); 
	
	bool operator<(const Fahrzeug& other) {
		return this->iD < other.iD;
	}

	void neueStrecke(); 
	void Zeichnen();
};

ostream& operator<<(ostream& os, const Fahrzeug& fz){
	return fz.vAusgeben(os);
}
