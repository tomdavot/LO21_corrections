#include<map>
#include <set>
#include <iostream>

using namespace std;

template<class Vertex>
class GraphG {
  map<Vertex,set<Vertex> > adj;
  size_t nb_edges;
  string name;
 public:
 GraphG(const string& n):name(n), nb_edges(0){}
  const string& getName() const { return name; }
  size_t getNbVertices() const { return adj.size(); }
  size_t getNbEdges() const { return nb_edges; }
  void addVertex(const Vertex& i);
  void addEdge(const Vertex& i, const Vertex& j);
  void removeEdge(const Vertex& i, const Vertex& j);
  void print(ostream& f) const;
};


template<class V> void GraphG<V>::addVertex(const V& i){
  adj[i];

  // adj.insert(make_pair(i,set<V>()));

  //map<V,set<V> >::iterator it=adj.find(i);
  //if (it==adj.end()) adj[i]=set<V>();
}
template<class V> void GraphG<V>::addEdge(const V& i, const V& j){
  if (adj[i].insert(j)->second)
    nb_edges++;
  adj[j];
}

template<class V> void GraphG<V>::removeEdge(const V& i, const V& j){
  auto it=adj.find(i);
  if (it!=adj.end()) nb_edges-=it->second.erase(j);
}

template<class V>
void GraphG<V>::print(ostream& f) const {
  f<<"Graph "<<getName()<<" ("<<getNbVertices()<<" vertices and "<<getNbEdges()<<"edges)"<<"\n";
  for(typename map<V,set<V> >::const_iterator it=adj.begin(); it!=adj.end(); ++it){
    f<<it->first<<":";
    for(typename set<V>::const_iterator it2=it->second.begin(); it2!=it->second.end()
	  ; ++it2) f<<*it2<<" ";
    f<<"\n";
  }
}

template<class V>
ostream& operator<<(ostream& f, const GraphG<V>& G){
  G.print(f);
  return f;
}
