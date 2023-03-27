#include "pioche.h"
using namespace Set;

int main() {
  
  try {

    printCouleurs();
    printNombres();
    printFormes();
    printRemplissages();

    Jeu jeu;
    std:: cout << jeu.getCarte(0) << std::endl;
    //    std:: cout << jeu.getCarte(83) << std::endl;

    Pioche p1(jeu), p2(jeu);
    for(size_t i=0; i<5; ++i){
      std::cout << "Jeu 1: " << p1.piocher() << std::endl;
      std::cout << "Jeu 2: " << p2.piocher() << std::endl;
    }

  }
  catch (SetException& e) {
    std::cout << e.getInfo() << "\n";
  }
	


  return 0;
}
