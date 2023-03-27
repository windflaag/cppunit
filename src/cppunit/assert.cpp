#include <cppunit/assert.hpp>

void cppunit::fail(std::string message) {
  if (message.size() != 0) {
      throw new cppunit::ResultErr(message);
    } else {
      throw new cppunit::ResultErr("failure");
    }
}

void cppunit::assertTrue(bool value, std::string message) {
  if (!value) {
      if (message.size() != 0) {
        throw new cppunit::ResultErr(message);
      } else {
        throw new cppunit::ResultErr("expected <True> got <False>");
      }
  }
}

void cppunit::assertFalse(bool value, std::string message) {
  if (value) {
      if (message.size() != 0) {
        throw new cppunit::ResultErr(message);
      } else {
        throw new cppunit::ResultErr("expected <False> got <True>");
      }
  }
}
