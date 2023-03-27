#include "jeu.h"

namespace Set
{
  class Plateau
  {
    const Carte** cartes;
    size_t nbMax;
    size_t nb;

    public:
    Plateau() = default;
    Plateau(const Plateau& p);
    Plateau& operator=(const Plateau& p);
    
    ~Plateau();
    
    size_t getNbCartes() const { return nb; }

    void ajouter(const Carte& c);
    void retirer(const Carte& c);

    void print(ostream& f = cout) const;
 
  };

  ostream& operator<<(ostream& f, const Plateau& m);
}
