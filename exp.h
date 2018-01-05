#ifndef EXP_H
#define EXP_H

#include "atom.h"
#include <string>
using std :: string;
// #include <iostream>
// using namespace std;

class Exp {
public:
  virtual bool evaluate() = 0;
  virtual string getExpressionResult() = 0;
};


class MatchExp : public Exp {
public:
  MatchExp(Term* left, Term* right): _left(left), _right(right){

  }

  bool evaluate(){
    return _left->match(*_right);
  }

  string getExpressionResult(){
    bool legal = evaluate();
        // if (legal && _left->symbol() != _right->symbol()) {
        //   if (_left->getVariable() != nullptr )
        //     return _left->symbol() + " = " + _right->value();
        //   else if (_right->getVariable() != nullptr )
        //     return _left->value() + " = " + _right->symbol();
        // }
        // else if (legal)
        //   return "true";
        // else
        //   return "false";

    if (!evaluate()){
      return "false";
    }else if (evaluate() && _left->symbol() == _right->symbol()){
      return "true";
    }else{
      return _left->symbol() + " = " + _right->value();
    }
  }

private:
  Term* _left;
  Term* _right;
};

class ConjExp : public Exp {
public:
  ConjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  bool evaluate() {
    return (_left->evaluate() && _right->evaluate());
  }

  string getExpressionResult(){
    // bool legal = evaluate();
    //
    // if (legal && _left->getExpressionResult() == "true" && _right->getExpressionResult() == "true")
    //   return "true";
    // else if ( legal && _left->getExpressionResult() ==  _right->getExpressionResult())
    //   return _left->getExpressionResult();
    // else if ( legal && _left->getExpressionResult().find( _right->getExpressionResult()) != string::npos ) // some parts have existed in left side
    //   return _left->getExpressionResult();
    // else if ( legal && _left->getExpressionResult() == "true" )
    //   return _right->getExpressionResult();
    // else if ( legal && _right->getExpressionResult() == "true" )
    //   return _left->getExpressionResult();
    // else if(!legal)
    //   return "false";
    // else
    //   return _left->getExpressionResult() + ", " + _right->getExpressionResult();

    evaluate();
    if (_left->getExpressionResult() == "false" || _right->getExpressionResult() == "false"){
      return "false";
    }else if (_right->getExpressionResult() == "true" || _left->getExpressionResult().find(_right->getExpressionResult()) != string::npos){
      return _left->getExpressionResult();
    }else if (_left->getExpressionResult() == "true" && _right->getExpressionResult() == "true"){
      return "true";
    }else if (_left->getExpressionResult() == "true"){
      return _right->getExpressionResult();
    }else{
      return _left->getExpressionResult() + ", " + _right->getExpressionResult();
    }

    // string result = "";
    // if (evaluate()){
    //   if (_left->getExpressionResult() == "true" && _right->getExpressionResult() == "true") {
    //     result = "true";
    //   }
    //   else if (_left->getExpressionResult() == _right->getExpressionResult()) {
    //     result = _left->getExpressionResult();
    //   }
    //   else if (_left->getExpressionResult().find(_right->getExpressionResult()) != string :: npos){
    //     result = _left->getExpressionResult();
    //   }
    //   else if (_left->getExpressionResult() == "true") {
    //     result = _right->getExpressionResult();
    //   }
    //   else if (_right->getExpressionResult() == "true") {
    //     result = _left->getExpressionResult();
    //   }
    //   else {
    //     result = _left->getExpressionResult() + ", " + _right->getExpressionResult();
    //   }
    // }
    // else {
    //   result = "false";
    // }
    // return result;

    // string temp;
    // cout << _left -> value() << endl;
    // cout << _right -> value();
    // // temp += _left -> symbol();
    // temp += " , " ;
    // // temp += _right -> symbol();
    // return temp;
  }

private:
  Exp * _left;
  Exp * _right;
};

class DisjExp : public Exp {
public:
  DisjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  bool evaluate() {
    return (_left->evaluate() || _right->evaluate());
  }

  string getExpressionResult(){
    // bool legal = evaluate();
    //
    // if ( _left->getExpressionResult() == "true" || _left->getExpressionResult() == "false" ) {
    //   return _right->getExpressionResult();
    // }
    // else if ( _right->getExpressionResult() == "true" || _right->getExpressionResult() == "false" ) {
    //   return _left->getExpressionResult();
    // }
    // else {
    //   return _left->getExpressionResult() + "; " + _right->getExpressionResult();
    // }

    evaluate();
    if (_right->getExpressionResult() == "false"){
      return _left->getExpressionResult();
    }else if (_left->getExpressionResult() == "false"){
      return _right->getExpressionResult();
    }else{
      return _left->getExpressionResult() + "; " + _right->getExpressionResult();
    }

    // string temp;
    // // cout << _left -> value() << endl;
    // // cout << _right -> value();
    // // temp += _left -> symbol();
    // temp += " ; " ;
    // // temp += _right -> symbol();
    // return temp;
  }

private:
  Exp * _left;
  Exp * _right;
};
#endif
