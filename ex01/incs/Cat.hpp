#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
  Brain* brain;

 public:
  Cat();
  Cat(const Cat& other);
  Cat& operator=(const Cat& other);
  virtual ~Cat();

  virtual void makeSound() const;

  void setIdea(size_t idx, const std::string& s);
  const std::string getIdea(size_t idx) const;
};

#endif  // CAT_HPP
