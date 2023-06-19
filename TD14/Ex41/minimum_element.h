#if !defined(_minimum_element_T_H)
#define _minimum_element_T_H

namespace TD {
 template<class IT> IT element_minimum(IT it1, IT it2);

 template<class IT, class COMP> IT element_minimum(IT it1, IT it2, COMP comp);
 
}

template<class IT>
IT TD::element_minimum(IT it1, IT it2){
  IT it_min=it1;
  ++it1;
  while(it1!=it2){
    if (*it1<*it_min) it_min=it1;
    ++it1;
  }
  return it_min;
}


template<class IT, class COMP>
  IT TD::element_minimum(IT it1, IT it2, COMP comp){
  IT it_min=it1;
  ++it1;
  while(it1!=it2){
    if (comp(*it1,*it_min)) it_min=it1;
    ++it1;
  }
  return it_min;
}

#endif
