#ifndef CPPUNIT_FUNCTION_HPP
#define CPPUNIT_FUNCTION_HPP

#include <string>
#include <ostream>

namespace cppunit {
  typedef void (*function_t)();

  class Function {
    private:
      function_t function;
      std::string name;

    public:
      Function();
      Function(const Function& other);
      Function(const Function&& other);
      Function(function_t function, std::string name);
      ~Function();
      void operator=(const Function& other);
      void operator=(const Function&& other);
      function_t getFunction();
      std::string getName();
  };
}

std::ostream& operator<<=(std::ostream& stream, cppunit::Function& function);
std::ostream& operator<<(std::ostream& stream, cppunit::Function& function);

#endif
