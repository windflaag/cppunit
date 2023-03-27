#include <cppunit/suite_descriptor.hpp>
#include <cstdio>
#include <regex>

void cppunit::SuiteDescriptor::init(std::string name) {
  this->name = name;
  this->functions = new std::vector<std::string>();
  this->computeFunctionName();
}

cppunit::SuiteDescriptor::SuiteDescriptor() {
  this->init("");
}

cppunit::SuiteDescriptor::SuiteDescriptor(std::string name) {
  this->init(name);
}

cppunit::SuiteDescriptor::~SuiteDescriptor() {
  delete this->functions;
}

void cppunit::SuiteDescriptor::addFunction(std::string function) {
  this->functions->push_back(function);
}

std::vector<std::string>* cppunit::SuiteDescriptor::getFunctions() {
  return this->functions;
}

std::ostream& operator<<=(std::ostream& stream, cppunit::SuiteDescriptor& suiteDescriptor) {
  stream << "(suite '" << suiteDescriptor.getName() << " (suites";

  std::vector<std::string>* functions = suiteDescriptor.getFunctions();
  for (auto it = functions->begin(); it != functions->end(); ++it) {
    stream << " '" << *it;
  }

  stream << "))";
  return stream;
}

std::ostream& operator<<(std::ostream& stream, cppunit::SuiteDescriptor& suiteDescriptor) {
  stream << "void " << suiteDescriptor.getFunctionName() << "() {";
  stream << "\n\tcppunit::Suite* suite = new cppunit::Suite(\"" << suiteDescriptor.getName() << "\");";

  std::vector<std::string>* functions = suiteDescriptor.getFunctions();
  for (auto it = functions->begin(); it != functions->end(); ++it) {
    stream << "\n\tsuite->addFunction(cppunit::Function(&" << *it << ", \"" << *it << "\"));";
  }

  stream << "\n\tcppunit::Report* report = suite->execute();";
  stream << "\n\tstd::cout << *report << std::endl;";
  stream << "\n\tdelete report;";
  stream << "\n\tdelete suite;";
  stream << "\n}";
  return stream;
}

std::string cppunit::SuiteDescriptor::getName() {
  return this->name;
}

std::string cppunit::SuiteDescriptor::getFunctionName() {
  return this->functionName;
}

std::regex regexOfPoint ("[.]");
std::regex regexOfSlash ("[/]");
std::regex regexOfSpecialChar ("[+\\-*#]");

void cppunit::SuiteDescriptor::computeFunctionName() {
  std::string escapedName = this->name;
  escapedName = std::regex_replace(escapedName, regexOfPoint, "_");
  escapedName = std::regex_replace(escapedName, regexOfSlash, "__");
  escapedName = std::regex_replace(escapedName, regexOfSpecialChar, "_");
  this->functionName = "suite__" + escapedName;
}
