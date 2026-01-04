#include "../incs/Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain()) {
  type = "Cat";
  std::cout << "[Cat] constructor : type = "
            << type << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
  std::cout << "[Cat] copy constructor : type = "
            << type << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    Animal::operator=(other);
    Brain* newBrain = new Brain(*other.brain);
    delete brain;
    brain = newBrain;
  }
  std::cout << "[Cat] copy assignment operator : type = "
            << type << std::endl;
  return *this;
}

Cat::~Cat() {
  delete brain;
  std::cout << "[Cat] destructor : type = "
            << type << std::endl;
}

void Cat::makeSound() const {
  std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(size_t idx, const std::string& s) {
  brain->setIdea(idx, s);
}

const std::string& Cat::getIdea(size_t idx) const {
  return brain->getIdea(idx);
}
