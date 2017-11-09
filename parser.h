#ifndef PARSER_H
#define PARSER_H
#include <string>
using std::string;
#include <iostream>

#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "number.h"
#include "list.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner){}
  Term* createTerm(){
    int token = _scanner.nextToken();
    //std::cout<<"token(createTerm)="<<token<<std::endl;
    if(token == VAR){
      //std::cout<<"return Variable"<<std::endl;
      return new Variable(symtable[_scanner.tokenValue()].first);
    }
    else if(token == NUMBER){
      //std::cout<<"return Number"<<std::endl;
      return new Number(_scanner.tokenValue());
    }
    else if(token == ATOM){
      Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
      if(_scanner.currentChar() == '(' ) {
        //std::cout<<"In Struct process"<<std::endl;
        _scanner.nextToken();
        vector<Term*> terms = getArgs();
        if(_currentToken == ')'){
          //std::cout<<"return Struct"<<std::endl;
          return new Struct(*atom, terms);
        }
        else{
          /*Atom* unexpected = new Atom("unexpected token");
          return unexpected;*/
          throw string("unexpected token");
        }
      }
      else {
        //std::cout<<"return Atom"<<std::endl;
        return atom;
      }
    }
    else if(token == ATOMSC){
      Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
      if(_scanner.currentChar() == '(' ) {
        //std::cout<<"In Struct process"<<std::endl;
        _scanner.nextToken();
        vector<Term*> terms = getArgs();
        if(_currentToken == ')'){
          //std::cout<<"return Struct"<<std::endl;
          return new Struct(*atom, terms);
        }
        else{
          /*Atom* unexpected = new Atom("unexpected token");
          return unexpected;*/
          throw string("unexpected token");
        }
      }
      else {
        //std::cout<<"return Atom"<<std::endl;
        return atom;
      }
    }
    else if ((char)token == ')'){
      _currentToken = token;
    }
    else if((char)token == '['){
      //std::cout<<"In list process"<<std::endl;
      vector<Term *> elements = getArgs();
      //std::cout<<"elements.size()="<<elements.size()<<std::endl;
      if(_currentToken == ']'){
        return new List(elements);
      }
      else{
        /*Atom* unexpected = new Atom("unexpected token");
        return unexpected;*/
        throw string("unexpected token");
      }
    }
    else if ((char)token == ']'){
      _currentToken = token;
    }
    return nullptr;
  }

  vector<Term*> getArgs()
  {
    //std::cout<<"In getArgs process"<<std::endl;
    Term* term = createTerm();
    vector<Term*> args;
    if(term){
      args.push_back(term);

      while((_currentToken = _scanner.nextToken()) == ',') {
        args.push_back(createTerm());
      }
    }
    //std::cout<<"_currentToken="<<_currentToken<<std::endl;
    return args;
  }



private:
  Scanner _scanner;
  int _currentToken;
};
#endif
