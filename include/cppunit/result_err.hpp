#ifndef CPPUNIT_RESULT_ERR_HPP
#define CPPUNIT_RESULT_ERR_HPP

#include <cppunit/result.hpp>
#include <string>
#include <ostream>

namespace cppunit {
  class ResultErr : public Result {
    private:
      std::string reason;
    public:
      ResultErr(std::string reason);
      bool isErr();
      bool isOk();
      std::string getReason();
  };
}

std::ostream& operator<<=(std::ostream& stream, cppunit::ResultErr& resultErr);
std::ostream& operator<<(std::ostream& stream, cppunit::ResultErr& resultErr);

#endif
