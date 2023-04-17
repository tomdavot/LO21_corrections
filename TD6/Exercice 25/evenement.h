#include <ostream>
#if !defined(_EVENEMENT_H)
#define _EVENEMENT_H

#include <iostream>
#include <string>
#include "timing.h"

namespace TIME
{
  
	class Evt1j
	{
	private:
		Date date;
		std::string sujet;
	public:
    
	        Evt1j(const Date& d, const std::string& s): date(d),sujet(s)
		{
			std::cout << "Construction Evt1j\n";
		}
		~Evt1j()
		{
			std::cout << "Destruction Evt1j\n";
		}
    
		const std::string & getDescription() const { return sujet; }
    
		const Date & getDate() const { return date; }
    
		void afficher(std::ostream& f= std::cout) const
		{
			f<<"***** Evt ********"<<"\n"<<"Date="<<date<<" sujet="<<sujet<<"\n";
		}
    
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

		void afficher(std::ostream &f = std::cout) const
		{
			Evt1j::afficher(f);
			f << "début= " << debut << " duree=" << duree << std::endl;
		}

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

		void afficher(std::ostream &f=std::cout) const
		{
			Evt1jDur::afficher(f);
			f << "personne=" << personne << " lieu=" << lieu << std::endl;
		}
    
	};
  
}
#endif
