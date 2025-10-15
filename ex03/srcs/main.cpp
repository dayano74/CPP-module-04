#include <iostream>

#include "../incs/AMateria.hpp"
#include "../incs/CharacterMock.hpp"
#include "../incs/Cure.hpp"
#include "../incs/ICharacter.hpp"
#include "../incs/Ice.hpp"

int main() {
  CharacterMock hero("Hero");

  AMateria* ice = new Ice();
  AMateria* iceClone = ice->clone();

  AMateria* cure = new Cure();
  AMateria* cureClone = cure->clone();

  ice->use(hero);
  iceClone->use(hero);

  cure->use(hero);
  cureClone->use(hero);

  delete cureClone;
  delete cure;
  delete iceClone;
  delete ice;

  std::cout << "\033[32mok\033[0m" << std::endl;
  return 0;
}