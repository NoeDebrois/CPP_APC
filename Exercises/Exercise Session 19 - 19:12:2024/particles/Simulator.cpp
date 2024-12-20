//
// Created by Federica Filippini on 18/01/23.
//

#include "Simulator.h"

#include <unistd.h>


const Simulator::particle_container & Simulator::get_particles (void) const
{
  return particles;
}


bool Simulator::is_in_limits (const Particle& p) const // Check that the particle is in the box !
{
  const Vector2D & position = p.get_position();
  return x_min - epsilon <= position.get_x() &&
         position.get_x() <= x_max + epsilon &&
         y_min - epsilon <= position.get_y() &&
         position.get_y() <= y_max + epsilon;
}

void Simulator::add_particle (const Particle& p) // Just an insert to an unordered-map S (class Simulator).
{
  if (!is_in_limits(p)){ // We have to check that the particle is in the box !
    std::cerr << "particle out of bounds" << std::endl;
    return; // Return nothing since it is a void-function.
  }
  particles.insert({p.get_id(), p}); // Insert in the unordered-map data structure.
}


void Simulator::remove_particle (unsigned id) // Find the particle whose ID is id and erase it.
{
  Simulator::particle_container::iterator it = particles.find(id);

  if (it != particles.end())
      particles.erase(it);
}


// Perform one simulation step computing particles new position
void Simulator::simulation_step (double Dt)
{
  for (auto it = particles.begin(); it != particles.end(); ++it)
  {
    it->second.next_position(Dt);
    fix_position_and_velocity(it->second);
  }
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

// Implementation of the notion of rebound, in case of "out-of-bounds" situation:
void Simulator::fix_position_and_velocity (Particle& rp)
{
  Vector2D rpos = rp.get_position();

  // The particle can go out of bounds in 4 situations: by <y_min, >y_max, <x_min, >x_max.

  // Particle moving from up to down (recall: (x_min,y_min) is the top left corner)
  if(rpos.get_y() > y_max)
  {
    // Update y coordinate
    double delta_pos = rpos.get_y() - y_max; // > 0
    Vector2D new_position(rpos.get_x(), y_max - delta_pos); // Rebound : same x it would have without rebound,
    // but y is updated so that the fixed y is y_max - delta (cf scheme on the énoncé).
    rp.set_position(new_position);

    // Update y velocity component
    Vector2D new_velocity (rp.get_velocity());
    new_velocity.set_y(-new_velocity.get_y());
    rp.set_velocity(new_velocity);
  }

  // EXACTLY THE SAME FOR THE OTHER FIXING PROCEDURE (in case of out-of-bounds):

  // Particle moving from down to up
  if(rpos.get_y() < y_min)
  {
    // Update y coordinate
    double delta_pos = y_min - rpos.get_y();
    Vector2D new_position(rpos.get_x(), y_min + delta_pos);
    rp.set_position(new_position);
    // Update y velocity component
    Vector2D new_velocity (rp.get_velocity());
    new_velocity.set_y(-new_velocity.get_y());
    rp.set_velocity(new_velocity);
  }

  // Get new position: the y-component may have changed!
  rpos = rp.get_position();

  // Particle moving from left to right
  if(rpos.get_x() > x_max)
  {
    // Update x coordinate
    double delta_pos = rpos.get_x() - x_max;
    Vector2D new_position(x_max - delta_pos, rpos.get_y());
    rp.set_position(new_position);
    // Update x velocity component
    Vector2D new_velocity(rp.get_velocity());
    new_velocity.set_x(-new_velocity.get_x());
    rp.set_velocity(new_velocity);
  }

  // Particle moving from right to left
  if(rpos.get_x() < x_min)
  {
    // Update x coordinate
    double delta_pos = x_min - rpos.get_x();
    Vector2D new_position(x_min + delta_pos, rpos.get_y());
    rp.set_position(new_position);
    // Update x velocity component
    Vector2D new_velocity(rp.get_velocity());
    new_velocity.set_x(-new_velocity.get_x());
    rp.set_velocity(new_velocity);
  }
}


std::map<double, unsigned> Simulator::sort_particles_by_distance() const
{
  std::map<double, unsigned> new_distances;

  /*
  for (auto cit = particles.cbegin(); cit != particles.cend(); ++cit)
  {
    const auto & rp = cit->second;
    new_distances.insert({rp.compute_distance(origin), rp.get_id()});
  }
  */

  // We can also write (more readable in my opinion):
  for (const auto &[id, particle] : particles) {
    new_distances.insert({particle.compute_distance(origin), id});
  }
  
  return new_distances;
}
