#if !defined(_GRAPH_H)
#define _GRAPH_H

#include <list>
#include<string>
#include <stdexcept>
#include <vector>

using namespace std;

class Graph {

  unsigned nb_edges;
  vector<list<unsigned int> > adj;
  string name;
  
 public:
  Graph(const string& n, size_t nb);
  
  const string& getName() const;
  
  size_t getNbVertices() const;
  
  size_t getNbEdges() const;
  
  void addEdge(unsigned int i, unsigned int j);
  
  void removeEdge(unsigned int i, unsigned int j);
  
  const list<unsigned int>& getSuccessors(unsigned int i) const;
  
  const list<unsigned int> getPredecessors(unsigned int i) const;
};

ostream& operator<<(ostream& f, const Graph& G);




class GraphException : public exception {
  string info;
 public:
  GraphException(const string& i) noexcept : info(i){}
  virtual ~GraphException() noexcept {}
  const char * what() const noexcept { return info.c_str(); }
};



#endif
