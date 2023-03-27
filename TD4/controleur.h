#include "plateau.h"
#include "pioche.h" 

namespace Set {
  class Controleur
  {
    Jeu jeu;
    Pioche* pioche;
    Plateau plateau;
  public:
    
    Controleur();

    ~Controleur();

    void distribuer();
    
    const Plateau& getPlateau() const { return plateau; }
  };
}
