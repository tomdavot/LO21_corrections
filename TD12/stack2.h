#if !defined(_Stack2_T_H)
#define _Stack2_T_H
#include "vector.h"

using namespace TD;

namespace AO { // adapteur d’objet
  
  template<class T, class CONT=Vector<T>>
    class Stack {
  
    CONT cont;

  public:
  Stack() : cont(0) {}
  
  void push(const T& x) { cont.push_back(x); }
 
  void pop() { cont.pop_back(); }
 
  const T& top() const { return cont.back(); }
 
  T& top() { return cont.back(); }
 
  bool empty() const { return cont.empty(); }
 
  void clear() { cont.clear(); }
 
  };
}

#endif
