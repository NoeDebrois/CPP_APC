#ifndef SOCIAL_NETWORK_HPP_
#define SOCIAL_NETWORK_HPP_

///. include
#include "user.hpp"

///STL include
#include <vector>

namespace SocialNetworkNS {
class SocialNetwork {
private:
  ///Social network users
  std::vector<User> users;
  ///Friends of user[i]
  std::vector<std::vector<size_t>> friends;

  /**
   * Return the user index in the users vector, users.size() if the
   * user is not found
   */
  size_t CUserIndex(const std::string &name,
                    const std::string &surname) const;

public:
  /**
   * Return the set of users
   */
  const std::vector<User> CGetUsers() const;

  /**
   * Get the friends of a user
   * @param user is the user
   * @return the set of his/her friends
   */
  const std::vector<User> CGetFriends(const User &user) const;

  /**
   * Get the friends of a user
   * @param name is the name of the user
   * @param surname is the surname of the user
   * @return the set of his/her friends
   */
  const std::vector<User> CGetFriends(const std::string &name,
                                      const std::string &surname) const;

  /**
   * Add a new user to the social network
   * @param name is the name of the user
   * @param surname is the surname of the user
   */
  void AddUser(const std::string &name, const std::string &surname);

  /**
   * Add a friendship between two users
   * @param first_name is the name of the first user
   * @param first_surname is the surname of the first user
   * @param second_name is the name of the second user
   * @param second_surname is the surname of the second user
   */
  void AddFriendship(const std::string &first_name,
                     const std::string &first_surname,
                     const std::string &second_name,
                     const std::string &second_surname);

};
}

#endif /*SOCIAL_NETWORK_HPP_*/
