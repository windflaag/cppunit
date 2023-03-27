#include <cppunit/assert.hpp>
#include <cppunit/result_err.hpp>

//! test
void assertEqualShouldNotFail() {
  size_t A = 17;
  size_t B = 17;
  try {
    cppunit::assertEqual(A, B);
  } catch (cppunit::ResultErr* err) {
    cppunit::fail();
  }
}

//! test
void assertEqualShouldFail() {
  size_t A = 17;
  size_t B = 18;
  try {
    cppunit::assertEqual(A, B);
  } catch (cppunit::ResultErr* err) {
    return;
  }
  cppunit::fail();
}

//! test
void assertNotEqualShouldNotFail() {
  size_t A = 17;
  size_t B = 18;
  try {
    cppunit::assertNotEqual(A, B);
  } catch (cppunit::ResultErr* err) {
    cppunit::fail();
  }
}

//! test
void assertNotEqualShouldFail() {
  size_t A = 17;
  size_t B = 17;
  try {
    cppunit::assertNotEqual(A, B);
  } catch (cppunit::ResultErr* err) {
    return;
  }
  cppunit::fail();
}
