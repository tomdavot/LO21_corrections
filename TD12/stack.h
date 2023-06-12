#if !defined(_Stack_T_H)
#define _Stack_T_H
#include "vector.h"

using namespace TD;

namespace AC { // adapteur de classe sur Vector<T>
  template<class T>
  class Stack : private Vector<T> {
    
  public:
    Stack(): Vector<T>(0) {}
    
    void push(const T& x) { Vector<T>::push_back(x); }
    
    void pop() { Vector<T>::pop_back(); }
    
    const T& top() const { return Vector<T>::back(); }
    
    T& top() { return Vector<T>::back(); }
    
    bool empty() const { return Vector<T>::empty(); }
    
    void clear() { Vector<T>::clear(); }
  };
} // namespace AC

namespace AC2 { // adapteur de classe
  
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
  };
}

  
#endif
