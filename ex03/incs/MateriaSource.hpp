#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>

#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {
 private:
  AMateria* _materias[4];

 public:
  MateriaSource();
  MateriaSource(MateriaSource const& other);
  MateriaSource& operator=(MateriaSource const& other);
  ~MateriaSource();

  void learnMateria(AMateria* m);
  AMateria* createMateria(std::string const& type);
};

#endif  // MATERIASOURCE_HPP
