#include <cppunit/assert.hpp>
#include <cppunit/result_err.hpp>

//! test
void failShouldFail() {
  // acqua calda
  try {
    cppunit::fail();
  } catch(cppunit::ResultErr* err) {
    return;
  } 
  throw new cppunit::ResultErr("not failed");
}
