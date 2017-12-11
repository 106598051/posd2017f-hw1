#include <typeinfo>
#include "term.h"
#include "iterator.h"
#include "variable.h"
#include "list.h"
#include "atom.h"
#include "number.h"
#include <iostream>
Term::Term ():_symbol(""){}

Term::Term (string s):_symbol(s) {}
/*
Term::Term(int value){
  std::stringstream buffer;
  buffer << value;
  _symbol = buffer.str();
}*/

Term::Term(double value){
  std::stringstream buffer;
  buffer << value;
  _symbol = buffer.str();
}

string Term::symbol() const{
  return _symbol;
};

string Term::value() const{
  return Term::symbol();
};

bool Term::match(Term & term) {
  //bool result = false;
  if (typeid(term) ==  typeid(Variable)) {
    return term.match(*this);
  }
  else {
    return symbol() == term.symbol();
  }
  /*
  if (typeid(term) ==  typeid(Variable)){
    result = term.match(*this);
  }
  else if(typeid(term) == typeid(List)){
    result = true;
    vector<Term *> vector1;
    vector<Term *> vector2;
    vector1 = getElements();
    vector2 = term.getElements();
    if(vector1.size() != vector2.size()){
      result = false;
    }
    else{
      for(int i = 0; i < vector1.size(); i++){
        if(!vector1[i]->match(*vector2[i])){
          result = false;
          break;
        }
      }
    }
  }
  else{
    result = symbol() == term.symbol();
  }
  */
  //return result;
}

std::vector<Term *> Term::getElements(){
  vector<Term *> v;
  return v;
}

int Term::arity() const{
  return 0;
}

Term * Term::args(int index) {
  throw string("not available");
  /*
  Term * v;
  return v;
  */
}

Iterator<Term *> * Term::createIterator(){
  return new NullIterator<Term *>(this);
}
