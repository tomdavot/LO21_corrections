#pragma once
#include "carte.h"
#include "set.h"
#include <cstddef>

namespace Set {
  class Jeu {
    
    const Carte* cartes[81];

    Jeu();
    ~Jeu();
    Jeu(const Jeu& j) = delete;
    Jeu& operator=(const Jeu& j) = delete;

    struct Handler
    {
      Jeu* jeu;
      Handler() : jeu(nullptr) {}
      ~Handler() { delete jeu; }
    };

    static Handler handler;

    const Carte& getCarte(size_t i) const
    {
      if(i>=81) throw SetException("La carte est invalide");
      return *cartes[i];
    }

  public:
    

    static Jeu & getJeu();
    static void libererJeu();
    
    size_t getNbCartes() const { return 81; }    


    
  };
}
