#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "term.h"

using std::string;

class Atom;
class Number;

class Variable : public Term{
public:
  Variable(string s);
  string symbol() const;
  string value();

  //string match(string s);
  string match(Atom *atom);
  string match(Number *number);
  bool match(Atom& atom);
  bool match(Number& number);
  bool match(Variable& variable);
  //string& referenceOfValue();
  bool assignable();

private:
  string _value;
  bool _assignable = true;
  bool assign(string s);
};

#endif
