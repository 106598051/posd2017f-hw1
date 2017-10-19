#ifndef STRUCT_H
#define STRUCT_H

#include <vector>
#include <string>
#include "term.h"
#include "atom.h"

using std::string;

class Struct:public Term
{
public:
  Struct(Atom const & name, std::vector<Term *> args);

  Term * args(int index);
  int sizeOfArgs();

  Atom const & name();
  string symbol() const;
  string value() const;
  bool match(Term &term);
  //bool match(Struct &term);
private:
  Atom _name;
  std::vector<Term *> _args;
};

#endif
