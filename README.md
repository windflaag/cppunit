# CppUnit

JUnit inspired C++ unit testing framework

## Building

- git clone the repository
- run `make` (it will run both `cmake` and `make`)
- run `make tests` if you want to run CppUnit tests again CppUnit

## Using CppUnit

### Writing test cases

You should write test cases in a separate `tests` directory in the root of your project. Use the `<cppunit/*.hpp>` header files to include assertions (at `<cppunit/assert.hpp>`) and some more things, for example the result types.
You can also pass a custom fail message to assertions.

this is an example of a test case function:

```cpp
//! test
void functionThatTestsSomething() {
  // body
}
```

### Generating test runner

After writing test cases you now have to generate the sources of the `test runner`, the program that will collect all your test and run them properly. This is done by using an included utility of this project: `cppunit-cli`.
You should call it like `cppunit-cli <test-folder>`, it will generate in the *current working directory* a file called `main.cpp` that contains the test runner. Compile it with a custom cmake target or make or what you prefer.
You could use the tests directory of this project as a "template" for your cmake target if you want to.

### Running test cases

The test runner will instance all suites one by one and run them in sequence, the it will print *gradually* the output of the suites.

### Details and Problems

Currently `CppUnit` collect tests cases by searching for a comment
```cpp
//! test
```
inside the tests file with a suitable extension (cc, cpp, hpp, hh).

All test functions should be of type `void (function*)()`, that is a void function which accepts zero parameters.

All test files are included with
```cpp
#include<path/to/file>
```
so it is your fault if there are some circular imports, just make sure that everything is ok.

### Example of Test Runner Output

This is an example from CppUnit's tests of CppUnit:

```txt
cppunit::Report(suite = /home/refo/Documents/cppunit/tests/cppunit/assert_equal_not_equal.cpp) {
        assertEqualShouldNotFail :: Ok
        assertEqualShouldFail :: Ok
        assertNotEqualShouldNotFail :: Ok
        assertNotEqualShouldFail :: Ok
}
total score = 100%
cppunit::Report(suite = /home/refo/Documents/cppunit/tests/cppunit/assert_fail.cpp) {
        failShouldFail :: Ok
}
total score = 100%
cppunit::Report(suite = /home/refo/Documents/cppunit/tests/cppunit/assert_custom_message.cpp) {
        assertTrueCustomMessage :: Ok
        assertFalseCustomMessage :: Ok
        assertEqualCustomMessage :: Ok
        assertNotEqualCustomMessage :: Ok
        failCustomMessage :: Ok
}
total score = 100%
cppunit::Report(suite = /home/refo/Documents/cppunit/tests/cppunit/assert_true_false.cpp) {
        assertTrueShouldFailWithFalse :: Ok
        assertFalseShouldFailWithTrue :: Ok
        assertTrueShouldNotFailWithTrue :: Ok
        assertFalseShouldNotFailWithFalse :: Ok
}
total score = 100%
```

This is not just plain text, it's coloured with some unicode escapes, so make sure your console or terminal emulator supports ansi colors.
It should work fine even without this type of support (probably) but it would be like a punch in the eyes, lmao.
