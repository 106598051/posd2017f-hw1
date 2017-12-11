#ifndef STRUCT_H
#define STRUCT_H

#include <vector>
#include <string>
#include "term.h"
#include "atom.h"

// using std::string;

template<typename T> class Iterator;
class Struct:public Term
{
public:
  //Struct(Atom const & name, nullptr);
  Struct(Atom const & name, std::vector<Term *> args);

  Term * args(int index);
  int sizeOfArgs() const;
  int arity() const;

  Atom const & name();
  string symbol() const;
  string value() const;
  //bool match(Term &term);
  //bool match(Struct &term);

  Iterator<Term *> * createIterator();
  Iterator<Term *> * createDFSIterator();
  Iterator<Term *> * createBFSIterator();

private:
  Atom _name;
  std::vector<Term *> _args;
};

#endif
