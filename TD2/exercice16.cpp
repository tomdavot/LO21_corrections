#include "exercice17.h"

using namespace std;

void raz(personne &p)
{
  p.nom[0]='\0';
  p.age=0;
}

void affiche_struct(const personne &p)
{
  cout << "Nom : " << p.nom << endl
       << "Age : " << p.age << endl;
}

void affiche_tab(const personne * p_tab, size_t size)
{
  for(size_t i=0;i<size;++i)
    affiche_struct(p_tab[i]);
}

void init_struct(personne &p, const char * nom, unsigned age)
{
  size_t i;
  for(i=0;nom[i]!='\0';++i)
    p.nom[i]=nom[i];
  p.nom[i]='\0';

  p.age=age;
}

void copy_struct(const personne &p_source, personne &p_target)
{
  // operateur '=' généré par défaut.
  p_target=p_source;
}

void copy_tab(const personne * p_source, personne * p_target, size_t size)
{
  for(size_t i =0; i<size; ++i)
    p_target[i]=p_source[i];
}

void exercice_17()
{
  personne p1;
  affiche_struct(p1);
  raz(p1);
  affiche_struct(p1);
  
  personne p2={"Cooper", 28 };
  affiche_struct(p2);
  init_struct(p2, "Wolowitz", 27);
  affiche_struct(p2);
  copy_struct(p1,p2);
  affiche_struct(p2);
  
  personne tab1[3]={ "Cooper", 28, "Wolowitz", 27, "Hofstadter", 30 };
  personne tab2[3];
  copy_tab(tab2,tab1,3);
  affiche_tab(tab2,3);
}
