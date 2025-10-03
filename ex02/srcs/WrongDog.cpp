#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal() {
  type = "WrongDog";
  std::cout << "[WrongDog] constructor : type = "
            << type << std::endl;
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other) {
  std::cout << "[WrongDog] copy constructor : type = "
            << type << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& other) {
  if (this != &other) {
    WrongAnimal::operator=(other);
  }
  std::cout << "[WrongDog] copy assignment operator : type = "
            << type << std::endl;
  return *this;
}

WrongDog::~WrongDog() {
  std::cout << "[WrongDog] destructor : type = "
            << type << std::endl;
}

void WrongDog::makeSound() const {
  std::cout << "Meow! (by Wrong Dog)" << std::endl;
}
