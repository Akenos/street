#include "SimulationsObjekt.h"

ostream &operator<<(ostream &os, SimulationsObjekt &simobj) {
  return simobj.vAusgeben(os);
}