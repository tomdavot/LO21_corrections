#include <iostream>
#include <string>

using namespace std;
struct compte {
  string id;
  int solde;
};

int & operation(compte * tab, string id);


void essai_comptes();
