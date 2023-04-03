#include "pioche.h"
#include "set.h"

namespace Set {
  Pioche::Pioche() : cartes(new const Carte*[Jeu::getJeu().getNbCartes()]), nb(Jeu::getJeu().getNbCartes())
  {
    size_t i=0;
    for(auto it = Jeu::getJeu().getIterator(); !it.isDone(); it.next())
      cartes[i++] = &it.currentItem();

    
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
