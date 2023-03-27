#include "pioche.h"
#include "set.h"

namespace Set {
  Pioche::Pioche(const Jeu& j) : cartes(new const Carte*[j.getNbCartes()]), nb(j.getNbCartes())
  {
    for(size_t i=0; i <nb; i++)
      cartes[i] = &j.getCarte(i);

    
    // suffle (très naif)
    for(size_t it=0; it<2*nb ; ++it){
      size_t a = rand() % nb,  b = rand() % nb; // on tire deux positions entre 0 et nb
      const Carte * tmp = cartes[a];
      cartes[a]=cartes[b];
      cartes[b]=tmp;
    }
      
  }

  const Carte& Pioche::piocher()
  {
    if(estVide()) throw SetException("La pioche est vide");
    nb--;
    return *cartes[getNbCartes()];

  }

  Pioche::~Pioche()
  {
    delete [] cartes;
  }
}
