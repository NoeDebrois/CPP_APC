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
};

inline bool operator<(const Arcade::Player &lhs, const Arcade::Player &rhs) {
  return (lhs.getUsername() < rhs.getUsername());
}
}

//inline bool operator<(const Arcade::Player& rhs, const Arcade::Player& lhs){return (rhs.getUsername() < lhs.getUsername());}

#endif /* PLAYER_H_ */
