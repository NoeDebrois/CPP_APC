///Header include
#include "social_network.hpp"
#include "user.hpp"

///STD include
#include <iostream>

namespace SocialNetworkNS {
  size_t SocialNetwork::CUserIndex(const std::string &name, const std::string &surname) const {
    size_t i;

    User u(name, surname); // Constructor !

    bool found = false;

    for (i = 0; i < users.size() && !found; ++i)
      if (users[i] == u)
        found = true;

    if (found)
      return --i; // return the index - 1 (because the vector starts at index 0 !
    else // not found !
      return users.size();
  }

  void SocialNetwork::AddUser(const std::string &name, const std::string &surname) {
    /* MY CODE */
    // If the user is already in the network : return an error ;
    if(SocialNetwork::CUserIndex(name, surname) == users.size()) {
      // If the user is not in the network : add the user and...
      users.push_back(User(name, surname));
      // ...create a null vector row (no friendship for the moment) :
      friends.push_back(std::vector<size_t>());
    }
    else {
      std::cerr << "ERROR : the user is already in the network" << std::endl;
    }
  }

  const std::vector<User> SocialNetwork::CGetUsers() const {
    return users;
  }

  // Returns the vector of friends of the user passed as parameter (which is from User class).
  // Avoid code replication by using the other CGetFriends method !
  const std::vector<User> SocialNetwork::CGetFriends(const User &user) const {
    /* MY CODE */
    return CGetFriends(user.CGetName(), user.CGetSurname());
  }

  // Returns the vector of friends of the user passed as parameter (which is identified by its name and surname).
  const std::vector<User> SocialNetwork::CGetFriends(const std::string &name, const std::string &surname) const {
    std::vector<User> ret{};
    /* MY CODE */
    const size_t index = CUserIndex(name, surname);
    for(size_t i : friends[index]) { // We check all its friends and add them to ret
      ret.push_back(User(users[i].CGetName(), users[i].CGetSurname()));
    }
    return ret;
  }

  void SocialNetwork::AddFriendship(const std::string &first_name,
                                    const std::string &first_surname,
                                    const std::string &second_name,
                                    const std::string &second_surname) {
    /* MY CODE */
    const size_t first_index = CUserIndex(first_name, first_surname);
    const size_t second_index = CUserIndex(second_name, second_surname);
    // SOME CHECKS :

    // A user cannot be friend of her/himself :
    if(first_name == second_name && first_surname == second_surname) {
      std::cerr << "ERROR : a user cannot be friend of her/himself" << std::endl;
    }

    // A user cannot be friend of another user who is not in the social network :
    if(first_index == users.size() || second_index == users.size()) {
      std::cerr << "ERROR : a user cannot be friend of another user who is not in the social network" << std::endl;
    }

    // We have to detect if they are already friends :
    bool already_friends = false;

    for(size_t i : friends[first_index]) {
      // Let's check all the friends of the first user
      if(i == second_index) {
        already_friends = true;
      }
    }

    if(already_friends) {
      std::cerr << "ERROR : the users are already friends" << std::endl;
    } else {
      friends[first_index].push_back(second_index);
      friends[second_index].push_back(first_index);
    }
  }
}