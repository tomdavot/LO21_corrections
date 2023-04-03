#include "controleur.h"
using namespace Set;

int main() {
  try {
 
    Jeu &jeu= Jeu::getJeu();

    auto it =jeu.getIterator();
    for(auto it = jeu.getIterator();!it.isDone();it.next())
      std::cout<< it.currentItem() << std::endl;

    Controleur c;
    for(auto it=c.getPlateau().begin();it!=c.getPlateau().end();++it)
      std::cout<< *it << std::endl;
    
    for(auto it : c.getPlateau()){
      std::cout<< it << std::endl;
    }
    

  }
  catch (SetException& e) {
    std::cout << e.getInfo() << "\n";
  }
	


  return 0;
}
