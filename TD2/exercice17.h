#include <iostream>
#include <string>

struct personne
{
  std::string nom;
  unsigned int age;
};

void raz(personne &p);

void affiche_struct(const personne &p);

void affiche_tab(const personne * p_tab, size_t size);

void init_struct(personne &p, const std::string & nom, unsigned age);

void copy_struct(const personne &p_source, personne &p_target);

void copy_tab(const personne *p_source, personne *p_target, size_t size);

void exercice_18();
