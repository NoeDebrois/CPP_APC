/*!
  \file rootfinding.hpp
  \brief A collection of typedefs for rootfinding
*/

#ifndef ROOTFINDING_HPP
#define ROOTFINDING_HPP

#include <iostream>
#include <cmath>
#include <limits>

//! Type for real numbers
typedef double real;

//! Type for convergence check
enum checkT {
  INCREMENT, //! Check the difference between subsequent iterates
  RESIDUAL,  //! Check the residual
  BOTH       //! Check both conditions
};

#endif /* ROOTFINDING_HPP */
