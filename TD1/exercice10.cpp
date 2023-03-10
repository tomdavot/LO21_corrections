void funct(){

  //  double * pt0=0;
  // C'est préférable d'utiliser nullptr (qui n'existe pas en C) à NULL ou 0 
  double * pt0=nullptr;
  
  // Ne compile pas, pas de conversion entre double et int*
  //double * pt1=4096;
  double *pt1;
  
  // ok mais ne jamais faire ça en vrai 
  double * pt2=(double *)4096;

  // Il est possible de convertir de façon implicite un n'importe quel pointeur vers void * mais pas l'inverse
  void * pt3=pt1;
  //  pt1=pt3;
  pt1=(double *)pt3;

  // Il est possible de convertir un pointeur non constant vers un pointeur constant mais pas l'inverse
  double d1=36;
  const double d2=36;
  double * pt4=&d1;
  const double * pt5=&d1;
  *pt4=2.1;
  //  *pt5=2.1;

  // Ne compile pas car pt4 n'est pas un pointeur constant 
  //  pt4=&d2;
  pt5=&d2;
  
  double * const pt6=&d1;
  // Ne compile pas car pt6 ne peut pas pointer vers une autre valeur
  //pt6=&d1;
  *pt6=2.78; // mais on peut changer la valeur de la variable pointée

  // Ne compile pas car d2 est constant
  // double * const pt6b=&d2;

  // On ne peut ni modifier la valeur pointée ni changer d'adresse dans le pointeur
  const double * const pt7=&d1;
  //  pt7=&d1;
  // *pt7=2.78;

  // double const * est équivalent à const double *
  double const *  pt8=&d1;
  pt8=&d2;
  pt8=&d1;
  //  *pt8=3.14;
}
