#if !defined(LOG_H)
#define LOG_H

#include "timing.h"
#include<iostream>

class Log {
 public:
  virtual void addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string& s)=0;
  virtual void displayLog(std::ostream& f) const=0;
};


#endif
