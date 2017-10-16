#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "term.h"

using std::string;

class Number;
class Variable;

class Atom : public Term{
public:
  Atom(string s);

  string symbol() const;

  //string _symbol;
};

#endif
