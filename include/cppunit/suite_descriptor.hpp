#ifndef CPPUNIT_SUITE_DESCRIPTOR_HPP
#define CPPUNIT_SUITE_DESCRIPTOR_HPP

#include <string>
#include <vector>
#include <ostream>

namespace cppunit {
  class SuiteDescriptor {
    private:
      std::string name;
      std::string functionName;
      std::vector<std::string>* functions;
      void init(std::string name);
    public:
      SuiteDescriptor();
      SuiteDescriptor(std::string name);
      ~SuiteDescriptor();
      void addFunction(std::string function);
      std::string getName();
      std::string getFunctionName();
      std::vector<std::string>* getFunctions();
      void computeFunctionName();
  };
}

std::ostream& operator<<=(std::ostream& stream, cppunit::SuiteDescriptor& suiteDescriptor);
std::ostream& operator<<(std::ostream& stream, cppunit::SuiteDescriptor& suiteDescriptor);

#endif
