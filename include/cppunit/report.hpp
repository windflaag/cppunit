#ifndef CPPUNIT_REPORT_HPP
#define CPPUNIT_REPORT_HPP

#include <cppunit/function.hpp>
#include <cppunit/result.hpp>
#include <string>
#include <vector>
#include <ostream>

namespace cppunit {
  class Report {
    private:
      std::string suiteName;
      std::vector<std::pair<Function, Result*>>* records;
    public:
      Report(std::string suiteName);
      ~Report();
      void addRecord(Function function, Result* result);
      std::string getSuiteName();
      std::vector<std::pair<cppunit::Function, cppunit::Result*>>* getRecords();
  };
}

std::ostream& operator<<=(std::ostream& stream, cppunit::Report& report);
std::ostream& operator<<(std::ostream& stream, cppunit::Report& report);

#endif
