#include "evenement.h"
#include <ostream>

TIME::Evt::~Evt() {}

void TIME::Evt::afficher(std::ostream& f) const
{
  f<<"***** Evt ********"<<"\n"<<" sujet="<<sujet<<"\n";
}
// pour un destructeur virtuel pur, on doit déclarer le corps de la méthode


void TIME::Evt1j::afficher(std::ostream& f) const
{
  Evt::afficher(f);
  f<<"Date="<<date<<std::endl;
}

void TIME::EvtPj::afficher(std::ostream& f) const
{
  Evt::afficher(f);
  f<<"Début="<< debut << " Fin="<< fin <<std::endl;
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


TIME::Evt1j *TIME::Evt1j::clone() const
{
  return new Evt1j(*this);
}

TIME::Evt1jDur *TIME::Evt1jDur::clone() const
{
  return new Evt1jDur(*this);
}

TIME::Rdv *TIME::Rdv::clone() const
{
  return new Rdv(*this);
}

TIME::EvtPj* TIME::EvtPj::clone() const
{
  return new EvtPj(* this);
}


std::ostream& operator<<(std::ostream& f, const TIME::Evt1j& e){
  e.afficher(f);
  return f;
}

