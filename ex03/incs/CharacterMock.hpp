#ifndef CHARACTERMOCK_HPP
#define CHARACTERMOCK_HPP

#include <string>

#include "ICharacter.hpp"

class CharacterMock : public ICharacter {
 private:
  std::string _name;

 public:
  CharacterMock(std::string const& name);
  CharacterMock(CharacterMock const& other);
  CharacterMock& operator=(CharacterMock const& other);
  ~CharacterMock();

  std::string const& getName() const;
};

#endif  // CHARACTERMOCK_HPP
