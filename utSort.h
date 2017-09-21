#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"

TEST (Sort, sortByIncreasingPerimeter) {
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
  Sort::sortByIncreasingPerimeter(&shapes);
  i = shapes.begin();
  ASSERT_EQ(t.getShapeName(), (*i)->getShapeName());
  i++;
  ASSERT_EQ(c.getShapeName(), (*i)->getShapeName());
  i++;
  ASSERT_EQ(r.getShapeName(), (*i)->getShapeName());
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
  i = shapes.begin();
  ASSERT_EQ(r.getShapeName(), (*i)->getShapeName());
  i++;
  ASSERT_EQ(c.getShapeName(), (*i)->getShapeName());
  i++;
  ASSERT_EQ(t.getShapeName(), (*i)->getShapeName());
}

TEST (Sort, sortByIncreasingArea) {
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
  Sort::sortByIncreasingArea(&shapes);
  i = shapes.begin();
  ASSERT_EQ(t.getShapeName(), (*i)->getShapeName());
  i++;
  ASSERT_EQ(c.getShapeName(), (*i)->getShapeName());
  i++;
  ASSERT_EQ(r.getShapeName(), (*i)->getShapeName());
}

TEST (Sort, sortByDecreasingArea) {
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
  Sort::sortByDecreasingArea(&shapes);
  i = shapes.begin();
  ASSERT_EQ(r.getShapeName(), (*i)->getShapeName());
  i++;
  ASSERT_EQ(c.getShapeName(), (*i)->getShapeName());
  i++;
  ASSERT_EQ(t.getShapeName(), (*i)->getShapeName());
}

TEST (Sort, sortByIncreasingCompactness) {
    // Compactness = area/perimeter
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
    Sort::sortByIncreasingCompactness(&shapes);
    i = shapes.begin();
    ASSERT_EQ(t.getShapeName(), (*i)->getShapeName());
    i++;
    ASSERT_EQ(c.getShapeName(), (*i)->getShapeName());
    i++;
    ASSERT_EQ(r.getShapeName(), (*i)->getShapeName());
}

#endif
