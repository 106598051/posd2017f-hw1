#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "term.h"

using std::string;

class Variable : public Term{
public:
  Variable(string s);
  string value() const;
  bool match(Term& term);
  Variable* getVariable();

private:
  Term *_content;
};

#endif
