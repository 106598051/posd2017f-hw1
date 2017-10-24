#include "list.h"
#include "term.h"
#include <vector>
using std::vector;

List::List (): _elements() {}
List::List (vector<Term *> const & elements):_elements(elements){}
string List::symbol() const{};
string List::value() const{};
bool List::match(Term & term){};
Term * List::head() const{};
List * List::tail() const{};
