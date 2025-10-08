#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class ICharacter {
 public:
  virtual ~ICharacter();
  virtual std::string const& getName() const = 0;
};

#endif  // ICHARACTER_HPP
