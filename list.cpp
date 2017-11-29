#include <vector>
#include <iostream>
#include <typeinfo>
#include "list.h"
#include "term.h"
#include "atom.h"
#include "variable.h"
using std::vector;

List::List (): _elements() {}

List::List (vector<Term *> const & elements):_elements(elements){}

string List::symbol() const{
  //return value();
  string ret ="[";
  if(_elements.size() != 0){
    for(int i = 0; i < _elements.size() - 1 ; i++){
      ret += _elements[i]-> symbol() + ", ";
    }
    ret += _elements[_elements.size()-1]-> symbol();
  }
  ret += "]";
  return  ret;
}

string List::value() const{
  string ret = "[";
  if(_elements.size() != 0){
    for(int i = 0; i < _elements.size() - 1 ; i++){
      ret += _elements[i]-> value() + ", ";
    }
    if(_elements.size() != 0)
    ret += _elements[_elements.size()-1]-> value();
  }
  /*
  if(_elements.size() > 0){
    ret += _elements[0]->value();
    for(int i = 1; i < _elements.size(); i++){
      ret += ", " + _elements[i]->value();
    }
  }*/
  ret += "]";
  return ret;
}

vector<Term *> List::getElements(){
  return _elements;
}

bool List::match(Term & term){
  bool ret = false;
  if(typeid(term) == typeid(Variable)){
    ret = term.match(*this);
  }
  else if(_elements.size() != 0){
    List *pt = dynamic_cast<List *>(&term);
    if(pt){
      ret = compareList(pt);
    }
  }
  /*
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
  */
  return ret;
}

Term * List::head() const{
  if(_elements.size() == 0){
    throw string("Accessing head in an empty list");
  }
  vector<Term *> vec = _elements;
  //return *_elements.begin();
  return vec.front();
}

List * List::tail() const{
  if(_elements.size() == 0){
    throw string("Accessing tail in an empty list");
  }
  List *list = new List(_elements);
  list->_elements = _elements;
  list->_elements.erase(list->_elements.begin());
  return list;
}

bool List::compareList(List *list){
  if(_elements.size() != list->getSize()){
    return false;
  }
  for(int i = 0; i < _elements.size(); i++){
    if(!(_elements[i]->match(*(list->_elements[i])))){
      return false;
    }
  }
  return true;
}

int List::getSize() const{
  return _elements.size();
}
