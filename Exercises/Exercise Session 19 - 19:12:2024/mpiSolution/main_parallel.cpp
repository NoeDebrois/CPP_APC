#include <iostream>

#include "ParallelSimulator.h"

using namespace ParallelSimulator;

int main (int argc, char* argv[]) 
{
  MPI_Init(&argc, &argv);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (argc != 2)
  {
    std::cout << "YOU MUST PROVIDE THE ID OF THE PRINTING RANK" << std::endl;
    MPI_Finalize();
    return 1;
  }

  int print_from_rank = std::stoi(argv[1]);

/*
  // one-rank movements
  Particle p1{1, {1,1}, {1,0}};
  Particle p2{2, {0,0.4}, {0,1}};
  Particle p3{3, {0.5,0.5}, {1,-1}};
  Particle p4{4, {0.5,0}, {1,1}};
*/
  // two-ranks movements
  Particle p1{1, {1,1}, {0,-10}};
  Particle p2{2, {0,0.4}, {0,5}};
  Particle p3{3, {0.5,0.5}, {1,-1}};
  Particle p4{4, {0.5,0}, {1,1}};
  std::vector<Particle> particles = {p1, p2, p3, p4};

  std::vector<limits_t> limits = compute_limits (0.0, 1.0, size);
  
  Simulator local_simulator = init_simulator(particles, limits);

  if (rank == print_from_rank)
    local_simulator.print(4);

  double Dt = 0.1;
  simulation_step(local_simulator, Dt, limits);
  
  if (rank == print_from_rank)
  {
    std::cout << "Simulation step for rank " << rank << std::endl;
    local_simulator.print(4);  
  }

  MPI_Finalize();
  return 0;
}
