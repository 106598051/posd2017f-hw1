#include "Variable.h"
#include "Atom.h"
#include "Number.h"
using std::string;

Variable::Variable(string s):_symbol(s){}
string Variable::symbol(){
  return _symbol;
}
string Variable::value(){
  return _value;
}
string Variable::match(string s){
  bool ret = _assignable;
  assign(s);
  return ret ? (_symbol + " = " + _value) : "false";
}
string Variable::match(Atom *atom){
  string ret = "false";
  if(assign(atom->symbol()) || (_value == atom->symbol())){
    ret = (_symbol + " = " + _value);
  }/*
  else if(_value == atom->symbol()){
    ret = (_symbol + " = " + _value);
  }*/
  return ret;
}
string Variable::match(Number *number){
  string ret = "false";
  if(assign(number->value()) || (_value == number->value())){
    ret = (_symbol + " = " + _value);
  }/*
  else if(_value == number->value()){
    ret = (_symbol + " = " + _value);
  }*/
  return ret;
}
bool Variable::assignable(){
  return _assignable;
}
bool Variable::assign(string s){
  bool ret = false;
  if(_assignable){
    _value = s;
    _assignable = false;
    ret = true;
  }
  return ret;
}
