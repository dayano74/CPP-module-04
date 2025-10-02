#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 private:
  Brain* brain;

 public:
  Dog();
  Dog(const Dog& other);
  Dog& operator=(const Dog& other);
  virtual ~Dog();

  virtual void makeSound() const;

  void setIdea(size_t idx, const std::string& s);
  const std::string getIdea(size_t idx) const;
};

#endif  // DOG_HPP
