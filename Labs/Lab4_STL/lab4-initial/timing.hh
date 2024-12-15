#ifndef TIMING_HH
#define TIMING_HH

#include <chrono>

namespace timing {
typedef std::chrono::time_point<std::chrono::steady_clock> time_point;

void elapsed_between(const time_point &start, const time_point &finish);
}

#endif // TIMING_HH
