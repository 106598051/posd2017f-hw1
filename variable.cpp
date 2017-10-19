#include <iostream>
#include "term.h"
#include "variable.h"
#include "atom.h"
#include "number.h"
#include "struct.h"
using std::string;

Variable::Variable(string s){
  _symbol = s;
}

string Variable::symbol() const{
  return _symbol;
}

string Variable::value() const{
  if(vectorOfTerm.size() > 0){
    /*
    for(int i = 0; i < vectorOfTerm.size(); i++){
      return vectorOfTerm[i]->value();
    }
    */
    return vectorOfTerm[0]->value();
  }
  else if(_value == ""){
    return _symbol;
  }
  //std::cout << _symbol << ":_value="<<_value << '\n';
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
  }
  return ret;
}

string Variable::match(Number *number){
  string ret = "false";
  if(assign(number->value()) || (_value == number->value())){
    ret = (_symbol + " = " + _value);
  }
  return ret;
}

bool Variable::match(Atom& atom){
  bool ret = false;
  if(assign(atom.symbol()) || (_value == atom.symbol())){
    ret = true;
  }
  return ret;
}

bool Variable::match(Number& number){
  bool ret = false;
  if(assign(number.value()) || (_value == number.value())){
    ret = true;
  }
  return ret;
}

bool Variable::match(Variable& variable){
  bool ret = false;

  if(this == &variable){
    ret = true;
  }
  else if(_assignable && variable.assignable()){
    for(auto const& i : assignedVariables){
      i->assignedVariables.push_back(&variable);
      i->assignedVariables.insert(
        i->assignedVariables.end(),
        variable.assignedVariables.begin(),
        variable.assignedVariables.end()
      );
    }
    for(auto const& i : variable.assignedVariables){
      i->assignedVariables.push_back(this);
      i->assignedVariables.insert(
        i->assignedVariables.end(),
        assignedVariables.begin(),
        assignedVariables.end()
      );
    }
    std::list<Variable *> tempList = assignedVariables;
    assignedVariables.push_back(&variable);
    assignedVariables.insert(
      assignedVariables.end(),
      variable.assignedVariables.begin(),
      variable.assignedVariables.end()
    );
    variable.assignedVariables.push_back(this);
    variable.assignedVariables.insert(
      variable.assignedVariables.end(),
      tempList.begin(),
      tempList.end()
    );
    ret = true;
  }
  else if(!_assignable && !variable.assignable()){
    ret = assign(variable.value());
  }
  else if(_assignable){
    _value = variable.value();
    ret = true;
  }
  else if(variable.assignable()){
    ret = variable.match(*this);
  }
  return ret;
}

bool Variable::match(Struct& s){
  bool ret = false;
  vectorOfTerm.push_back(&s);
  /*
  if(assign(s.symbol()) || (_value == s.symbol())){
    ret = true;
  }
  */
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
    for(auto const& i : assignedVariables){
      i->assign(s);
    }
    ret = true;
  }
  return ret;
}

void Variable::assignedList() {
  std::cout<<"List of "<<_symbol<<"[";
  for(auto const& i : assignedVariables){
    std::cout<<i->symbol();
  }
  std::cout<<"]"<<std::endl;
}
