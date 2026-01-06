#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <cstddef>
#include <string>

#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {
 private:
  std::string _name;
  AMateria* _inventory[4];

 public:
  Character();
  Character(std::string const& name);
  Character(Character const& other);
  Character& operator=(Character const& other);
  ~Character();

  std::string const& getName() const;
  AMateria* getMateria(int idx) const;

  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);
};

#endif  // CHARACTER_HPP
