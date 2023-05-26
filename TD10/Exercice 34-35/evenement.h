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

    virtual void afficher(std::ostream& f=std::cout) const;

    virtual Evt* clone() const=0;

    virtual ~Evt()=0;
  };
  
  class Evt1j : public Evt
  {
  private:
    Date date;

  public:
    
    Evt1j(const Date& d, const std::string& s): Evt(s), date(d)
    {
      std::cout << "Construction Evt1j\n";
    }
    virtual ~Evt1j()
    {
      std::cout << "Destruction Evt1j\n";
    }
    
    const Date & getDate() const { return date; }

    void afficher(std::ostream& f= std::cout) const;

    Evt1j* clone() const;
    
  };

  class EvtPj : public Evt
  {
    Date debut, fin;

    public:
    EvtPj(const Date& d, const Date& f, const std::string& s) : Evt(s), debut(d), fin(f) {}

    const Date& getDateDebut() const { return debut; }
    const Date& getDateFin() const { return fin; }

    void afficher(std::ostream& f= std::cout) const;

    EvtPj* clone() const;
  };
  
  class Evt1jDur : public Evt1j
  {
    Horaire debut;
    Duree duree;

  public:
    
    Evt1jDur(const Date &d, const std::string s, const Horaire &h, const Duree &t) : Evt1j(d, s), debut(h), duree(t)
    {
      std::cout << "Construction Evt1jDur\n";
    }
    ~Evt1jDur()
    {
      std::cout << "Destruction Evt1jDur\n";
    }

    const Horaire & getHoraire() const { return debut; }
    const Duree & getDuree() const {return duree; }

    // mot-clé virtual non obligatoire mais possible dans les redéfinitions 
    virtual void afficher(std::ostream &f = std::cout) const;

    Evt1jDur* clone() const;
  };

  class Rdv: public Evt1jDur
  {
    std::string personne, lieu;

  public:
    Rdv(const Date& d, const std::string &s, const Horaire &h,
	const Duree &t, const std::string &p, const std::string &l) : Evt1jDur(d, s, h, t), personne(p), lieu(l)
    {
      std::cout << "Construction Rdv\n";
    }
    ~Rdv()
    {
      std::cout << "Destruction Rdv\n";
    }


    const std::string & getPersonne() const {return personne;}

    const std::string & getLieu() const {return lieu;}

    void afficher(std::ostream &f=std::cout) const;

    Rdv* clone() const;
    
  };
  

  } // namespace TIME
 std::ostream& operator<<(std::ostream&, const TIME::Evt1j&); 
#endif
