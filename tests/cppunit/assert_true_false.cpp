#include <cppunit/assert.hpp>
#include <cppunit/result_err.hpp>

//! test
void assertTrueShouldFailWithFalse() {
  try {
    cppunit::assertTrue(false);
  } catch(cppunit::ResultErr* err) {
    return;
  }
  cppunit::fail();
}

//! test
void assertFalseShouldFailWithTrue() {
  try {
    cppunit::assertFalse(true);
  } catch(cppunit::ResultErr* err) {
    return;
  }
  cppunit::fail();
}

//! test
void assertTrueShouldNotFailWithTrue() {
  try {
    cppunit::assertTrue(true);
  } catch(cppunit::ResultErr* err) {
    cppunit::fail();
  }
}

//! test
void assertFalseShouldNotFailWithFalse() {
  try {
    cppunit::assertFalse(false);
  } catch(cppunit::ResultErr* err) {
    cppunit::fail();
  }
}
