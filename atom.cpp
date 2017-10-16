#include "term.h"
#include "atom.h"
#include "variable.h"
#include "number.h"
using std::string;

Atom::Atom(string s){
  _symbol = s;
}

string Atom::symbol() const{
  return _symbol;
}
/*
bool Atom::match(string const s){
  return MATCH_FAILURE_DIFF_CONSTANT;
}

bool Atom::match(int const i){
  return MATCH_FAILURE_DIFF_CONSTANT;
}
bool Atom::match(Number *number){
  return MATCH_FAILURE_DIFF_CONSTANT;
}
bool Atom::match(Atom *atom){
  return (_symbol == atom->symbol());
}
bool Atom::match(Variable *variable){
  bool ret = false;
  if(variable->assignable()){
    variable->match(_symbol);
    ret = true;
  }
  else{
    ret = (_symbol == variable->value());
  }
  return ret;
}
bool Atom::match(Atom& atom){
  return (_symbol == atom._symbol);
}
bool Atom::match(Number &number){
  return MATCH_FAILURE_DIFF_CONSTANT;
}
bool Atom::match(Variable& variable){
  bool ret = false;
  if(variable.assignable()){
    variable.match(_symbol);
    ret = true;
  }
  else{
    ret = (_symbol == variable.value());
  }
  return ret;
}
*/
