#include<iostream>
#include<string>

#include "fraction.h"

using namespace std;


MATH::Fraction* myFunction(){
    MATH::Fraction fx(7,8);
    MATH::Fraction* pfy=new MATH::Fraction(2,3);
    return pfy;
}



int main()
{
  
  try {
  MATH::Fraction f(3,0);
  } catch (MATH::FractionException &f_e) {
    std::cout << f_e.getInfo() << std::endl;
  }

  /*MATH::Fraction f2(3,4);

  MATH::Fraction f3 = somme(f,f2);
  MATH::Fraction f4 = f.somme(f2);
  */
  /*
    MATH::Fraction f1(3,4);
  MATH::Fraction f2(1,6);

  MATH::Fraction fr = f1+f2;
  MATH::Fraction f_int = f1 + 5;
  MATH::Fraction f_int2 = 5+ f1;
  
    MATH::Fraction* pf3=new MATH::Fraction(1,2);
    cout<<"ouverture d’un bloc\n";
    MATH::Fraction* pf6;
    {
	MATH::Fraction f4(3,8);
	MATH::Fraction f5(4,6);
	pf6=new MATH::Fraction(1,3);
    }
    cout<<"fin d’un bloc\n";
    cout<<"debut d’une fonction\n";
    MATH::Fraction* pf7=myFunction();
    cout<<"fin d’une fonction\n";
    cout<<"desallocations controlee par l’utilisateur :\n";
    delete pf6;
    delete pf7;*/
  
}
