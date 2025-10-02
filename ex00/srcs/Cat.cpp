#include "Cat.hpp"

Cat::Cat() : Animal() {
  type = "Cat";
  std::cout << "[Cat] constructor : type = "
            << type << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
  std::cout << "[Cat] copy constructor : type = "
            << type << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    Animal::operator=(other);
  }
  std::cout << "[Cat] copy assignment operator : type = "
            << type << std::endl;
  return *this;
}

Cat::~Cat() {
  std::cout << "[Cat] destructor : type = "
            << type << std::endl;
}

void Cat::makeSound() const {
  std::cout << "Meow!" << std::endl;
}
