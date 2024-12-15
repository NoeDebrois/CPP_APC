#include <iostream>
#include <algorithm>

#include "search.hh"
#include "timing.hh"

namespace Arcade {
bool binary_search(const std::vector<Arcade::Player> &player_vec, unsigned player_username) {
  timing::time_point start = std::chrono::steady_clock::now();

  std::vector<Arcade::Player>::const_iterator begin = player_vec.begin(), end = player_vec.end(),
  // original musernamepoint
  musername = begin + (end - begin) / 2;
  unsigned n_iter = 1;

  while (begin != end and musername->getUsername() != player_username) {
    /* end is meant to be invalusername, so in both cases
     * we are ignoring musername at the following iteration
     */
    if (player_username < musername->getUsername())
      end = musername;
    else
      begin = musername + 1;

    musername = begin + (end - begin) / 2;
    ++n_iter;
  }

  std::cout << "Number of Iterations " << n_iter << "\n";

  timing::time_point finish = std::chrono::steady_clock::now();
  timing::elapsed_between(start, finish);

  if (musername != player_vec.end() and player_username == musername->getUsername()) {
    return true;
  } else {
    return false;
  }
}

bool stl_binary_search(const std::vector<Arcade::Player> &player_vec, unsigned player_username) {
  timing::time_point start = std::chrono::steady_clock::now();
  bool val = std::binary_search(player_vec.begin(), player_vec.end(), Player(player_username));
  timing::time_point finish = std::chrono::steady_clock::now();
  timing::elapsed_between(start, finish);

  return val;
}

bool set_search(const std::set<Arcade::Player> &player_set, unsigned player_username) {
  timing::time_point start = std::chrono::steady_clock::now();
  bool val = player_set.count(Player(player_username));
  timing::time_point finish = std::chrono::steady_clock::now();
  timing::elapsed_between(start, finish);

  return val;
}

bool map_search(const std::unordered_map<unsigned, Arcade::Player> &player_map, unsigned player_username) {
  timing::time_point start = std::chrono::steady_clock::now();
  bool val = player_map.count(player_username);
  timing::time_point finish = std::chrono::steady_clock::now();
  timing::elapsed_between(start, finish);

  return val;
}
}
