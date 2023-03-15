void exercice11()
{
  // invalide car une référence doit référer à une variable
  //  double& d1=36;
  
  double d2=36;
  double& ref=d2;
  ref=4; // valide car équivalent à d2=4
  const double d3=36;
  const double& d4=36; // valide avec le mot clé const : cela revient à créer un espace mémoire contenant la valeur constante 36 qui sera alors seulement accessible en lecture
  const double& d5=d2;

   // invalide car la référence est constante, elle n'est accessible que en lecture
  //  d5=21;
  const double& d6=d3;

  // impossible d'avoir une référence non constante pour pointer vers une constante
  //double& ref2=d6;
  
  int i=4;
   // erreur de type int!=double
  //  double& d7=i;
  
  const double& d8=i; // les conversions constantes sont possibles, un espace mémoire dédié est alors créé (comme pour le cas const double & d4 =36)
  // erreur car référence constante, on ne peut pas la modifier
  //  d8 = 3; 
}
