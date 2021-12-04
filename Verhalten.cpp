#pragma once

#include "Fahrzeug.h"
#include "SimulationsObjekt.h"
#include "Weg.h"

// how far can we drive in current street within zeitinterval?
double Verhalten::Strecke(Fahrzeug &aFzg, double Zeitintervall) {
  if (Zeitintervall < 0)
    return 0;

  double fzSpeed = aFzg.Speed();
  if (fzSpeed > zam.getTempolimit())
    fzSpeed = zam.getTempolimit();

  double distanceToDrive = fzSpeed * Zeitintervall;

  double restStrecke = zam.getLange() - aFzg.getAbschnittstrecke();

  if (distanceToDrive < restStrecke) {
    return distanceToDrive;
  } else {
    return restStrecke;
  }

  /*double Verhalten::SpeedLimit(){

    switch(zam->getWeg()){

    }

  }*/
};
