#include "plateau.h"
#include "carte.h"

namespace Set {

  Plateau::Plateau(const Plateau& p) : cartes(new const Carte*[p.nb]), nb(p.nb), nbMax(p.nb)
  {
    for (size_t i = 0; i < nb; i++)
      cartes[i] = p.cartes[i];
  }

  Plateau& Plateau::operator=(const Plateau& p)
  {
    if (this != &p) {
      if (p.nb > nbMax) {
	const Carte** newtab = new const Carte*[p.nb];
	for (size_t i = 0; i < nb; i++) newtab[i] = p.cartes[i];
	auto old = cartes;
	cartes = newtab;
	nb=nbMax = p.nb;
	delete[] old;
      }
      else {
	for (size_t i = 0; i < nb; i++) cartes[i] = p.cartes[i];
	nb = p.nb;
      }
    }
    return * this;
  }

  Plateau::~Plateau()
  {
    delete [] cartes;
  }

  void Plateau::ajouter(const Carte& c)
  {
    if (nb == nbMax) {
      const Carte** newtab = new const Carte*[(nbMax + 1) * 2];
      for (size_t i = 0; i < nb; i++)
	newtab[i] = cartes[i];
      
      auto old = cartes;
      cartes = newtab;
      nbMax = (nbMax + 1) * 2;
      delete[] old;
    }
    cartes[nb++] = &c;
  }

  void Plateau::retirer(const Carte& c)
  {
    size_t i = 0;
    while (i < nb && cartes[i] != &c) i++;
    if (i == nb) throw SetException("Carte inexistante");
    i++;
    
    while (i < nb) {
      cartes[i - 1] = cartes[i]; i++;
    }
    nb--;
  }

  void Plateau::print(ostream& f) const
  {
    for (size_t i = 0; i < nb; i++) {
      if (i % 4 == 0) f << "\n";
      f << *cartes[i] << " ";
    }
    f << "\n";
  }
  ostream& operator<<(ostream& f, const Plateau& m)
  {
    m.print(f);
    return f;
  }

  
} 


  
