#pragma once
#include "Parken.h"
#include "Verhalten.h"

Parken::Parken(Weg &a, double start_time) : Verhalten(a), sTime(start_time){};
double Parken::Strecke(Fahrzeug &aFzg, double Zeitintervall) {
  if (Zeitintervall < 0)
    return 0;

  double time_to_drive = Globaltime + Zeitintervall - sTime;

  if (Globaltime > sTime) {
    cout << "Parken ist zum Ende" << endl;
    time_to_drive = Zeitintervall;
  }

  return Verhalten::Strecke(aFzg, time_to_drive);
};