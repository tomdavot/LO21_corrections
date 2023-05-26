#include "agenda.h"

TIME::Agenda& TIME::Agenda::operator<<(TIME::Evt1j& e) {
  tab.push_back(&e);
  return *this;
}

void TIME::Agenda::afficher(std::ostream& f) const{
  f<<"Agenda:"<<std::endl;
  for(unsigned i=0; i<tab.size(); i++)
    tab[i]->afficher(f); 
  f<<"##########"<<std::endl;
}

TIME::Agenda::~Agenda(){ }
