#include "struct.h"
#include "iterator.h"
//homework 4沒用到
Term * Struct::args(int index) {
  return _args[index];
}

int Struct::arity(){
    return _args.size();
  }

Atom const & Struct::name(){
  return _name;
}

string  Struct::symbol() const {
  string ret = _name.symbol() + "(";
  if(_args.size()){
    std::vector<Term *>::const_iterator it = _args.begin();
    for (; it != _args.end()-1; ++it)
      ret += (*it)->symbol()+", ";
    ret  += (*it)->symbol();
  }
  ret += ")";
  return ret;
}

string Struct::value() const{
  string ret =_name.value() + "(";
  for(int i = 0; i < _args.size() - 1 ; i++){
    ret += _args[i]-> value() + ", ";
  }
  ret += _args[_args.size()-1]-> value() + ")";
  return  ret;
}

Iterator<Term *> * Struct::createIterator(){
  return new StructIterator<Term *>(this);
}

Iterator<Term *> * Struct::createDFSIterator(){
  return new DFSIterator<Term *>(this);
}

Iterator<Term *> * Struct::createBFSIterator(){
  return new BFSIterator<Term *>(this);
}
