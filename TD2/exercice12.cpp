#include <iostream>

using namespace std;
void inverse(int *a, int *b)
{
  // solution 1
  int tmp = *a;
  *a=*b;
  *b=tmp;

  // solution 2
  // *a+=*b;
  // *b=*a-*b;
  // *a-=*b;
}


void inverse(int &a , int &b)
{
  int tmp = a;
  a=b;
  b=tmp;
}

void exercice12()
{
  int a = 1, b =2;
  cout << "Avant " << a << " - " << b << endl;
  inverse(&a,&b);
  cout << "Après " << a << " - " << b << endl;

  int c = 3, d =4;
  cout << "Avant " << c << " - " << d << endl;
  inverse(&a,&b);
  cout << "Après " << c << " - " << d << endl;

  
}
