#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "variable.h"

using std::string;

class Atom;

class Number {
public:
  Number(string name, int value):_symbol(name), _value(value){}
  Number(int value):_symbol(std::to_string(value)), _value(value){}
  string value(){
    return std::to_string(_value);
  }
  string symbol(){
    return _symbol;
  }
  bool match(string const s){
    /*
    int d = std::stoi(s);
    return matching(&d);
    */
    return MATCH_FAILURE_DIFF_CONSTANT;
  }
  bool match(int const i){
    return matching(&i);
  }
  bool match(Number *number){
    return matching(&number->_value);
  }
  bool match(Atom *atom){
    return MATCH_FAILURE_DIFF_CONSTANT;
  }
  bool match(Variable *variable){
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
private:
  bool MATCH_FAILURE_DIFF_CONSTANT = false;
  string _symbol;
  int _value;
  bool matching(int const *i) {
    bool matched = false;
    if(_value == *i){
      matched = true;
    }
    return matched;
  }
};

#endif
