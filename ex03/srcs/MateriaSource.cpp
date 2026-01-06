#include "../incs/MateriaSource.hpp"

#include <iostream>

#include "../incs/AMateria.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; ++i) _materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& other) {
  for (int i = 0; i < 4; ++i) {
    if (other._materias[i] != NULL) {
      _materias[i] = other._materias[i]->clone();
    } else {
      _materias[i] = NULL;
    }
  }
}

MateriaSource& MateriaSource::operator=(MateriaSource const& other) {
  if (this != &other) {
    for (int i = 0; i < 4; ++i) {
      if (_materias[i] != NULL) {
        delete _materias[i];
        _materias[i] = NULL;
      }
    }
    for (int i = 0; i < 4; ++i) {
      if (other._materias[i] != NULL) {
        _materias[i] = other._materias[i]->clone();
      } else {
        _materias[i] = NULL;
      }
    }
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; ++i) {
    if (_materias[i] != NULL) {
      delete _materias[i];
      _materias[i] = NULL;
    }
  }
}

void MateriaSource::learnMateria(AMateria* m) {
  if (m == NULL) return;

  for (int i = 0; i < 4; ++i) {
    if (_materias[i] == NULL) {
      _materias[i] = m->clone();
      delete m;
      return;
    }
  }
  delete m;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < 4; ++i) {
    if (_materias[i] != NULL && _materias[i]->getType() == type) {
      return _materias[i]->clone();
    }
  }
  return NULL;
}
