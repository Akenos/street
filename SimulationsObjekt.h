#pragma once
#include <string>
#include<iostream>
#include<iomanip>
extern double Globaltime;

using namespace std;

class SimulationsObjekt {
public:
	SimulationsObjekt() : SimulationsObjekt("") {
	};

	SimulationsObjekt(string a) :name(a), maxID(0), iD(0), zeit(0){};
	SimulationsObjekt(const SimulationsObjekt& other) = delete; // ich will keine SimulationsObjekte,die gleiche ID haben
																// Funktionsparameter ohne & (why?)
	
	~SimulationsObjekt() { //cout << "Destr"<<iD << name;       
	};

	static void vKopf() {
		cout << resetiosflags(ios::left);
		cout << setw(10) << "ID" << setw(20) << "Name";
	};

	virtual ostream& vAusgeben(ostream& os) const {
		os << setw(10) << iD << setw(20) << name;
		return os;
	};
	void vEinlesen();
	void vSimulieren() {
		zeit = Globaltime;
	}
	SimulationsObjekt& operator=(const SimulationsObjekt& other) {
		
		if(this != other){			//ohne diese Funktion,Default wuerde aktivert werden
			name = other.name;		// unmoeglich, dass Elemete der Unterklasse zugewiest werden
			//iD = other.iD;
			//maxID = other.maxID;
			zeit = other.zeit;
		}
		return *this;
	}


protected:
	string name;
	const int maxID;
	int iD;
	double zeit;
};

ostream& operator<<(ostream& os, SimulationsObjekt& simobj){
	return simobj.vAusgeben(os);
}
