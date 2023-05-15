#include "jeu.h"

namespace Set {

  Jeu::Jeu()
  {
    size_t i = 0;
    for (auto c : Couleurs)
      for (auto v : Nombres)
	for (auto f : Formes)
	  for (auto r : Remplissages)
	    cartes[i++] = new Carte(c, v, f, r);
  }

  
  Jeu::~Jeu()
  {
    for (size_t i = 0; i < getNbCartes(); i++)
      delete cartes[i];
  }

  Jeu & Jeu::getJeu()
  {
    if (handler.jeu == nullptr)
      handler.jeu = new Jeu;
    return *handler.jeu;
  }

  void Jeu::libererJeu()
  {
    delete handler.jeu;
    handler.jeu =nullptr;
  }

  Jeu::Handler Jeu::handler = Handler();

}
