#include <cppunit/suite.hpp>
#include <cppunit/result_err.hpp>
#include <cppunit/result_ok.hpp>

cppunit::Suite::Suite(std::string name) {
  this->name = name;
  this->functions = new std::vector<cppunit::Function>();
}

cppunit::Suite::Suite(std::string name, std::vector<cppunit::Function> functions) {
  this->name = name;
  this->functions = new std::vector<cppunit::Function>();
  *(this->functions) = functions;
}

cppunit::Suite::Suite(std::string name, std::vector<cppunit::Function>* functions) {
  this->name = name;
  this->functions = new std::vector<cppunit::Function>();
  *(this->functions) = *functions;
}

cppunit::Suite::~Suite() {
  delete this->functions;
}

void cppunit::Suite::addFunction(Function function) {
  this->functions->push_back(function);
}

cppunit::Result* cppunit::Suite::executeFunction(Function function) {
  try {
    function.getFunction()();
    return new cppunit::ResultOk();
  } catch (cppunit::ResultErr* err) {
    return err;
  } catch (std::exception* err) {
    return new cppunit::ResultErr(err->what());
  }
}

cppunit::Report* cppunit::Suite::execute() {
  cppunit::Report* report = new cppunit::Report(this->name);
  for (auto it = this->functions->begin(); it != this->functions->end(); ++it) {
    report->addRecord(*it, this->executeFunction(*it));
  }
  return report;
}

std::string cppunit::Suite::getName() {
  return this->name;
}

std::vector<cppunit::Function>* cppunit::Suite::getFunctions() {
  return this->functions;
}

std::ostream& operator<<=(std::ostream& stream, cppunit::Suite& suite) {
  stream << "(suite '" << suite.getName() << "(functions";

  std::vector<cppunit::Function>* functions = suite.getFunctions();
  for (auto it = functions->begin(); it != functions->end(); ++it) {
    stream << " " <<= *it;
  }

  stream << "))";
  return stream;
}

std::ostream& operator<<(std::ostream& stream, cppunit::Suite& suite) {
  stream << "cppunit::Suite(suite = " << suite.getName() << ") {";

  std::vector<cppunit::Function>* functions = suite.getFunctions();
  for (auto it = functions->begin(); it != functions->end(); ++it) {
    stream << "\n\t" << *it;
  }

  stream << "\n}";
  return stream;
}
