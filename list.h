#ifndef LIST_H
#define LIST_H

#include "term.h"

#include <vector>
using std::vector;

class List : public Term {
public:
  List ();
  List (vector<Term *> const & elements);
  string symbol() const;
  string value() const;
  vector<Term *> getElements();
  //bool match(Term & term);
  Term * head() const;
  List * tail() const;

private:
  vector<Term *> _elements;

};

#endif
