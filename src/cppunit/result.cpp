#include <cppunit/result.hpp>
#include <cppunit/result_ok.hpp>
#include <cppunit/result_err.hpp>

cppunit::Result::~Result() { /*empty implementation*/ }

std::ostream& operator<<=(std::ostream& stream, cppunit::Result* result) {
  if (result->isOk()) {
    cppunit::ResultOk* ok = dynamic_cast<cppunit::ResultOk*>(result);
    stream <<= *ok;   
  } else {
    cppunit::ResultErr* err = dynamic_cast<cppunit::ResultErr*>(result);
    stream <<= *err;
  }
  return stream;
}

std::ostream& operator<<(std::ostream& stream, cppunit::Result* result) {
  if (result->isOk()) {
    cppunit::ResultOk* ok = dynamic_cast<cppunit::ResultOk*>(result);
    stream << *ok;   
  } else {
    cppunit::ResultErr* err = dynamic_cast<cppunit::ResultErr*>(result);
    stream << *err;
  }
  return stream;
}
