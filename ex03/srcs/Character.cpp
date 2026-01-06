#include "../incs/Character.hpp"

#include "../incs/AMateria.hpp"

Character::Character() : _name("") {
  for (int i = 0; i < 4; ++i) _inventory[i] = NULL;
}

Character::Character(std::string const& name) : _name(name) {
  for (int i = 0; i < 4; ++i) _inventory[i] = NULL;
}

Character::Character(Character const& other) : _name(other._name) {
  for (int i = 0; i < 4; ++i) {
    if (other._inventory[i] != NULL) {
      _inventory[i] = other._inventory[i]->clone();
    } else {
      _inventory[i] = NULL;
    }
  }
}

Character& Character::operator=(Character const& other) {
  if (this != &other) {
    _name = other._name;

    for (int i = 0; i < 4; ++i) {
      if (_inventory[i] != NULL) {
        delete _inventory[i];
        _inventory[i] = NULL;
      }
    }
    for (int i = 0; i < 4; ++i) {
      if (other._inventory[i] != NULL) {
        _inventory[i] = other._inventory[i]->clone();
      } else {
        _inventory[i] = NULL;
      }
    }
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < 4; ++i) {
    if (_inventory[i] != NULL) {
      delete _inventory[i];
      _inventory[i] = NULL;
    }
  }
}

std::string const& Character::getName() const { return _name; }

AMateria* Character::getMateria(int idx) const {
  if (idx < 0 || idx >= 4) return NULL;
  return _inventory[idx];
}

void Character::equip(AMateria* m) {
  if (m == NULL) return;

  for (int i = 0; i < 4; ++i) {
    if (_inventory[i] == NULL) {
      _inventory[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= 4) return;
  if (_inventory[idx] == NULL) return;

  _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx >= 4) return;
  if (_inventory[idx] == NULL) return;

  _inventory[idx]->use(target);
}
