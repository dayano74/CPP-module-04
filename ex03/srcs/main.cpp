#include <iostream>

#include "../incs/AMateria.hpp"
#include "../incs/Character.hpp"
#include "../incs/Cure.hpp"
#include "../incs/ICharacter.hpp"
#include "../incs/IMateriaSource.hpp"
#include "../incs/Ice.hpp"
#include "../incs/MateriaSource.hpp"

int main() {
  {
    std::cout << "\033[33m=== Test: subject test case ===\033[0m" << std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
  }
  // {
  //   std::cout << "\033[33m=== Test 1: Basic equip and use ===\033[0m" << std::endl;
  //   IMateriaSource* source = new MateriaSource();
  //   source->learnMateria(new Ice());
  //   source->learnMateria(new Cure());

  //   Character hero("Hero");
  //   Character villain("Villain");

  //   AMateria* m1 = source->createMateria("ice");
  //   AMateria* m2 = source->createMateria("cure");

  //   hero.equip(m1);
  //   hero.equip(m2);

  //   hero.use(0, villain);
  //   hero.use(1, villain);

  //   std::cout << "\033[33m=== Test 2: Equip full inventory ===\033[0m" << std::endl;
  //   AMateria* m3 = source->createMateria("ice");
  //   AMateria* m4 = source->createMateria("cure");
  //   AMateria* m5 = source->createMateria("ice");

  //   hero.equip(m3);
  //   hero.equip(m4);
  //   hero.equip(m5);

  //   delete m5;

  //   std::cout << "\033[33m=== Test 3: Unequip and re-equip ===\033[0m" << std::endl;
  //   AMateria* unequiped = hero.getMateria(1);
  //   hero.unequip(1);
  //   AMateria* m6 = source->createMateria("cure");
  //   hero.equip(m6);

  //   hero.use(0, villain);
  //   hero.use(1, villain);

  //   delete unequiped;

  //   std::cout << "\033[33m=== Test 4: Out of range use ===\033[0m" << std::endl;
  //   hero.use(4, villain);
  //   hero.use(-1, villain);

  //   std::cout << "\033[33m=== Test 5: Use empty slot ===\033[0m" << std::endl;
  //   unequiped = hero.getMateria(2);

  //   hero.unequip(2);
  //   hero.use(2, villain);

  //   delete unequiped;

  //   std::cout << "\033[33m=== Test 6: Create non-existent materia type ===\033[0m" << std::endl;
  //   AMateria* m7 = source->createMateria("fire");
  //   if (m7 == NULL) {
  //     std::cout << "createMateria returned NULL for unknown type (expected)" << std::endl;
  //   }

  //   std::cout << "\033[33m=== Test 7: Character copy constructor ===\033[0m" << std::endl;
  //   Character copy(hero);
  //   copy.use(0, villain);
  //   copy.use(1, villain);

  //   std::cout << "\033[33m=== Test 8: Character assignment operator ===\033[0m" << std::endl;
  //   Character assign("Assign");
  //   assign = hero;
  //   assign.use(0, villain);
  //   assign.use(1, villain);

  //   std::cout << "\033[33m=== Test 9: MateriaSource copy constructor ===\033[0m" << std::endl;
  //   MateriaSource source2(*((MateriaSource*)source));
  //   AMateria* m8 = source2.createMateria("ice");
  //   if (m8 != NULL) {
  //     std::cout << "MateriaSource copy works (created ice)" << std::endl;
  //     delete m8;
  //   }

  //   std::cout << "\033[33m=== Test 10: MateriaSource assignment operator ===\033[0m" << std::endl;
  //   MateriaSource source3;
  //   source3 = *((MateriaSource*)source);
  //   AMateria* m9 = source3.createMateria("cure");
  //   if (m9 != NULL) {
  //     std::cout << "MateriaSource assignment works (created cure)" << std::endl;
  //     delete m9;
  //   }

  //   delete source;

  //   std::cout << "\033[32m=== ALL TESTS OK ===\033[0m" << std::endl;
  // }
  return 0;
}
