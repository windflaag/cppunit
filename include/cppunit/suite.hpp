#ifndef CPPUNIT_SUITE_HPP
#define CPPUNIT_SUITE_HPP

#include <cppunit/report.hpp>
#include <cppunit/function.hpp>
#include <cppunit/result.hpp>
#include <vector>
#include <ostream>

namespace cppunit {
  class Suite {
    private:
      std::string name;
      std::vector<Function>* functions;
      Result* executeFunction(Function function);

    public:
      Suite(std::string name);
      Suite(std::string name, std::vector<Function> functions);
      Suite(std::string name, std::vector<Function>* functions);
      ~Suite();
      void addFunction(Function function);
      std::string getName();
      std::vector<Function>* getFunctions();
      Report* execute();
  };
}

std::ostream& operator<<=(std::ostream& stream, cppunit::Suite& suite);
std::ostream& operator<<(std::ostream& stream, cppunit::Suite& suite);

#endif
