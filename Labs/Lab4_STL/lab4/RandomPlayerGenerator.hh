#ifndef RANDOMPLAYERGENERATOR_H_
#define RANDOMPLAYERGENERATOR_H_

#include <random>

namespace Arcade {
class Player;

class RandomPlayerGenerator {
  unsigned next_username;

  std::mt19937 generator;
  std::uniform_int_distribution<unsigned> score_distribution;
  std::uniform_int_distribution<unsigned> number_distribution;

public:
  RandomPlayerGenerator();
  RandomPlayerGenerator(unsigned first_username, unsigned lowest_score,
                        unsigned highest_score, unsigned n_scores,
                        unsigned seed = 0u);

  Player nextPlayer();
};
}

#endif /* RANDOMPLAYERGENERATOR_H_ */
