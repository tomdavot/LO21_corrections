#if !defined(_Container_T_H)
#define _Container_T_H
#include<string>
#include<stdexcept>
namespace TD {
  class ContainerException : public std::exception {
  protected :
    std::string info;
  public:
    ContainerException(const std::string& i="") noexcept :info(i){}
    const char * what() const noexcept { return info.c_str(); }
    ~ContainerException()noexcept{}
  };

  
  template<class T>
    class Container {
  protected :
    size_t nbEl;

  public :
  Container(size_t n=0) : nbEl(n) {}
    
    virtual ~Container() {}
    
    unsigned int size() const { return nbEl; }
    
    bool empty() const { return nbEl==0; }
    
    virtual T& front();
    
    virtual T& back();
    
    virtual const T& front() const;
    
    virtual const T& back() const;
    
    virtual T& element(size_t i)=0;
    
    virtual const T& element(size_t i) const=0;
    
    virtual void push_back(const T& x)=0;
    
    virtual void pop_back()=0;
    
    virtual void clear()
    {
      while(!empty()) pop_back();
    }
  };
} // namespace TD
  
template<class T> T& TD::Container<T>::front()
{
  if (!empty()) return element(0);
  throw ContainerException("erreur Container : demande hors limite");
}

template <class T> T &TD::Container<T>::back()
{
  if (!empty()) return element(nbEl-1);
  throw ContainerException("erreur Container : demande hors limite");
}

template <class T> const T &TD::Container<T>::front() const
{
  if (!empty()) return element(0);
  throw ContainerException("erreur Container : demande hors limite");
}

template <class T>
const T &TD::Container<T>::back() const
{
  if (!empty()) return element(nbEl-1);
  throw ContainerException("erreur Container : demande hors limite");
}
#endif
