#include <algorithm>
#include <iterator>
#include <string>
#include "graph.h"



Graph::Graph(const string& n, size_t nb) : nb_edges(0), name(n), adj(nb) {}
  
const string& Graph::getName() const
{
  return name;
}
  
size_t Graph::getNbVertices() const
{
  return adj.size();
}
  
size_t Graph::getNbEdges() const
{
  return nb_edges;
}
  
void Graph::addEdge(unsigned int i, unsigned int j)
{
  if(i>= getNbVertices() || j>=getNbVertices())
    throw GraphException("Erreur, le sommet " + to_string(max(i,j)) + " n'existe pas dans le graphe " + getName());

  if(find(adj[i].begin(),adj[i].end(),j)!=adj[i].end())
    throw GraphException("Erreur, l'arc (" + to_string(i) + "," + to_string(j) + ") existe déjà dans le graphe " + getName());

  adj[i].push_back(j);
  ++nb_edges;
}
  
void Graph::removeEdge(unsigned int i, unsigned int j) {
  if(i>= getNbVertices() || j>=getNbVertices())
    throw GraphException("Erreur, le sommet " + to_string(max(i,j)) + " n'existe pas dans le graphe " + getName());

  auto it = find(adj[i].begin(),adj[i].end(),j);
  if(it==adj[i].end())
    throw GraphException("Erreur, l'arc (" + to_string(i) + "," + to_string(j) + ") n'existe pas dans le graphe " + getName());

  adj[i].erase(it);
  --nb_edges;
}
  
const list<unsigned int>& Graph::getSuccessors(unsigned int i) const
{
    if(i>= getNbVertices())
      throw GraphException("Erreur, le sommet " + to_string(i) + " n'existe pas dans le graphe " + getName());
    return adj[i];
}
  
const list<unsigned int> Graph::getPredecessors(unsigned int i) const
{
  list<unsigned> predecessors;
  if(i>= getNbVertices())
    throw GraphException("Erreur, le sommet " + to_string(i) + " n'existe pas dans le graphe " + getName());
  for(size_t j=0; j<getNbVertices(); ++j){
    if(j!=i && find(adj[j].begin(),adj[j].end(),i)!=adj[j].end())
      predecessors.push_back(j);
  }
  return predecessors;
}

ostream& operator<<(ostream& f, const Graph& G){
  f<<"Graph "<<G.getName()<<" ("<<G.getNbVertices()
   <<" vertices and "<<G.getNbEdges()<<" edges)"<<"\n";
  for(size_t i=0; i<G.getNbVertices(); i++) {
    f<<i<<":";
    for(list<unsigned int>::const_iterator it=G.getSuccessors(i).begin(); it!=G.
	  getSuccessors(i).end(); ++it) f<<*it<<" ";
    f<<"\n";
  }
  return f;
}
