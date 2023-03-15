#include <iostream>

struct personne
{
  char nom[100];
  unsigned int age;
} ;

void raz(personne &p);

void affiche_struct(const personne &p);

void affiche_tab(const personne * p_tab, size_t size);

void init_struct(personne &p, const char * nom, unsigned age);

void copy_struct(const personne &p_source, personne &p_target);

void copy_tab(const personne *p_source, personne *p_target, size_t size);

void exercice_17();
