#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "struct.h"
#include "variable.h"
#include "atom.h"
#include "list.h"
#include "number.h"
#include "struct.h"
#include "iterator.h"

TEST(iterator, first) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    Iterator <Term* > *itStruct = s.createIterator();
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

TEST(iterator, nested_iterator) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    Iterator <Term* > *itStruct = s.createIterator();
    itStruct->first();
    itStruct->next();
    Struct *s2 = dynamic_cast<Struct *>(itStruct->currentItem());
    Iterator <Term* > *itStruct2 = s2->createIterator();
    itStruct2->first();
    ASSERT_EQ("X", itStruct2->currentItem()->symbol());
    ASSERT_FALSE(itStruct2->isDone());
    itStruct2->next();
    ASSERT_EQ("2", itStruct2->currentItem()->symbol());
    ASSERT_FALSE(itStruct2->isDone());
    itStruct2->next();
    ASSERT_TRUE(itStruct2->isDone());
}

TEST(iterator, firstList) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    List l({ &one, &t, &Y });
    Iterator<Term* > *itList = l.createIterator();
    itList->first();
    ASSERT_EQ("1", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("t(X, 2)", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("Y", itList->currentItem()->symbol());
    itList->next();
    ASSERT_TRUE(itList->isDone());
}

TEST(iterator, NullIterator){
  Number one(1);
  Iterator<Term* > *it = one.createIterator();
  it->first();
  ASSERT_TRUE(it->isDone());
}

TEST(iterator, StuctDFSIterator) {
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  Struct t(Atom("t"), { &X, &two });
  Struct t2(Atom("t2"), { &X, &t, &two });
  Iterator<Term* > *itStruct = t2.createDFSIterator();
  itStruct->first();
  ASSERT_EQ("X", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("X", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("2", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("2", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_TRUE(itStruct->isDone());
}

TEST(iterator, ListDFSIterator) {
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  Struct t(Atom("t"), { &X, &two });
  List l({ &one, &t, &Y });
  Iterator<Term* > *itList = l.createDFSIterator();
  itList->first();
  ASSERT_EQ("1", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("t(X, 2)", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("X", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("2", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("Y", itList->currentItem()->symbol());
  itList->next();
  ASSERT_TRUE(itList->isDone());
}

TEST(iterator, StuctBFSIterator) {
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  Struct t(Atom("t"), { &X, &two });
  Struct t2(Atom("t2"), { &X, &t, &two });
  Iterator<Term* > *itStruct = t2.createDFSIterator();
  itStruct->first();
  ASSERT_EQ("X", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("X", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("2", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("2", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_TRUE(itStruct->isDone());
}

TEST(iterator, ListBFSIterator) {
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  Struct t(Atom("t"), { &X, &two });
  List l({ &one, &t, &Y });
  List l2({ &l, &t, &Y });
  Iterator<Term* > *itList = l2.createBFSIterator();
  itList->first();
  ASSERT_EQ("[1, t(X, 2), Y]", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("t(X, 2)", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("Y", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("1", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("t(X, 2)", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());

}

TEST(iterator, ListBFSIterator2) {
  Atom fries2("fries2");
  Atom fries1("fries1");
  List list3({ &fries1,&fries2 });
  Atom coke("coke");
  Atom onions2("onions2");
  Atom onions1("onions1");
  List list2({ &onions1,&onions2 });
  Atom pickleSlice2("pickleSlice2");
  Atom pickleSlice1("pickleSlice1");
  List list({ &pickleSlice1,&pickleSlice2 });
  Atom cheese("cheese");
  Atom sauce("sauce");
  Atom shreddedLettuce("shreddedLettuce");
  Atom beefPatty("beefPatty");
  Atom bun("bun");
  Struct bigMac(Atom("bigMac"),{&bun,&beefPatty,&shreddedLettuce,&sauce,&cheese,&list,&list2});
  Struct combo1(Atom("combo1"),{&bigMac,&coke,&list3});

  Iterator<Term* > *itStruct = combo1.createBFSIterator();
  itStruct->first();
  ASSERT_EQ("bigMac(bun, beefPatty, shreddedLettuce, sauce, cheese, [pickleSlice1, pickleSlice2], [onions1, onions2])", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("coke", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("[fries1, fries2]", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("bun", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("beefPatty", itStruct->currentItem()->symbol());
  itStruct->next();
  ASSERT_FALSE(itStruct->isDone());
}


#endif
