#include "jeu.h"

namespace Set
{
  class Plateau
  {
    const Carte** cartes;
    size_t nbMax;
    size_t nb;

    public:
    Plateau() : cartes(nullptr), nbMax(0), nb(0) {} ;
    Plateau(const Plateau& p);
    Plateau& operator=(const Plateau& p);
    
    ~Plateau();
    
    size_t getNbCartes() const { return nb; }

    void ajouter(const Carte& c);
    void retirer(const Carte& c);

    void print(ostream& f = cout) const;

     class const_iterator {
      friend class Plateau;
       const Carte ** current =nullptr;
       const_iterator(const Carte** c) : current(c) {}

     public:
       const_iterator & operator++()
       {
	 current++;
	 return *this;
       }

       const Carte& operator *() const { return **current;}
       
       bool operator!=(const_iterator it) const { return current != it.current; }
      
    };
    const_iterator begin() const { return const_iterator(cartes); }
    const_iterator end() const { return const_iterator(cartes+nb); }

 
  };

  ostream& operator<<(ostream& f, const Plateau& m);
}
