#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
  std::cout << "[WrongAnimal] constructor : type = "
            << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
  std::cout << "[WrongAnimal] copy constructor : type = "
            << type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
  if (this != &other) {
    type = other.type;
  }
  std::cout << "[WrongAnimal] copy assignment operator : type = "
            << type << std::endl;
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "[WrongAnimal] destructor : type = "
            << type << std::endl;
}

const std::string& WrongAnimal::getType() const {
  return type;
}

void WrongAnimal::makeSound() const {
  std::cout << "(generic wrong animal sound)" << std::endl;
}
