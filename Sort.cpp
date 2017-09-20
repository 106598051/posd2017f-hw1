#include "include/Sort.h"

bool compareDecreasingPerimeter(Shape *first, Shape *second){
  return (first->perimeter() > second->perimeter());
}

void Sort::sortByDecreasingPerimeter(std::list<Shape *> *shapeList){
  shapeList->sort(compareDecreasingPerimeter);
}
