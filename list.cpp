#include <vector>
#include <iostream>
#include <typeinfo>
#include "list.h"
#include "term.h"
#include "iterator.h"
#include "atom.h"
#include "variable.h"
using std::vector;

List::List (): _elements() {}

List::List (vector<Term *> const & elements):_elements(elements){}

string List::symbol() const{
  string ret ;
  if(_elements.size()==0 ){
    ret = "[]";
  }else{
    ret  = "[";
    std::vector<Term *>::const_iterator it = _elements.begin();
    for( ; it != _elements.end()-1 ; ++it ){
      ret += (*it)->symbol()+", ";
    }
    ret += (*it)->symbol()+"]";
  }
  return ret;
  // //return value();
  // string ret ="[";
  // if(_elements.size() != 0){
  //   for(int i = 0; i < _elements.size() - 1 ; i++){
  //     ret += _elements[i]-> symbol() + ", ";
  //   }
  //   ret += _elements[_elements.size()-1]-> symbol();
  // }
  // ret += "]";
  // return  ret;
}

string List::value() const{
  string ret ;
  if(_elements.empty()){
      ret = "[]";
  }else{
      ret  = "[";
      std::vector<Term *>::const_iterator it = _elements.begin();
      for( ; it != _elements.end()-1 ; ++it ){
        ret += (*it)->value()+", ";
      }
      ret += (*it)->value()+"]";
  }
  return ret;
  // string ret = "[";
  // if(_elements.size() != 0){
  //   for(int i = 0; i < _elements.size() - 1 ; i++){
  //     ret += _elements[i]-> value() + ", ";
  //   }
  //   if(_elements.size() != 0)
  //   ret += _elements[_elements.size()-1]-> value();
  // }
  // /*
  // if(_elements.size() > 0){
  //   ret += _elements[0]->value();
  //   for(int i = 1; i < _elements.size(); i++){
  //     ret += ", " + _elements[i]->value();
  //   }
  // }*/
  // ret += "]";
  // return ret;
}

vector<Term *> List::getElements(){
  return _elements;
}

bool List::match(Term & term){
  if(typeid(term) ==  typeid(List)){
    bool ret =true;
    List * ptrls = dynamic_cast<List*>(&term);
    if( _elements.size() != ptrls->_elements.size() ){
    ret = false;
    }
    else{
      for(int i = 0 ; i < _elements.size() ;i++ ){
        ret = _elements[i]->match(*(ptrls->_elements[i])) ;
        if(ret == false)
          return ret;
      }
    }
    return ret;
  }
  else if(typeid(term) == typeid(Variable)){
    bool ret =true;
    for(int i = 0 ; i < _elements.size() ;i++ ){
    if(_elements[i]->symbol() ==  term.symbol()){
      if( _elements[i]->symbol() == term.symbol() ){
        ret= false;
        return ret;
      }
      ret = _elements[i]->match(term) ;
    }
    if(ret == false)
      return ret;
    }
    return ret;
  }
  else {
    return value () == term.value();
  }
  // bool ret = false;
  // if(typeid(term) == typeid(Variable)){
  //   ret = term.match(*this);
  // }
  // else if(_elements.size() != 0){
  //   List *pt = dynamic_cast<List *>(&term);
  //   if(pt){
  //     ret = compareList(pt);
  //   }
  // }
  // /*
  // if(typeid(term) == typeid(Atom)){
  //   for(int i = 0; i < _elements.size(); i++){
  //     if(_elements[i]->match(term)){
  //       ret = true;
  //       break;
  //     }
  //   }
  // }
  // if(typeid(term) == typeid(Variable)){
  //   ret = term.match(*this);
  // }
  // */
  // return ret;
}

Term * List::head() const{
  if(_elements.empty()){
    throw std::string("Accessing head in an empty list");
  }
  return _elements[0];
  // if(_elements.size() == 0){
  //   throw string("Accessing head in an empty list");
  // }
  // vector<Term *> vec = _elements;
  // //return *_elements.begin();
  // return vec.front();
}

List * List::tail() const{
  if(_elements.empty()){
    throw std::string("Accessing tail in an empty list");
  }
  vector<Term *> _clone_elements;
  _clone_elements.assign(_elements.begin() + 1, _elements.end());
  List *ls = new List(_clone_elements) ;
  return ls;
  // if(_elements.size() == 0){
  //   throw string("Accessing tail in an empty list");
  // }
  // List *list = new List(_elements);
  // list->_elements = _elements;
  // list->_elements.erase(list->_elements.begin());
  // return list;
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

int List::arity(){
  return _elements.size();
}

int List::getSize() const{
  return _elements.size();
}

Term * List::args(int index) {
  return _elements[index];
}

Iterator<Term *> * List::createIterator(){
  return new ListIterator<Term *>(this);
}

Iterator<Term *> * List::createDFSIterator(){
  return new DFSIterator<Term *>(this);
}

Iterator<Term *> * List::createBFSIterator(){
  return new BFSIterator<Term *>(this);
}
