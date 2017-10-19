#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <list>
#include <vector>
#include "term.h"

using std::string;

class Atom;
class Number;
class Struct;

class Variable : public Term{
public:
  std::list<Variable *> assignedVariables;
  std::vector<Struct *> vectorOfTerm;

  Variable(string s);
  string symbol() const;
  string value() const;
  string match(string s);
  string match(Atom *atom);
  string match(Number *number);
  bool match(Atom& atom);
  bool match(Number& number);
  bool match(Variable& variable);
  bool match(Struct& s);
  bool assignable();
  void assignedList();

private:
  string _value;
  string addressOfValue = "";
  string* pointerOfAddress = &addressOfValue;
  bool _assignable = true;
  bool assign(string s);
  string assignAsVariable = "";
};

#endif
