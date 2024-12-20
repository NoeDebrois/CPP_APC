#include <iostream>

#include "Simulator.h"

int main() {

  Particle p1{1, {1,1}, {1,0}};
  Particle p2{2, {0,0}, {0,1}};
  Particle p3{3, {0.5,0.5}, {1,1}};
  Particle p4{4, {0.5,0}, {1,1}};
  Simulator S;
  S.add_particle(p1);
  S.add_particle(p2);
  S.add_particle(p3);
  S.add_particle(p4);
  S.print(4);

  std::cout << "\n--------------------------------------------" << std::endl;
  std::cout << "Simulation run" << std::endl;
  S.simulation_run(20, 0.1);

  S.print(4);
  return 0;
}
