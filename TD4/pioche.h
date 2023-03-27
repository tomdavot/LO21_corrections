#include "jeu.h"
#include <cstddef>

namespace Set {
  class Pioche
  {
    const Carte** cartes;
    size_t nb;

  public:
    explicit Pioche(const Jeu& j);
    bool estVide() const { return nb==0; }
    size_t getNbCartes() const { return nb; }
    const Carte& piocher();
    ~Pioche();

    Pioche(const Pioche&) = delete;
    Pioche& operator=(const Pioche&) = delete;
  };
}
