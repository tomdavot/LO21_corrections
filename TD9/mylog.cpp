#include "mylog.h"
#include "logexception.h"


void MyLog::displayLog(std::ostream& f) const
{
  for(Agenda::const_iterator it=begin(); it!=end(); ++it)
    f<<dynamic_cast<const TIME::Evt1jDur&>(*it).getDate()
     <<" - "
     <<dynamic_cast<const TIME::Evt1jDur&>(*it).getHoraire()
     <<":"
     <<(*it).getDescription()<<"\n";
}

void MyLog::addEvt(const TIME::Date& d, const TIME::Horaire& h,const std::string& s){
    if (begin()!=end()){
	auto it = --end();
	const TIME::Evt1jDur* lastEvent=dynamic_cast<const TIME::Evt1jDur*>(*it);
	if (d<lastEvent->getDate() || (d==lastEvent->getDate() && h<lastEvent->getHoraire()))
	    throw LogError("Ajout d'un evenement postérieur");
    }
    
    TIME::Evt1jDur e_t = TIME::Evt1jDur(d,s,h,TIME::Duree(0));
    TIME::Evt &e = e_t;
    *this<<e;
}
