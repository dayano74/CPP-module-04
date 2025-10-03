#include <iostream>

#include "../incs/Animal.hpp"
#include "../incs/Cat.hpp"
#include "../incs/Dog.hpp"

int main() {
  const Animal* i = new Dog();
  const Animal* j = new Cat();
  // const Animal* meta = new Animal();

  std::cout << i->getType() << std::endl;
  std::cout << j->getType() << std::endl;

  i->makeSound();
  j->makeSound();

  delete i;
  delete j;

  return 0;
}