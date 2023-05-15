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
    

    class Iterator {
      friend class Jeu;
      size_t i;
      Iterator() = default;
      
    public:
      bool isDone() const { return i== Jeu::getJeu().getNbCartes(); }
      void next()
      {
	if(isDone())
	  throw SetException("Iterateur a fini de parcourir la sequence");
	i++;
      }

      const Carte& currentItem() const {
	if (isDone()) throw SetException("Iterateur a fini de parcourir la sequence");
	return Jeu::getJeu().getCarte(i);
      }
   
    };
    Iterator getIterator() const
    {
      return Iterator();
    }

    class FormeIterator {
      friend class Jeu;
      size_t i;
      Forme f;
      FormeIterator(Forme forme) : f(forme) {
	if(currentItem().getForme()!=f)
	  next();
      } 
      
    public:
      bool isDone() const { return i== Jeu::getJeu().getNbCartes(); }
      void next()
      {
	if(isDone())
	  throw SetException("Iterateur a fini de parcourir la sequence");
	
	while(!isDone() && Jeu::getJeu().getCarte(i).getForme() != f)
	  i++;
      }

      const Carte& currentItem() const {
	if (isDone()) throw SetException("Iterateur a fini de parcourir la sequence");
	return Jeu::getJeu().getCarte(i);
      }
   
    };
     FormeIterator getFormeIterator(Forme f) const
    {
      return FormeIterator(f);
    }

    
  };
}
