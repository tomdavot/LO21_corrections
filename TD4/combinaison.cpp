#include "combinaison.h"

namespace Set {
  bool Combinaison::estUnSET() const
  {
    bool c = (c1->getCouleur() == c2->getCouleur() && c1->getCouleur() == c3->
	      getCouleur()) || (c1->getCouleur() != c2->getCouleur() && c1->getCouleur
				() != c3->getCouleur() && c2->getCouleur() != c3->getCouleur());
    
    bool n = (c1->getNombre() == c2->getNombre() && c1->getNombre() == c3->
	      getNombre()) || (c1->getNombre() != c2->getNombre() && c1->getNombre() !=
			       c3->getNombre() && c2->getNombre() != c3->getNombre());
    
    bool f = (c1->getForme() == c2->getForme() && c1->getForme() == c3->getForme
	      ()) || (c1->getForme() != c2->getForme() && c1->getForme() != c3->
		      getForme() && c2->getForme() != c3->getForme());
    
    bool r = (c1->getRemplissage() == c2->getRemplissage() && c1->getRemplissage
	      () == c3->getRemplissage()) || (c1->getRemplissage() != c2->
					      getRemplissage() && c1->getRemplissage() != c3->getRemplissage() && c2->
					      getRemplissage() != c3->getRemplissage());
    return c && n && f && r;
  }

  ostream& operator<<(ostream& f, const Combinaison& c) {
    f << "[ " << c.getCarte1() << " ; " << c.getCarte2() << " ; " << c.getCarte2
      () << " ]";
    return f;
  }
}
