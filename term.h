#ifndef TERM_H
#define TERM_H

#include <sstream>
#include <string>
#include <vector>

//#include "iterator.h"

using namespace std;


template<class T>class Iterator;
class Term{
public:
  virtual string symbol() const;
  virtual string value() const;
  virtual bool match(Term & term);
  virtual std::vector<Term *> getElements();
  virtual int arity() const;
  virtual Term * args(int index);
  virtual Iterator<Term *> * createIterator();

protected:
  Term();
  Term(string s);
  //Term(int value);
  Term(double value);

  string _symbol;

};

#endif
