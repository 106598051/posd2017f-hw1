#include <sstream>
#include "term.h"
#include "number.h"
#include "atom.h"
#include "variable.h"
using std::string;

Number::Number(string name, int value){
  _symbol = name;
  _value = value;
}

Number::Number(string name, double value){
  _symbol = name;
  _value = value;
}

Number::Number(int value){
  std::stringstream buffer;
  buffer << _value;
  _symbol = buffer.str();
  _value = value;
}

Number::Number(double value){
  std::stringstream buffer;
  buffer << _value;
  _symbol = buffer.str();
  _value = value;
}

string Number::symbol() const{
  return _symbol;
}

string Number::value() const{
  std::stringstream buffer;
  buffer << _value;
  return buffer.str();
}
/*
bool Number::match(string const s){
  return MATCH_FAILURE_DIFF_CONSTANT;
}

bool Number::match(int const i){
  return matching(&i);
}

bool Number::match(Number *number){
  return matching(&number->_value);
}

bool Number::match(Atom *atom){
  return MATCH_FAILURE_DIFF_CONSTANT;
}

bool Number::match(Variable *variable){
  bool ret = false;
  if(variable->assignable()){
    variable->match(value());
    ret = true;
  }
  else{
    ret = (value() == variable->value());
  }
  return ret;
}

bool Number::match(Number& number){
  return matching(&number._value);
}

bool Number::match(Atom& atom){
  return MATCH_FAILURE_DIFF_CONSTANT;
}

bool Number::match (Variable& variable){
  bool ret = false;
  if(variable.assignable()){
    variable.match(value());
    ret = true;
  }
  else{
    ret = (value() == variable.value());
  }
  return ret;
}

bool Number::matching(int const *i) {
  bool matched = false;
  if(_value == *i){
    matched = true;
  }
  return matched;
}
*/
