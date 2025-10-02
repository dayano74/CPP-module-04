#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main() {
  const Animal* d = new Dog();
  const Animal* c = new Cat();

  delete d;
  delete c;
  return 0;
}