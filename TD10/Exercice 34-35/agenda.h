#pragma once

#include <vector>

#include "evenement.h"


namespace TIME {
  class Agenda {
    std::vector<Evt*> tab;

    public:

    Agenda() =default;
    virtual ~Agenda();

    Agenda(const Agenda&) = delete;
    Agenda& operator=(const Agenda&) =delete;

    Agenda& operator<<(Evt &e);

    void afficher(std::ostream& f = std::cout) const;


    class iterator : public std::vector<Evt*>::iterator
    {
    public:
      Evt & operator*() const
      {
	return *std::vector<Evt*>::iterator::operator *();
      }
    private:
      friend class Agenda;
      iterator(const std::vector<Evt*>::iterator& it) : std::vector<Evt*>::iterator(it) {}
      
    };
    iterator begin() { return iterator(tab.begin()); }
    iterator end() { return iterator(tab.end()); }

    class const_iterator : public std::vector<Evt*>::const_iterator {
    public:
      const Evt& operator *() const
      {
	return *std::vector<Evt*>::const_iterator::operator *();
      }
    private:
      friend class Agenda;
      const_iterator(const std::vector<Evt*>::const_iterator& it) : std::vector<Evt*>::const_iterator(it) {}
    };
    const_iterator cbegin() const { return const_iterator(tab.begin()); }
    const_iterator cend() const { return const_iterator(tab.end()); }
    const_iterator begin() const { return const_iterator(tab.begin()); }
    const_iterator end() const { return const_iterator(tab.end()); }
    
  };
}
