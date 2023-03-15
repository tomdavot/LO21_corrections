void essai_alloc(){
  int* pt_int;
  double* pt_double;
  // pt_int=(int*)malloc(sizeof(int));
  pt_int = new int;
 
  // pt_double=(double*)malloc(sizeof(double)*100);
  pt_double= new double[100];
  
  // free(pt_int);
  delete pt_int;
  
  // free(pt_double);
  // Important de ne pas oublier [] sinon seule la première case du tableau est libérée
  delete[] pt_double;
  
}
