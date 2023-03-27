#ifndef CPPUNIT_ASSERT_HPP
#define CPPUNIT_ASSERT_HPP

#include <cppunit/result_err.hpp>
#include <sstream>
#include <string>

namespace cppunit {
  void fail(std::string message = "");
  void assertTrue(bool value, std::string message = ""); 
  void assertFalse(bool value, std::string message = "");

  template<typename E, typename T>
  void assertEqual(E expected, T actual, std::string message = "") {
    if (!(expected == actual)) {
      std::ostringstream output;
      if (message.size() == 0) {
        output << "expected <" << expected << "> got <" << actual << ">";
      } else {
        output << message;
      }
      throw new cppunit::ResultErr(output.str());
    }
  }

  template<typename E, typename T>
  void assertNotEqual(E expected, T actual, std::string message = "") {
    if (!(expected != actual)) {
      std::ostringstream output;
      if (message.size() == 0) {
        output << "expected something different from <" << expected << ">";
      } else {
        output << message;
      }
      throw new cppunit::ResultErr(output.str());
    }
  }
}

#endif
