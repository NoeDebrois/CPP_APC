#include <vector>

#include "RandomPlayerGenerator.hh"
#include "Player.hh"

namespace Arcade {
RandomPlayerGenerator::RandomPlayerGenerator()
    : RandomPlayerGenerator(1, 18, 30, 20) {}

RandomPlayerGenerator::RandomPlayerGenerator(unsigned first_username,
                                             unsigned lowest_score,
                                             unsigned highest_score,
                                             unsigned n_scores,
                                             unsigned seed)
    : next_username(first_username), generator(seed),
      score_distribution(lowest_score, highest_score),
      number_distribution(1, n_scores) {}

Player RandomPlayerGenerator::nextPlayer() {
  const unsigned n_scores = number_distribution(generator);
  std::vector<unsigned> scores(n_scores);

  for (unsigned &score: scores)
    score = score_distribution(generator);

  return Player(next_username++, scores);
}
}
