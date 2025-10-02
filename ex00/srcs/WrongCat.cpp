#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  type = "WrongCat";
  std::cout << "[WrongCat] constructor : type = "
            << type << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
  std::cout << "[WrongCat] copy constructor : type = "
            << type << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
  if (this != &other) {
    WrongAnimal::operator=(other);
  }
  std::cout << "[WrongCat] copy assignment operator : type = "
            << type << std::endl;
  return *this;
}

WrongCat::~WrongCat() {
  std::cout << "[WrongCat] destructor : type = "
            << type << std::endl;
}

void WrongCat::makeSound() const {
  std::cout << "Meow! (by Wrong Cat)" << std::endl;
}
