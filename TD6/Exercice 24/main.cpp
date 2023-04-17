#include<iostream>
#include<string>

#include "graph.h"


using namespace std;

int main() {
  try{
    Graph G1("G1",5); cout<<G1;
    G1.addEdge(0,1); G1.addEdge(0,2); G1.addEdge(1,2); G1.addEdge(1,3);
    G1.addEdge(1,4); G1.addEdge(3,0);
    cout<<G1;
  }catch(exception e){ std::cout<<e.what()<<"\n"; }
  
  return 0;
}
