//
// Created by Federica Filippini on 18/01/23.
//

#include "Simulator.h"

#include <unistd.h>


const Simulator::particle_container & Simulator::get_particles (void) const
{
  return particles;
}


bool Simulator::is_in_limits (const Particle& p) const
{
  /* your code goes here */
}

void Simulator::add_particle (const Particle& p)
{
  /* your code goes here */
}


void Simulator::remove_particle (unsigned id)
{
  /* your code goes here */
}


// perform one simulation step computing particles new position
void Simulator::simulation_step (double Dt)
{
  /* your code goes here */
}


void Simulator::simulation_run (unsigned n_steps, double Dt)
{
  for (unsigned sim_step = 0; sim_step < n_steps; ++sim_step)
  {
    simulation_step(Dt);
    print(23, 80);
    usleep(100000);  // wait 0.5 seconds
  }
  return;
}


std::list<Particle> Simulator::top_k_particles (unsigned k) const
{
  std::map<double, unsigned> distances = sort_particles_by_distance();

  std::list<Particle> l;
  unsigned counter = 0;
  for (auto cit = distances.cbegin(); cit != distances.cend() && counter < k; cit++, counter++) 
  {
    const auto cur_particle = particles.find(cit->second)->second;
    l.push_back(cur_particle);
  }

  return l;
}


void Simulator::print (unsigned rows, unsigned cols) const
{
  std::cout << std::endl;

  for (auto it = particles.begin(); it != particles.end(); ++it) 
  {
    auto pos = it->second.get_position();
    // Get printed position by rescaling from (x_min, x_max) to (0, cols) 
    // (same for y axis)
    unsigned printed_x = (pos.get_x() - x_min) * cols / (x_max - x_min);
    unsigned printed_y = (pos.get_y() - y_min) * rows / (y_max - y_min);

    // Move cursor according to the printed coordinates, and print id there
    for (unsigned i = 0; i < printed_y; i++)
      std::cout << std::endl;  // move down one row
    for (unsigned j = 0; j < printed_x; j++)
      std::cout << " ";  // move left one row
    std::cout << it->first << "\r";  // print id, then go back to beginning of line
    for (unsigned i = 0; i < printed_y; i++)
      std::cout << "\033[A";  // move up one row
  }

  // Finally, move cursor to the bottom of the grid
  for (unsigned i = 0; i < rows+1; i++)
    std::cout << std::endl;
  
  return;
}


void Simulator::print(unsigned int k) const 
{
 std::list<Particle> l = top_k_particles(k);

 for (std::list<Particle>::const_iterator cit = l.cbegin(); cit != l.cend(); ++cit)
    cit->print();
}


void Simulator::fix_position_and_velocity (Particle& rp)
{
  /* your code goes here */
  
}


/* your code goes here */ Simulator::sort_particles_by_distance() const
{
  /* your code goes here */
}
