#include "evenement.h"

void TIME::Evt1j::afficher(std::ostream& f) const
{
  f<<"***** Evt ********"<<"\n"<<"Date="<<date<<" sujet="<<sujet<<"\n";
}

void TIME::Evt1jDur::afficher(std::ostream& f) const
{
  Evt1j::afficher(f);
  f << "début= " << debut << " duree=" << duree << std::endl;
}

void TIME::Rdv::afficher(std::ostream& f) const
{
  Evt1jDur::afficher(f);
  f << "personne=" << personne << " lieu=" << lieu << std::endl;
}

std::ostream& operator<<(std::ostream& f, const TIME::Evt1j& e){
  e.afficher(f);
  return f;
}

