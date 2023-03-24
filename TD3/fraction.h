#include <iostream>
#include <string>

namespace MATH {

   class FractionException {
	std::string info;

	public:
	FractionException(char * error) {
	    info=error;
	}

	const std::string& getInfo(){
	    return info;
	}
	
    };
  
  class Fraction
  {
    int numerateur, denominateur;

    void simplification();
  public:

    Fraction(int n=0,int d=1) : numerateur(n), denominateur(d)
    {
      if(denominateur==0) {
	//denominateur=1;
	//std::cout << "Erreur !" << std::endl;
	throw FractionException((char*)"Erreur denominateur egal a 0");
      }
      simplification();
      std::cout << "Construction de l'objet " << this << std::endl;
      //      setFraction(n, d);
    }

    Fraction() : numerateur(0), denominateur(1) {}
    ~Fraction()
    {
      std::cout << "Destruction de l'objet " << this << std::endl;
    }

    Fraction somme(const Fraction& f) const
    {
      return Fraction(f.getDenominateur()*getNumerateur()+getDenominateur()*f.getNumerateur(),getDenominateur()*f.getDenominateur());
    }

    /*Fraction operator+(const Fraction& f) const
    {
      return Fraction(f.getDenominateur()*getNumerateur()+getDenominateur()*f.getNumerateur(),getDenominateur()*f.getDenominateur());
      }*/

    Fraction& operator++();

    Fraction operator++(int);
    
    inline int getDenominateur() const
    {
      return denominateur;
    }
    inline int getNumerateur() const
    {
      return numerateur;
    }

    void setFraction(int numerateur, int denominateur);
    
  } ;

  Fraction somme(const Fraction &f1, const Fraction &f2);

  Fraction operator+(const Fraction &f1, const Fraction &f2);

}
  std::ostream& operator<<(std::ostream& F, const MATH::Fraction& frac);
  


