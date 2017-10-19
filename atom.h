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
  bool match(Atom& atom);
  bool match(Number& number);
  bool match(Variable& variable);

  string symbol() const;

  //string _symbol;
private:
  const bool MATCH_FAILURE_DIFF_CONSTANT = false;
};

#endif
