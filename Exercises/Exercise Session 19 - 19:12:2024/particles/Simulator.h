//
// Created by Federica Filippini on 18/01/23.
//

#ifndef PARTICLES_SIMULATOR_H
#define PARTICLES_SIMULATOR_H

#include "Particle.h"

#include <iostream>
#include <unordered_map> // Data structure
#include <list>
#include <map>

class Simulator {
public:
  typedef std::unordered_map<unsigned, Particle> particle_container;

private:
  particle_container particles;

  const Vector2D origin = {0.,0.};

  static constexpr double x_min = 0.0;
  static constexpr double x_max = 1.0;
  static constexpr double y_min = 0.0;
  static constexpr double y_max = 1.0;

  bool is_in_limits (const Particle& p) const;

  void fix_position_and_velocity (Particle& p);

  std::map<double, unsigned> sort_particles_by_distance (void) const;

public:
  static constexpr double epsilon = 0.00001;

  Simulator (void) = default;

  const particle_container& get_particles (void) const;

  void add_particle (const Particle& p);
  void remove_particle (unsigned id);

  void simulation_step (double Dt);
  void simulation_run (unsigned n_steps, double Dt);

  std::list<Particle> top_k_particles (unsigned k) const;

  void print (unsigned row, unsigned cols) const;

  void print (unsigned k) const; // print details of the top k particles

};


#endif //PARTICLES_SIMULATOR_H
