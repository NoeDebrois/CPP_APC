#include <ctime>
#include <iostream>

#include "timing.hh"

namespace timing {
void elapsed_between(const time_point &start, const time_point &finish) {
  std::chrono::duration<double> elapsed_seconds = finish - start;
  std::cout << "elapsed time: " << elapsed_seconds.count() << " s"
            << std::endl;
}
}
