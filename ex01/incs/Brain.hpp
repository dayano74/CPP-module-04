#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <cstddef>
#include <iostream>
#include <string>

class Brain {
 private:
  std::string ideas[100];

 public:
  Brain();
  Brain(const Brain& other);
  Brain& operator=(const Brain& other);
  ~Brain();

  void setIdea(size_t idx, const std::string& s);
  const std::string& getIdea(size_t idx) const;
};

#endif  // BRAIN_HPP
