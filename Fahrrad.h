#pragma once
#include "Fahrzeug.h"


class Fahrrad : public Fahrzeug {

protected:

public:

Fahrrad(string nameP, int maxSpeedParam) : Fahrzeug(nameP, maxSpeedParam) {
		//cout << "Const" << iD << name << maxSpeed;
	};

double Speed() const override {
    double fSpeed = maxSpeed; 

    for(int i = 0; i < totalStreet;i += 20)
        fSpeed *= 0.9;

    if(fSpeed < 12)
        fSpeed = 12;

    return fSpeed;
};

};

// ostream& operator<<(ostream& os, const Fahrrad& fr) {
//     return fr.vAusgeben(os);
// }