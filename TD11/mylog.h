#if !defined(MY_LOG_H)
#define MY_LOG_H

#include "log.h"
#include "agenda.h"

class MyLog : public Log, private TIME::Agenda {
 public:
  void addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string& s);
  void displayLog(std::ostream& f) const;
};


#endif
