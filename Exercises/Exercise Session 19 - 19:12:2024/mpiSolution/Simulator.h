//
// Created by Federica Filippini on 18/01/23.
//

#ifndef MOLECULES_SIMULATOR_H
#define MOLECULES_SIMULATOR_H

#include "Particle.h"

#include <iostream>
#include <unordered_map>
#include <list>
#include <map>

class Simulator {

private:
  std::unordered_map<unsigned, Particle> particles;

  const Vector2D origin = {0.,0.};

  static constexpr double x_min = 0.0;
  static constexpr double x_max = 1.0;
  static constexpr double y_min = 0.0;
  static constexpr double y_max = 1.0;

  bool is_in_limits (const Particle& p) const;
  bool is_in_limits (const Vector2D& position) const;

  void fix_pos_velocity (Particle& p);

  std::map<double, unsigned> compute_distances (void) const;

public:
  static constexpr double epsilon = 0.00001;
  
  Simulator (void) = default;

  const std::unordered_map<unsigned, Particle>& get_particles (void) const;

  void add_particle (const Particle& p);
  void remove_particle (unsigned id);

  void simulation_step (double Dt);
  void simulation_run (unsigned n_steps, double Dt);

  std::list<Particle> top_k_particles (unsigned k) const;

  void print (unsigned row, unsigned cols) const;

  void print (unsigned k) const; // print details of the top k molecules

};


#endif //MOLECULES_SIMULATOR_H
