#pragma once

#include <vector>

#include "evenement.h"


namespace TIME {
  class Agenda {
    std::vector<Evt1j*> tab;

    public:
    Agenda() =default;
    virtual ~Agenda();

    Agenda(const Agenda&) = delete;
    Agenda& operator=(const Agenda&) =delete;

    Agenda& operator<<(Evt1j &e);

    void afficher(std::ostream& f = std::cout) const;
  };
}
