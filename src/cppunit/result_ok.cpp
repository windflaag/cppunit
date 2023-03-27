#include <cppunit/result_ok.hpp>

bool cppunit::ResultOk::isOk() {
  return true;
}

bool cppunit::ResultOk::isErr() {
  return false;
}

std::ostream& operator<<=(std::ostream& stream, cppunit::ResultOk& ok) {
  stream << "'ok";
  return stream;
}

std::ostream& operator<<(std::ostream& stream, cppunit::ResultOk& ok) {
  stream << "\u001b[32mOk\u001b[0m";
  return stream;
}
