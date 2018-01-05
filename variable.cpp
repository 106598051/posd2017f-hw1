#include "variable.h"



Variable::Variable(string s):Term(s), _content(0){}

string Variable::value() const{
  if(_content) {
    return _content->value();
  }
  else {
    return Term::value();
  }
}
bool Variable::match( Term & term ) {
  if(this == &term) {
    return true;
  }
  if(!_content) {
    _content = &term ;
    return true;
  }
  return _content->match(term);
}

Variable* Variable::getVariable() {
  return this;
}
