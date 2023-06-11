#include <ostream>
#if !defined(_EVENEMENT_H)
#define _EVENEMENT_H

#include <iostream>
#include <string>
#include "timing.h"

namespace TIME
{
  class Evt {
    std::string sujet;
  public:
    Evt(const std::string& s) : sujet(s) {}

    const std::string & getDescription() const { return sujet; }

    virtual std::string toString() const=0;
    
    void afficher(std::ostream& f=std::cout) const;

    virtual Evt* clone() const=0;

    virtual ~Evt()=0;
  };
  
  class Evt1j : public Evt
  {
  private:
    Date date;

  public:
    
    Evt1j(const Date& d, const std::string& s): Evt(s), date(d)
    {}

    const Date & getDate() const { return date; }

    virtual std::string toString() const;
    

    Evt1j* clone() const;
    
  };

  class EvtPj : public Evt
  {
    Date debut, fin;

    public:
    EvtPj(const Date& d, const Date& f, const std::string& s) : Evt(s), debut(d), fin(f) {}

    const Date& getDateDebut() const { return debut; }
    const Date& getDateFin() const { return fin; }

    virtual std::string toString() const;
    
    EvtPj* clone() const;
  };
  
  class Evt1jDur : public Evt1j
  {
    Horaire debut;
    Duree duree;

  public:
    
    Evt1jDur(const Date &d, const std::string s, const Horaire &h, const Duree &t) : Evt1j(d, s), debut(h), duree(t) {}

    const Horaire & getHoraire() const { return debut; }
    const Duree & getDuree() const {return duree; }

    virtual std::string toString() const;

    Evt1jDur* clone() const;
  };

  class Rdv: public Evt1jDur
  {
    std::string personne, lieu;

  public:
    Rdv(const Date& d, const std::string &s, const Horaire &h,
	const Duree &t, const std::string &p, const std::string &l) : Evt1jDur(d, s, h, t), personne(p), lieu(l) {}


    const std::string & getPersonne() const {return personne;}

    const std::string & getLieu() const {return lieu;}

    virtual std::string toString() const;

    Rdv* clone() const;
    
  };
  
  inline Date getDate(const Evt& e){
    const Evt1j* pt1=dynamic_cast<const Evt1j*>(&e);
    const EvtPj* pt2=dynamic_cast<const EvtPj*>(&e);
    
    if (pt1)
      return pt1->getDate();
    if (pt2)
      return pt2->getDateDebut();
    throw "type evt inattendu";
  }

  inline bool operator<(const Evt& e1, const Evt& e2){
    Date d1=getDate(e1);
    Date d2=getDate(e2);
    if (d1<d2) return true;
    if (d2<d1) return false;
    // d1==d2
    const Evt1jDur* pt1=dynamic_cast<const Evt1jDur*>(&e1);
    const Evt1jDur* pt2=dynamic_cast<const Evt1jDur*>(&e2);
    if (pt1==nullptr && pt2!=nullptr) return true;
    if (pt2==nullptr) return false;
    
    // ce sont deux evt avec un horaire, on les compare
    return pt1->getHoraire()<pt2->getHoraire();
  }
} // namespace TIME
 std::ostream& operator<<(std::ostream&, const TIME::Evt1j&); 
#endif
