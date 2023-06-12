#include "mylogobjet.h"
#include "logexception.h"

void MyLogObjet::addEvt(const TIME::Date &d, const TIME::Horaire &h,
                        const std::string &s)
{

   if (evts.begin()!=evts.end()){
	auto it = --evts.end();
	const TIME::Evt1jDur* lastEvent=dynamic_cast<const TIME::Evt1jDur*>(*it);
	if (d<lastEvent->getDate() || (d==lastEvent->getDate() && h<lastEvent->getHoraire()))
	    throw LogError("Ajout d'un evenement postérieur");
    }
   TIME::Evt1jDur e_t = TIME::Evt1jDur(d,s,h,TIME::Duree(0));
   TIME::Evt &e = e_t;
 
   evts<<e;

}
void MyLogObjet::displayLog(std::ostream& f) const
{
  for(TIME::Agenda::const_iterator it=evts.begin(); it!=evts.end(); ++it)
    f<<dynamic_cast<const TIME::Evt1jDur&>(*it).getDate()
     <<" - "
     <<dynamic_cast<const TIME::Evt1jDur&>(*it).getHoraire()
     <<":"<<(*it).getDescription()<<"\n";
}
