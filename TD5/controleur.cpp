#include "controleur.h"

namespace Set {

  Controleur::Controleur()
  { 
    pioche = new Pioche();
  }
  
  Controleur::~Controleur()
  {
    delete pioche; 
  }

  void Controleur::distribuer()
  {
    if (plateau.getNbCartes() < 12)
      while (!pioche->estVide() && plateau.getNbCartes() < 12)
	plateau.ajouter(pioche->piocher());
    else
      if (!pioche->estVide())
	plateau.ajouter(pioche->piocher());
  }
}
