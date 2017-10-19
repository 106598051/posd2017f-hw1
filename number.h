#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "term.h"

using std::string;

class Atom;
class Variable;

class Number : public Term{
public:
  Number(string name, int value);
  Number(string name, double value);
  Number(int value);
  Number(double value);
  string symbol() const;
  string value() const;
  bool match(Number& number);
  bool match(Atom& atom);
  bool match(Variable& variable);

private:
  bool MATCH_FAILURE_DIFF_CONSTANT = false;
  double _value;
  //bool matching(int const *i);
};

#endif
