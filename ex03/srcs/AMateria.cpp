#include "../incs/AMateria.hpp"

#include <iostream>

#include "../incs/ICharacter.hpp"

AMateria::AMateria(std::string const& type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria& AMateria::operator=(AMateria const& other) {
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const {
  return this->_type;
}

void AMateria::use(ICharacter& target) {
  std::cout << "* uses materia of type " << this->_type
            << " on " << target.getName() << " *" << std::endl;
}
