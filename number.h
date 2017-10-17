#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "term.h"

using std::string;

class Atom;
class Variable;

class Number : public Term{
public:
  //string _symbol;
  //Number(string value);
  Number(string name, int value);
  Number(int value);
  string symbol() const;
  string value() const;
  /*
  bool match(string const s);
  bool match(int const i);
  bool match(Number *number);
  bool match(Atom *atom);
  bool match(Variable *variable);
  bool match(Number& number);
  bool match(Atom& atom);
  bool match(Variable& variable);
  */
private:
  bool MATCH_FAILURE_DIFF_CONSTANT = false;
  int _value;
  bool matching(int const *i);
};

#endif
