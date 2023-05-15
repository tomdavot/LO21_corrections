#include "plateau.h"
#include "pioche.h" 

namespace Set {
  class Controleur
  {
    Pioche* pioche;
    Plateau plateau;
  public:
    
    Controleur();

    ~Controleur();

    void distribuer();
    
    Plateau& getPlateau()  { return plateau; }
    const Pioche& getPioche() const {return *pioche;}
  };
}
