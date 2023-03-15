#include <iostream>
#include "exercice13.h"

using namespace std;
void essai::raz()
{
    n=0;
    x=0;
}

void raz(essai * e)
{
  e->n=0;
  e->x=0;
}

void raz(essai &e)
{
  e.n=0;
  e.x=0;
}

void exercice13()
{
  essai e1 = {1,1.5};
  cout << "Avant " << e1.n << " - " << e1.x << endl;
  raz(&e1);
  cout << "Après " << e1.n << " - " << e1.x << endl;

  essai e2 = {1,1.5};
  cout << "Avant " << e2.n << " - " << e2.x << endl;
  raz(e2);
  cout << "Après " << e2.n << " - " << e2.x << endl;

  essai e3 = {1,1.5};
  cout << "Avant " << e3.n << " - " << e3.x << endl;
  e3.raz();
  cout << "Après " << e3.n << " - " << e3.x << endl;


  
}
