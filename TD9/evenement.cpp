#include "evenement.h"
#include <ostream>
#include <sstream>

// pour un destructeur virtuel pur, on doit déclarer le corps de la méthode
TIME::Evt::~Evt() {}

void TIME::Evt::afficher(std::ostream &f) const
{
  f << toString();
}


std::string TIME::Evt1j::toString() const
{
  std::stringstream f;
  f<<"Sujet="<<getDescription()<<std::endl;
  f<<"Date="<<date<<std::endl;
  return f.str();
}

std::string TIME::EvtPj::toString() const
{
  std::stringstream f;
  f<<"Sujet="<<getDescription()<<std::endl;
  f<<"Début="<< debut << " Fin="<< fin <<std::endl;
  return f.str();
}


std::string TIME::Evt1jDur::toString() const
{
  std::stringstream f;
  f <<Evt1j::toString()<< "début= " << debut << " duree=" << duree << std::endl;
  return f.str();
}

std::string TIME::Rdv::toString()  const
{
  std::stringstream f;
  f <<Evt1jDur::toString()<< "personne=" << personne << " lieu=" << lieu << std::endl;
  return f.str();
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

