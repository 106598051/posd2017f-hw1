#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"

TEST (Sort, sortByIncreasingPerimeter) {
  Rectangle r(0, 0, 2, 3, "r");
  ASSERT_NEAR(6.0, r.area(), 0.000001);
  /*
  Circle c(0, 0, 1, "c");
  vertex vertex_A = {0, 0};
  vertex vertex_B = {0, 1};
  vertex vertex_C = {2, 0};
  Triangle t(vertex_A, vertex_B, vertex_C, "t");
  ShapeMedia *shapes;
  shapes.add(&r);
  shapes.add(&c);
  shapes.add(&t);*/



}

TEST (Sort, sortByDecreasingPerimeter) {
  Rectangle r(0, 0, 2, 3, "r");
  Circle c(0, 0, 1, "c");
  vertex vertex_A = {0, 0};
  vertex vertex_B = {0, 1};
  vertex vertex_C = {2, 0};
  Triangle t(vertex_A, vertex_B, vertex_C, "t");
  std::list<Shape *> shapes;
  shapes.push_back(&r);
  shapes.push_back(&c);
  shapes.push_back(&t);
  std::list<Shape *>::iterator i;
  Sort::sortByDecreasingPerimeter(&shapes);
  /*
  for(i = shapes.begin(); i != shapes.end(); ++i) {
    std::cout << (*i) << " ";
  }
  std::cout << std::endl;*/

  i = shapes.begin();
  ASSERT_EQ(r.getShapeName(), (*i)->getShapeName());
  i++;
  ASSERT_EQ(c.getShapeName(), (*i)->getShapeName());
  i++;
  ASSERT_EQ(t.getShapeName(), (*i)->getShapeName());



}

TEST (Sort, sortByIncreasingArea) {

}

TEST (Sort, sortByDecreasingArea) {

}

TEST (Sort, sortByIncreasingCompactness) {

}

#endif
