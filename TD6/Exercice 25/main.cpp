#include<iostream>
#include<string>

#include "evenement.h"

using namespace std;
using namespace TIME;

int main() {
  Evt1j e1(Date(4,10,1957),"Spoutnik");
  Evt1j e2(Date(11,6,2013),"Shenzhou");
  e1.afficher();
  e2.afficher();
  
  return 0;
}
