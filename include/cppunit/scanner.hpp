#ifndef CPPUNIT_SCANNER_HPP
#define CPPUNIT_SCANNER_HPP

#include <cppunit/suite_descriptor.hpp>
#include <string>
#include <vector>
#include <ostream>

namespace cppunit {
  class Scanner {
    private:
      std::vector<std::string>* includes;
      std::vector<SuiteDescriptor*>* suites;
      void addFile(std::string filepath);
    public:
      Scanner();
      ~Scanner();
      void exploreFile(std::string filepath);
      std::vector<cppunit::SuiteDescriptor*>* getSuites();
      std::vector<std::string>* getIncludes();
  };
}

std::ostream& operator<<=(std::ostream& stream, cppunit::Scanner& scanner);
std::ostream& operator<<(std::ostream& stream, cppunit::Scanner& scanner);

#endif
