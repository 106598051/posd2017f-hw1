#ifndef STRUCT_H
#define STRUCT_H

#include "atom.h"
#include <vector>

template<typename T> class Iterator;
class Struct:public Term{
public:
  Struct(Atom const & name, std::vector<Term *> args):_name(name), _args(args) {}
  Term * args(int index);
  int arity();
  Atom const & name();
  string symbol() const;
  string value() const;
  Iterator<Term *> * createIterator();
  Iterator<Term *> * createDFSIterator();
  Iterator<Term *> * createBFSIterator();
private:
  Atom _name;
  std::vector<Term *> _args;
};

#endif
