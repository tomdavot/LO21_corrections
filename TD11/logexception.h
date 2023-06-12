#if !defined(LOGEXCEPTION_H)
#define LOGEXCEPTION_H

#include <iostream>


class LogError : public std::exception {
  std::string info;
 public:
  LogError(const char * s) noexcept:info(s) {}
  const char * what() const noexcept { return info.c_str(); }
};

#endif
