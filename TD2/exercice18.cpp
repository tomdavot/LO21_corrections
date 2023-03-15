#include "exercice19.h"

int & operation(compte * tab, string id)
{
  
  for(tab=tab;tab->id!=id;tab++);
  // ou
  //  while(tab->id!=id)
  //  tab++;
  
  return tab->solde;
}

void essai_comptes(){
  compte tab[5]={ {"A", 10},{"B", 12500 },
		  {"C", 20 }, { "D", 300 },
		  {"E", 0} };
  
  operation(tab,"A")=1000;
  operation(tab,"B")+=100;
  operation(tab,"D")-=50;
  for(int i=0; i<5; i++)
    cout << tab[i].id << " : "
	 << tab[i].solde << endl;
}
