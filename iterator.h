#ifndef ITERATOR_H
#define ITERATOR_H

#include "struct.h"
#include "list.h"
#include <queue>

class Struct;
template <typename T>
class Iterator{
  public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual T currentItem() const = 0;
  virtual bool isDone() const = 0;
};


template <class T>
class NullIterator :public Iterator<T>{
public:
  NullIterator(Term *n){}
  void first(){}
  void next(){}
  T currentItem() const{
      return nullptr;
  }
  bool isDone() const{
    return true;
  };

};

template <class T>
class StructIterator :public Iterator<T> {
public:
  friend class Struct;
  void first() {
    _index = 0;
  }

  T currentItem() const {
    return _s->args(_index);
  }

  bool isDone() const {
    return _index >= _s->arity();
  }

  void next() {
    _index++;
  }
  StructIterator(Struct* s): _index(0), _s(s) {}
private:
  int _index;
  T _s;
};

class List;
template <class T>
class ListIterator :public Iterator<T>{
public:
  ListIterator(List *list): _index(0), _list(list) {}

  void first() {
    _index = 0;
  }

  Term* currentItem() const {
    return _list->args(_index);
  }

  bool isDone() const {
    return _index >= _list->arity();
  }

  void next() {
    _index++;
  }
private:
  int _index;
  List * _list;
};

template <class T>
class DFSIterator :public Iterator<T>{
  public:
    DFSIterator(Term *t): _index(0), _t(t) {traverse(t);}
    void first() {_index = 0;}

    T currentItem() const {
      return _items[_index];
    }

    bool isDone() const {
      return _index >= _items.size();
    }

    void next() {
      _index++;
    }

    void traverse(Term * t){
      for(int i=0;i<t->arity();i++){
        Term * term =  t->args(i);
        Struct * s = dynamic_cast<Struct *>(term);
        List * l = dynamic_cast<List *>(term);
        if(s != nullptr){
            _items.push_back(s);
            traverse(s);
        }else if(l != nullptr){
            _items.push_back(l);
            traverse(l);
        }else{
          _items.push_back(term);
        }
      }
    }

    void pushStructName(Struct * s){
      Term * structName = new Atom(s->name().symbol());
      _items.push_back(structName);
    }

    void test_printAllItem(){
      for(int i=0;i<_items.size();i++){
        cout << _items[i]->symbol()<<endl;
      }
    }

  private:
    int _index;
    Term * _t;
    vector<Term*> _items;
};


template <class T>
class BFSIterator :public Iterator<T>{
  public:
    BFSIterator(Term *t): _index(0), _t(t) {traverse(t);}
    void first() {_index = 0;}

    T currentItem() const {
      return _items[_index];
    }

    bool isDone() const {
      return _index >= _items.size();
    }

    void next() {
      _index++;
    }

    void traverse(Term * t){
      for(int i=0;i<t->arity();i++){
        Term * term =  t->args(i);
        Struct * s = dynamic_cast<Struct *>(term);
        List * l = dynamic_cast<List *>(term);
        if(s != nullptr){
          _queue.push(s);
          _items.push_back(s);
        }else if(l != nullptr){
          _queue.push(l);
          _items.push_back(l);
        }else{
          _items.push_back(term);
        }
      }
      while(!_queue.empty()){
        Term * term = _queue.front();
        _queue.pop();
        traverse(term);
      }
    }

    void pushStructNameOnVector(Struct * s){
      Term * structName = new Atom(s->name().symbol());
      _items.push_back(structName);
    }

    void pushListNameOnVector(){
      Term * ListName = new Atom("[]");
      _items.push_back(ListName);
    }

    void test_printAllItem(){
      for(int i=0;i<_items.size();i++){
        cout << _items[i]->symbol()<<endl;
      }
    }

  private:
    int _index;
    Term * _t;
    vector<Term*> _items;
    queue<Term*> _queue;
};

#endif
