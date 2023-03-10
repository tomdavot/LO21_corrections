#include <stdio.h>
#include <iostream>
//#define PI 3.14159
const double PI = 3.14159;

void exerciceA()
{
  int r; double p, s;

  //printf("donnez le rayon entier d’un cercle:");
  std::cout << "donnez le rayon entier d’un cercle: ";
  //scanf("%d",&r);
  std::cin>> r;
  
  p=2*PI*r;
  s=PI*r*r;
  
  //printf("le cercle de rayon %d ",r);
  std::cout << "le cercle de rayon " << r;
  
  //printf("a un perimetre de %f et une surface de %f\n",p,s);
  std::cout << " a un perimetre de " << p << " et une surface de " << s << std::endl;
}

void exercice6()
{
  double x = 3.14;
  std::cout << x << std::endl;

  double y;
  std::cout << y << std::endl; // valeur aléatoire
  y=3.14;
  std::cout << y << std::endl;
}

void exercice7()
{
  const double pi = 3.14;
  std::cout << pi << std::endl;
  // pi = 3.2 // => ne compile pas car pi est une constante
}
