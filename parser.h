#ifndef PARSER_H
#define PARSER_H
#include <string>
using std::string;
//#include <iostream>

#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "number.h"
#include "list.h"
#include "node.h"
#include "utParser.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner), _terms(){}

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
          //Atom* unexpected = new Atom("unexpected token");
          //return unexpected;
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
          //Atom* unexpected = new Atom("unexpected token");
          //return unexpected;
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
        //Atom* unexpected = new Atom("unexpected token");
        //return unexpected;
        throw string("unexpected token");
      }
    }
    else if ((char)token == ']'){
      _currentToken = token;
    }
    return nullptr;
  }

  /*
  Term* createTerm(){
    int token = _scanner.nextToken();
    _currentToken = token;
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token == ATOMSC){
      Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
      if(_scanner.currentChar() == '(' ) {
        return structure();
      }
      else
        return atom;
    }
    else if(token == '['){
      return list();
    }
    return nullptr;
  }
  */


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


  Term* structure(){
    Atom structureName(symtable[_scanner.tokenValue()].first);
    int startIndexOfStructure = _terms.size();
    _scanner.nextToken();
    createTerms();
    if(_currentToken == ')'){
      vector<Term *> args(_terms.begin() + startIndexOfStructure, _terms.end());
      return new Struct(structureName, args);
    }
    else {
      throw string("unexpected token");
    }
  }

  Term* list(){
    int startIndexOfList = _terms.size();
    if(_currentToken == ']'){
      vector<Term *> elements(_terms.begin() + startIndexOfList, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfList, _terms.end());
      return new List(elements);
    }
    else {
      throw string("unexpected token");
    }
  }

  vector<Term *> &getTerms(){
    return _terms;
  }

  void matchings(){
    Term *term = createTerm();
    if(term != nullptr){
      if(isCOMMA){
        Term *findTerm = find(term);
        if(findTerm != nullptr){
          term->match(*findTerm);
        }
      }
      _terms.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ','
      || _currentToken == '='
      || _currentToken == ';'){
        if (_currentToken == '=') {
          isCOMMA = false;
          Node *left = new Node(TERM, _terms.back(), nullptr, nullptr);
          _terms.push_back(createTerm());
          Node *right = new Node(TERM, _terms.back(), nullptr, nullptr);
          Node *root = new Node(EQUALITY, nullptr, left, right);
          _expressionTree = root;
        } else if (_currentToken == ',') {
          isCOMMA = true;
          Node *left = _expressionTree;
          matchings();
          Node *root = new Node(COMMA, nullptr, left, expressionTree());
          _expressionTree = root;
        } else if (_currentToken == ';') {
          isCOMMA = false;
          Node *left = _expressionTree;
          matchings();
          Node *root = new Node(SEMICOLON, nullptr, left, expressionTree());
          _expressionTree = root;
        }
      }
    }
  }

  Term *find(Term *term){
    for(int index = 0; index < _terms.size(); index++){
      if(_terms[index]->symbol() == term->symbol()){
        return _terms[index];
      }
      Struct *s = dynamic_cast<Struct *>(_terms[index]);
      if(s){
        return findStruct(s, term);
      }
    }
  }

  Term *findStruct(Struct *s, Term *term){
    for (int index = 0; index < s->arity(); index++) {
      if (s->args(index)->symbol() == term->symbol()) {
        return s->args(index);
      }
      Struct *structure = dynamic_cast<Struct *>(s->args(index));
      if (structure) {
        return findStruct(structure, term);
      }
    }
  }

  Node *expressionTree(){
    return _expressionTree;
  }

private:
  FRIEND_TEST(ParserTest, createArgs);
  FRIEND_TEST(ParserTest, ListOfTermsEmpty);
  FRIEND_TEST(ParserTest, listofTermsTwoNumber);
  FRIEND_TEST(ParserTest, createTerm_nestedStruct3);

  void createTerms(){
    Term * term = createTerm();
    if(term != nullptr){
      _terms.push_back(term);
      while ((_currentToken = _scanner.nextToken()) == ',') {
        _terms.push_back(createTerm());
      }
    }
  }

  Scanner _scanner;
  int _currentToken;
  std::vector<Term *> _terms;
  Node * _expressionTree;
  bool isCOMMA = false;
};
#endif
