#include "carte.h"

namespace Set {

  class Combinaison
  {
    const Carte* c1, *c2, *c3;
  public:
  Combinaison(const Carte& u, const Carte& d, const Carte& t) :c1(&u), c2(&d),
      c3(&t) {}

    bool estUnSET() const;

    const Carte& getCarte1() const { return *c1; }
    const Carte& getCarte2() const { return *c2; }
    const Carte& getCarte3() const { return *c3; }
  };

  ostream& operator<<(ostream& f, const Combinaison& c);
}
