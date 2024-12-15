#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>

namespace Arcade {
class Player {
  unsigned username;
  std::vector<unsigned> scores;

public:
  Player(unsigned, const std::vector<unsigned> &);
  explicit Player(unsigned);

  const std::vector<unsigned> &getScores() const;
  unsigned getUsername() const;

  void setScores(const std::vector<unsigned> &);
  void setUsername(unsigned);

  void print() const;

  /* It may be necessary to overload some operator
   * to enable the insertion in some data structure
   */
};
}

#endif /* PLAYER_H_ */
