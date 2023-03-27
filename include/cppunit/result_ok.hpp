#ifndef CPPUNIT_RESULT_OK_HPP
#define CPPUNIT_RESULT_OK_HPP

#include <cppunit/result.hpp>
#include <string>
#include <ostream>

namespace cppunit {
  class ResultOk : public Result {
    public:
      bool isErr();
      bool isOk();
  };
}

std::ostream& operator<<=(std::ostream& stream, cppunit::ResultOk& resultOk);
std::ostream& operator<<(std::ostream& stream, cppunit::ResultOk& resultOk);

#endif
