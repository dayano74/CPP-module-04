#include "Brain.hpp"

Brain::Brain() {
  std::cout << "[Brain] constructor is called" << std::endl;
}

Brain::Brain(const Brain& other) {
  std::cout << "[Brain] copy constructor is called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
  std::cout << "[Brain] copy assignment operator is called" << std::endl;
  return *this;
}

Brain::~Brain() {
  std::cout << "[Brain] destructor is called" << std::endl;
}

void Brain::setIdea(size_t idx, const std::string& s) {
  if (idx < 100) {
    ideas[idx] = s;
  }
}

const std::string& Brain::getIdea(size_t idx) const {
  static const std::string empty = "";
  return (idx < 100) ? ideas[idx] : empty;
}