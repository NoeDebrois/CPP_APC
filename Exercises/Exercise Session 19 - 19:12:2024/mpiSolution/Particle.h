//
// Created by Federica Filippini on 18/01/23.
//

#ifndef MOLECULES_PARTICLE_H
#define MOLECULES_PARTICLE_H

#include "Vector2D.h"

#include <vector>

class Particle {

private:
  unsigned id;
  Vector2D position;
  Vector2D velocity;

public:
  Particle (unsigned _id, const Vector2D& _pos, const Vector2D& _vel);
  Particle (unsigned _id, const std::vector<double>& _flat_particle);

  unsigned get_id (void) const;

  void next_position (double Dt);

  void set_position (const Vector2D& pos);
  void set_velocity (const Vector2D& vel);

  Vector2D get_position (void) const;
  Vector2D get_velocity (void) const;

  std::vector<double> flatten (void) const;

  double compute_distance (const Vector2D& other_pos) const;

  void print (void) const;
};


#endif //MOLECULES_PARTICLE_H
