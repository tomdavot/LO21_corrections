#if !defined(_Vector_T_H)
#define _Vector_T_H
#include "container.h"

namespace TD {
  template<class T>
    class Vector : public Container<T> {
    
    T* tab;
    size_t cap;
    
  public:
    Vector(size_t s=0, const T& initialize_with=T());
    Vector(const Vector<T>&);
    ~Vector();
    Vector<T>& operator=(const Vector<T>& t);
    T& element(size_t i) override;

    const T& element(size_t i) const override;
    T& operator[](size_t i) { return tab[i]; }
    const T& operator[](size_t i) const { return tab[i]; }
    void push_back(const T& x) override;
    void pop_back() override;
  };
} // namespace TD


template <class T>
TD::Vector<T>::Vector(size_t s, const T &initialize_with) : Container<T>(s), tab(new T[s]), cap(s)
{
  for(size_t i=0; i<Container<T>::nbEl; i++)
    tab[i]=initialize_with;
}

template <class T>
TD::Vector<T>::Vector(const TD::Vector<T> &t)
    : Container<T>(t.nbEl), tab(new T[t.size()]), cap(t.size())
{
  for(size_t i=0; i<this->size(); i++) tab[i]=t.tab[i];
}

template <class T> TD::Vector<T>::~Vector()
{
  delete[] tab;
}

template<class T> T& TD::Vector<T>::element(size_t i)
{
  if (i<Container<T>::nbEl) return tab[i];
  throw ContainerException("erreur Vector : demande hors limite");
}

template <class T> const T &TD::Vector<T>::element(size_t i) const
{
  if (i<Container<T>::nbEl) return tab[i];
  throw ContainerException("erreur Vector : demande hors limite");
}

template <class T> TD::Vector<T> &TD::Vector<T>::operator=(const TD::Vector<T> &t)
{
  if (this!=&t){
    T* newtab = new T[t.nbEl];
    for(size_t i=0; i<t.nbEl; i++) newtab[i]=t.tab[i];
    
    Container<T>::nbEl=t.nbEl;
    cap=t.nbEl;
    
    T* old=tab;
    tab=newtab;
    delete[] old;
  }
  return * this;
}

template <class T> void TD::Vector<T>::push_back(const T &x)
{
    if (Container<T>::nbEl==cap){
      T* newtab = new T[cap+5];
      for(size_t i=0; i<Container<T>::nbEl; i++) newtab[i]=tab[i];
      T* old=tab;
      cap+=5;
      tab=newtab;
      delete[] old;
    }
    tab[Container<T>::nbEl++] = x;
}

template <class T> void TD::Vector<T>::pop_back()
{
  if (!this->empty()){
    Container<T>::nbEl--;
  }
  else throw ContainerException("erreur Vector :: Vector vide");
}
#endif
