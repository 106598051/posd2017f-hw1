#include <vector>
#include <iostream>
#include <typeinfo>
#include "list.h"
#include "term.h"
#include "atom.h"
#include "variable.h"
using std::vector;

List::List ()/*: _elements() */{}

List::List (vector<Term *> const & elements):_elements(elements){}

string List::symbol() const{
  return value();
}

string List::value() const{
  string ret = "[";
  if(_elements.size() > 0){
    ret += _elements[0]->value();
    for(int i = 1; i < _elements.size(); i++){
      ret += ", " + _elements[i]->value();
    }
  }
  ret += "]";
  return ret;
}

vector<Term *> List::getElements(){
  return _elements;
}
/*
bool List::match(Term & term){
  bool ret = false;
  if(typeid(term) == typeid(Atom)){
    for(int i = 0; i < _elements.size(); i++){
      if(_elements[i]->match(term)){
        ret = true;
        break;
      }
    }
  }
  if(typeid(term) == typeid(Variable)){
    ret = term.match(*this);
  }
  return ret;
}
*/
Term * List::head() const{
  if(_elements.size() == 0){
    throw string("Accessing head in an empty list");
  }
  return *_elements.begin();
}

List * List::tail() const{
  if(_elements.size()==0){
    throw string("Accessing tail in an empty list");
  }
  List *list = new List(_elements);
  list->_elements.erase(list->_elements.begin());
  return list;
}
