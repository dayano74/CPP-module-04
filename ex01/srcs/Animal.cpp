#include "Animal.hpp"

Animal::Animal() : type("Animal") {
  std::cout << "[Animal] constructor : type = "
            << type << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
  std::cout << "[Animal] copy constructor : type = "
            << type << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
  if (this != &other) {
    type = other.type;
  }
  std::cout << "[Animal] copy assignment operator : type = "
            << type << std::endl;
  return *this;
}

Animal::~Animal() {
  std::cout << "[Animal] destructor : type = "
            << type << std::endl;
}

const std::string& Animal::getType() const {
  return type;
}

void Animal::makeSound() const {
  std::cout << "(generic animal sound)" << std::endl;
}
