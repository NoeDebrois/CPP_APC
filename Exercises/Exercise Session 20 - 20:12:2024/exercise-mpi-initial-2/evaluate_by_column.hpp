#include <mpi.h>
#include <functional>

#include "dense_matrix.hpp"

typedef std::function<double(const la::dense_matrix&)> function_t;

la::dense_matrix evaluate_by_column(const la::dense_matrix& A, const function_t& f);