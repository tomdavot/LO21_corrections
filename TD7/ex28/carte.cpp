#include "carte.h"

namespace Set {

  ostream& operator<<(ostream& f, const Carte& c) {
    f << "(" << c.getNombre() << "," << c.getCouleur()<<"," <<c.getForme()<<","
      << c.getRemplissage() << ")";
    return f;
  }

}
