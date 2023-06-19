#include <cstdlib>
#include <ctime>
#include <iostream>

#include "minimum_element.h"
#include "stack.h"


bool pair_minimum(int a , int b) {
  if(a%2==b%2)
    return a<b;
  if(a%2==0)
    return true;
  return false;
}

template <int i=10> bool plus_proche(int a,int b){
  return (a-i)*(a-i) < (b-i)*(b-i);
}


class comparateur {
public:
  enum ordre { croissant, decroissant };
private :
  ordre d;
public:
  comparateur(ordre o=croissant):d(o){}
  bool operator()(int a, int b) { if (d==croissant) return a<b; else return a>b; }
};


int main()
{
  std::srand(std::time(nullptr));
  TD::Vector<int> v;

  for(int i=0;i<10;i++)
    v.push_back(std::rand()%100);

  std::cout << "Vector" << std::endl;
  for(auto i : v)
    std::cout << i << " ";
  std::cout << std::endl;
  
  std::cout << "min: "<<*TD::element_minimum(v.begin(), v.end()) << std::endl;
  std::cout << "max: "<<*TD::element_minimum(v.begin(),v.end(),comparateur(comparateur::decroissant)) << std::endl;
  std::cout << "pair min: " << *TD::element_minimum(v.begin(),v.end(),pair_minimum) << std::endl;
  std::cout << "plus proche de 10: " << *TD::element_minimum(v.begin(),v.end(),plus_proche) << std::endl;
  std::cout << "plus éloigné de 10: " << *TD::element_minimum(v.begin(),v.end(),[](int a, int b) {
    return (a-10)*(a-10) > (b-10)*(b-10);
  }) << std::endl;
    std::cout << "plus proche de 20 : " << *TD::element_minimum(v.begin(),v.end(),plus_proche<20>) << std::endl;


  std::cout << "Entrer un nombre : "  ;
  int i;
  std::cin >> i;

  std::cout << "plus éloigné de " << i << ": " << *TD::element_minimum(v.begin(),v.end(),[&](int a, int b) {
    return (a-i)*(a-i) > (b-i)*(b-i);
  }) << std::endl;


  std::cout << std::endl;
  

  AC::Stack<int> s;

  for(int i=0;i<10;i++)
    s.push(std::rand()%100);

  std::cout << "Stack" << std::endl;
   for(auto i : s)
     std::cout << i << " ";
   std::cout << std::endl;

   std::cout << "min: "<<*TD::element_minimum(s.begin(), s.end()) << std::endl;
  std::cout << "max: "<<*TD::element_minimum(s.begin(),s.end(),comparateur(comparateur::decroissant)) << std::endl;
  std::cout << "pair min: " << *TD::element_minimum(s.begin(),s.end(),pair_minimum) << std::endl;
  std::cout << "plus proche de 10: " << *TD::element_minimum(s.begin(),s.end(),[](int a, int b) {
    return (a-10)*(a-10) < (b-10)*(b-10);
  }) << std::endl;

}
