#include "include/Sort.h"

bool compareIncreasingPerimeter(Shape *first, Shape *second){
  return (first->perimeter() < second->perimeter());
}
bool compareDecreasingPerimeter(Shape *first, Shape *second){
  return (first->perimeter() > second->perimeter());
}
bool compareIncreasingArea(Shape *first, Shape *second){
  return (first->area() < second->area());
}
bool compareDecreasingArea(Shape *first, Shape *second){
  return (first->area() > second->area());
}
bool compareIncreasingCompactness(Shape *first, Shape *second){
  return (
      (first->area() / first->perimeter() )
    < (second->area() / second->perimeter() )
  );
}

void Sort::sortByIncreasingPerimeter(std::list<Shape *> *shapeList){
  shapeList->sort(compareIncreasingPerimeter);
}
void Sort::sortByDecreasingPerimeter(std::list<Shape *> *shapeList){
  shapeList->sort(compareDecreasingPerimeter);
}
void Sort::sortByIncreasingArea(std::list<Shape *> *shapeList){
  shapeList->sort(compareIncreasingArea);
}
void Sort::sortByDecreasingArea(std::list<Shape *> *shapeList){
  shapeList->sort(compareDecreasingArea);
}
void Sort::sortByIncreasingCompactness(std::list<Shape *> *shapeList){
  shapeList->sort(compareIncreasingCompactness);
}
