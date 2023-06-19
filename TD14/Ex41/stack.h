#if !defined(_Stack_T_H)
#define _Stack_T_H
#include "vector.h"

using namespace TD;

namespace AC { // adapteur de classe
  
  template<class T, class CONT=Vector<T>>
  class Stack : private CONT {
  public:
    Stack(): CONT(0) {}
    
    void push(const T& x) { CONT::push_back(x); }
    
    void pop() { CONT::pop_back(); }
    
    const T& top() const { return CONT::back(); }
    
    T& top() { return CONT::back(); }
    
    using CONT::empty;
    using CONT::clear;

    using typename CONT::iterator;
    using typename CONT::const_iterator;
    using CONT::begin;
    using CONT::end;
  };
}

  
#endif
