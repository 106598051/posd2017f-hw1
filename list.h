#ifndef LIST_H
#define LIST_H

#include "term.h"
#include "atom.h"

#include <vector>
#include <string>
#include <typeinfo>
#include <iostream>
using std::vector;

class Variable;
template <class T> class Iterator;
class List : public Term {
public:
  List ();
  List (vector<Term *> const & elements);
  string symbol() const;
  string value() const;
  vector<Term *> getElements();
  bool match(Term & term);
  Term * head() const;
  List * tail() const;
  bool compareList(List *list);
  int arity();
  int getSize() const;
  Term * args(int index);
  Iterator<Term *> * createIterator();
  Iterator<Term *> * createDFSIterator();
  Iterator<Term *> * createBFSIterator();

protected:
  vector<Term *> _elements;

};

#endif
