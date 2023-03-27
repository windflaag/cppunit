#include <cppunit/assert.hpp>
#include <cppunit/result_err.hpp>

//! test
void assertTrueCustomMessage() {
  try {
    cppunit::assertTrue(false, "custom_message");
  } catch(cppunit::ResultErr* err) {
    cppunit::assertEqual("custom_message", err->getReason());
  }
}

//! test
void assertFalseCustomMessage() {
  try {
    cppunit::assertFalse(true, "custom_message");
  } catch(cppunit::ResultErr* err) {
    cppunit::assertEqual("custom_message", err->getReason());
  }
}

//! test
void assertEqualCustomMessage() {
  try {
    cppunit::assertEqual(1, 2, "custom_message");
  } catch(cppunit::ResultErr* err) {
    cppunit::assertEqual("custom_message", err->getReason());
  }
}

//! test
void assertNotEqualCustomMessage() {
  try {
    cppunit::assertNotEqual(1, 1, "custom_message");
  } catch(cppunit::ResultErr* err) {
    cppunit::assertEqual("custom_message", err->getReason());
  }
}

//! test
void failCustomMessage() {
  try {
    cppunit::fail("custom_message");
  } catch(cppunit::ResultErr* err) {
    cppunit::assertEqual("custom_message", err->getReason());
  }
}
