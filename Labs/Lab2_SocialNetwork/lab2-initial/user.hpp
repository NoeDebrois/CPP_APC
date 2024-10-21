#ifndef USER_HPP_
#define USER_HPP_

///STD include
#include <string>

namespace SocialNetworkNS {
class User {
private:
  ///The name
  const std::string name;

  ///The surname
  const std::string surname;

public:
  /**
   * Constructor
   * @param name is the name of the user
   * @param surname is the surname of the user
   */
  User(const std::string &name, const std::string &surname);

  /**
   * Return the name
   */
  const std::string &CGetName() const;

  /**
   * Return the surname
   */
  const std::string &CGetSurname() const;

  /**
   * Return the name and surname of the user
   */
  std::string ToString() const;
};

/**
 * Comparison operator
 */
bool operator==(const User &lhs, const User &rhs);
}

#endif /*USER_HPP_*/
