#include <iostream>

#include "../incs/Animal.hpp"
#include "../incs/Cat.hpp"
#include "../incs/Dog.hpp"

int main() {
  std::cout << "=== Polymorphism Test ===" << std::endl;

  const size_t N = 4;
  Animal* animals[N];

  for (size_t i = 0; i < N; ++i) {
    if (i < N / 2)
      animals[i] = new Dog();
    else
      animals[i] = new Cat();
  }

  std::cout << "\n--- Each animal makes a sound ---" << std::endl;
  for (size_t i = 0; i < N; ++i) {
    std::cout << animals[i]->getType() << ": ";
    animals[i]->makeSound();
  }

  std::cout << "\n=== Deep Copy Test (Dog) ===" << std::endl;
  {
    Dog d1;
    d1.setIdea(0, "bone");
    Dog d2 = d1;
    d1.setIdea(0, "ball");

    std::cout << "d1 idea[0] = " << d1.getIdea(0) << std::endl;
    std::cout << "d2 idea[0] = " << d2.getIdea(0) << std::endl;
  }

  std::cout << "\n=== Deep Copy Test (Cat) ===" << std::endl;
  {
    Cat c1;
    c1.setIdea(0, "fish");
    Cat c2;
    c2 = c1;
    c1.setIdea(0, "milk");

    std::cout << "c1 idea[0] = " << c1.getIdea(0) << std::endl;
    std::cout << "c2 idea[0] = " << c2.getIdea(0) << std::endl;
  }

  std::cout << "\n=== Deleting Animals ===" << std::endl;
  for (size_t i = 0; i < N; ++i) {
    delete animals[i];
  }
  return 0;
}
