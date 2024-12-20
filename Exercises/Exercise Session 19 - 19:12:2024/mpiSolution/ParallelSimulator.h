#ifndef PARTICLES_PARALLEL_SIMULATOR_H
#define PARTICLES_PARALLEL_SIMULATOR_H

#include <mpi.h>

#include "Simulator.h"


namespace ParallelSimulator {

  typedef std::vector<double> flat_particle_t;
  typedef std::pair<double, double> limits_t;

  std::vector<limits_t> compute_limits (
    double m, 
    double M, 
    unsigned n_stripes
  );

  Simulator init_simulator (
    const std::vector<Particle>& particles,
    const std::vector<limits_t>& limits
  );

  int find_particle_owner (
    double y, 
    const std::vector<limits_t>& limits
  );

  void send_particle(const Particle& particle, int dest);

  Particle recv_particle(int src);

  void communicate_particles(
    int r,
    std::vector<std::vector<Particle>>& particles
  );

  void simulation_step (
    Simulator& local_simulator, 
    double Dt,
    const std::vector<limits_t>& limits
  );

};

# endif // PARTICLES_PARALLEL_SIMULATOR_H