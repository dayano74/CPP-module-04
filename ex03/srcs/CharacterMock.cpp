#include "../incs/CharacterMock.hpp"

CharacterMock::CharacterMock(std::string const& name) : _name(name) {}

CharacterMock::CharacterMock(CharacterMock const& other) : _name(other._name) {}

CharacterMock& CharacterMock::operator=(CharacterMock const& other) {
  if (this != &other) _name = other._name;
  return *this;
}

CharacterMock::~CharacterMock() {}

std::string const& CharacterMock::getName() const { return _name; }
