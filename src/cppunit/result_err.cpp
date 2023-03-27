#include <cppunit/result_err.hpp>

cppunit::ResultErr::ResultErr(std::string reason) {
  this->reason = reason;
}

bool cppunit::ResultErr::isOk() {
  return false;
}

bool cppunit::ResultErr::isErr() {
  return true;
}

std::string cppunit::ResultErr::getReason() {
  return this->reason;
}

std::ostream& operator<<=(std::ostream& stream, cppunit::ResultErr& err) {
  stream << "(err \"" << err.getReason() << "\")";
  return stream;
}

std::ostream& operator<<(std::ostream& stream, cppunit::ResultErr& err) {
  stream << "\u001b[31mErr(reason = \"" << err.getReason() << "\")\u001b[0m";
  return stream;
}
