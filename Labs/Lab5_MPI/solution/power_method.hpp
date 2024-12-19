#ifndef POWER_METHOD_H_
#define POWER_METHOD_H_

#include <mpi.h>

#include "dense_matrix.hpp"

DenseMatrix
power_method(const DenseMatrix & local_A, std::size_t iterations);

#endif
