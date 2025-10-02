#include "../incs/Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain()) {
  type = "Dog";
  std::cout << "[Dog] constructor : type = "
            << type << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(0) {
  std::cout << "[Dog] copy constructor : type = "
            << type << std::endl;
  brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    Animal::operator=(other);
    Brain* newBrain = new Brain(*other.brain);
    delete brain;
    brain = newBrain;
  }
  std::cout << "[Dog] copy assignment operator : type = "
            << type << std::endl;
  return *this;
}

Dog::~Dog() {
  delete brain;
  std::cout << "[Dog] destructor : type = "
            << type << std::endl;
}

void Dog::makeSound() const {
  std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(size_t idx, const std::string& s) {
  brain->setIdea(idx, s);
}

const std::string Dog::getIdea(size_t idx) const {
  return brain->getIdea(idx);
}