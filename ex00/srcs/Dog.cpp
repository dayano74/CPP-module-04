#include "Dog.hpp"

Dog::Dog() : Animal() {
  type = "Dog";
  std::cout << "[Dog] constructor : type = "
            << type << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
  std::cout << "[Dog] copy constructor : type = "
            << type << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    Animal::operator=(other);
  }
  std::cout << "[Dog] copy assignment operator : type = "
            << type << std::endl;
  return *this;
}

Dog::~Dog() {
  std::cout << "[Dog] destructor : type = "
            << type << std::endl;
}

void Dog::makeSound() const {
  std::cout << "Woof!" << std::endl;
}
