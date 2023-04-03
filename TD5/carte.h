#pragma once
#include "set.h"

namespace Set {

  class Carte
  {
    friend class Jeu;
    Couleur couleur;
    Nombre nombre;
    Forme forme;
    Remplissage remplissage;


  Carte(Couleur c, Nombre n, Forme f, Remplissage r) : couleur(c), nombre(n), forme(f), remplissage(r) {}

  public:
    Couleur getCouleur() const { return couleur; }
    Nombre getNombre() const { return nombre; }
    Forme getForme() const { return forme; }
    Remplissage getRemplissage() const {return remplissage; }
    
  };

  ostream& operator<<(ostream& f, const Carte& c);
}
