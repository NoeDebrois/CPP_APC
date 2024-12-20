//
// Created by Federica Filippini on 18/01/23.
//

#include "Particle.h"

#include <iostream>
#include <cmath>

Particle::Particle (unsigned _id, const Vector2D& _pos, const Vector2D& _vel):
  id(_id), position(_pos), velocity(_vel)
{}

Particle::Particle (unsigned _id, const std::vector<double>& _flat_particle):
  id(_id), 
  position(Vector2D(_flat_particle[0],_flat_particle[1])),
  velocity(Vector2D(_flat_particle[2],_flat_particle[3]))
{}

unsigned Particle::get_id (void) const
{
  return id;
}

void Particle::next_position (double Dt)
{
  Vector2D next_position;

  next_position.set_x(position.get_x()+velocity.get_x()*Dt);
  next_position.set_y(position.get_y()+velocity.get_y()*Dt);
  position = next_position;
}

void Particle::set_position (const Vector2D& pos)
{
  position = pos;
}

void Particle::set_velocity (const Vector2D& vel)
{
  velocity = vel;
}

Vector2D Particle::get_position (void) const
{
  return position;
}

Vector2D Particle::get_velocity (void) const
{
  return velocity;
}

std::vector<double> Particle::flatten (void) const
{
  return {
    position.get_x(),
    position.get_y(),
    velocity.get_x(),
    velocity.get_y()
  };
}

double Particle::compute_distance (const Vector2D& other_pos) const
{
  double dx = other_pos.get_x() - position.get_x();
  double dy = other_pos.get_y() - position.get_y();
  return sqrt(dx*dx + dy*dy);
}

void Particle::print (void) const
{
  std::cout << "particle id: " << id << std::endl;
  std::cout << "particle position: ";
  position.print();
  std::cout << "particle velocity: ";
  velocity.print();
}
