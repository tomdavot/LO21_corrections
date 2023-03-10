#include <iostream>
#include "exercice8.h"

void Chinois::bonjour()
{
  std::cout << "hello\n";
}

void Anglais::bonjour()
{
  std::cout << "nichao\n";
}

void exercice8(){
  Chinois::bonjour();
  Anglais::bonjour();
}

