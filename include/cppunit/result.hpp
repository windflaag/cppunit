#ifndef CPPUNIT_RESULT_HPP
#define CPPUNIT_RESULT_HPP

#include <ostream>
#include <string>

namespace cppunit {
  class Result {
    public:
      virtual ~Result();
      virtual bool isErr() = 0;
      virtual bool isOk() = 0;
  };
}

std::ostream& operator<<=(std::ostream& stream, cppunit::Result* result);
std::ostream& operator<<(std::ostream& stream, cppunit::Result* result);

#endif
