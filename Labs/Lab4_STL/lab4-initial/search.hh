#ifndef SEARCH_HH
#define SEARCH_HH

#include <vector>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <unordered_map>

#include "Player.hh"

namespace Arcade {
bool binary_search(const std::vector<Arcade::Player> &player_vec, unsigned player_username);
bool stl_binary_search(const std::vector<Arcade::Player> &player_vec, unsigned player_username);
bool set_search(const std::set<Arcade::Player> &player_set, unsigned player_username);
bool map_search(const std::unordered_map<unsigned, Arcade::Player> &player_map, unsigned player_username);
}

#endif // SEARCH_HH
