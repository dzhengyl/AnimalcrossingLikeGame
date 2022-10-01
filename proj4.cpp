//Title: proj4.cpp
//Author: Danny Zheng
//Date: 3/21/2021
//Description: Builds a farm and starts the simulation (nothing random)
#include <iostream>
#include <string>
using namespace std;

#include "Farm.h"
#include "AgItem.h"

int main () {
  Farm farm;
  //calls simulation
  farm.StartSimulation();
  return 0;
}
