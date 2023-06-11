#if !defined(MY_LOG_H)
#define MY_LOG_H

#include "agenda.h"
#include "log.h"

class MyLogObjet : public Log {
 private:
  TIME::Agenda evts;
  
 public:
  void addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string& s);
  void displayLog(std::ostream& f) const;
};
#endif
