#include "ParallelSimulator.h"

namespace ParallelSimulator {

  void send_particle(const Particle& particle, int dest){
    unsigned id = particle.get_id();
    flat_particle_t fp = particle.flatten();
    // communcate ID tag 1
    MPI_Send(&id, 1, MPI_UNSIGNED, dest, 1, MPI_COMM_WORLD);
    // communcate 4 doubles tag 2
    MPI_Send(fp.data(), 4, MPI_DOUBLE, dest, 2, MPI_COMM_WORLD);

  }

  Particle recv_particle(int src){
    unsigned id;
    // Receive ID tag 1
    MPI_Receive(&id, 1, MPI_UNSIGNED, src, 1, MPI_COMM_WORLD);

    // Receive 4 double tag 2

    flat_particle_t fp(4);
    MPI_Receive(fp.data(), 4, MPI_DOUBLE, src, 2, MPI_COMM_WORLD);
    // return the particle

    return Particle(id, fp);

  }

  void communicate_particles(int r, std::vector<std::vector<Particle>>& particles)
  {
    int rank, size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == r)
    {
      // rank r sends to each other_rank the particles stored in particles[other_rank]

      // YOUR CODE GOES HERE

      for (int other_rank =0; other_rank <size; ++other_rank){
        if (other_rank != rank){
          unsigned n_particles = particles[other_rank].size();
          MPI_Send(&n_particles, 1, MPI_UNSIGNED, other_rank, 0, MPI_COMM_WORLD);

          for (unsigned i = 0; i< n_particles; ++i)
            send_particle(particles[other_rank][i], other_rank);
        }
      }
    }
    else
    {
      // if the current rank is not r, it receives the particles from r and stores them in particles[rank]

      // YOUR CODE GOES HERE

      // receive n_particles form r
      unsigned n_particles;
      MPI_Receive(&n_particles, 1, MPI_UNSIGNED, r, 0, MPI_COMM_WORLD);


      // receive n_particles particles to be stored in particles[rank]

      for (unsigned i = 0; i < n_particles; ++i){
        Particle p = recv_particle(r);
        particles[rank].push_back(p);
      }

    }
  }

};