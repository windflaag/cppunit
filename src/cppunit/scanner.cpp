#include <cppunit/suite_descriptor.hpp>
#include <cppunit/scanner.hpp>
#include <cstdio>
#include <regex>
#include <fstream>
#include <filesystem>
#include <stdexcept>

std::regex regexOfComment("//!\\s+test\\s*");
std::regex regexOfFunction("void\\s+(([a-zA-Z_][_a-zA-Z0-9]*)(::[a-zA-Z_][_a-zA-Z0-9]*)*)\\s*\\(\\)");

cppunit::Scanner::Scanner() {
  this->includes = new std::vector<std::string>();
  this->suites = new std::vector<cppunit::SuiteDescriptor*>();
}

cppunit::Scanner::~Scanner() {
  delete this->includes;
  for (auto it = this->suites->begin(); it != this->suites->end(); ++it) {
    delete *it;
  }
  delete this->suites;
}

std::regex regexOfCppExtension ("^(\\.((cpp)|(cc)|(hpp)|(hh)))$");
void cppunit::Scanner::exploreFile(std::string filepath) {
  if (! std::filesystem::exists(filepath))
    throw new std::runtime_error("file " + filepath + " doesn't exists");
  if (std::filesystem::is_directory(filepath)) {
    for (auto entry : std::filesystem::directory_iterator(filepath)) {
      this->exploreFile(entry.path().string());
    }
  } else {
    const auto path = std::filesystem::path(filepath);
    if (path.has_extension()) {
      if (std::regex_match(path.extension().c_str(), regexOfCppExtension)) {
        this->addFile(filepath);
      }
    }
  }
}

void cppunit::Scanner::addFile(std::string filepath) {
  this->includes->push_back(filepath);
  this->suites->push_back(new cppunit::SuiteDescriptor(filepath));
  std::ifstream file; file.open(filepath);

  std::string line;
  bool functionTrigger = false;
  while(std::getline(file, line)) {
    if (!functionTrigger) {
      if (std::regex_match(line, regexOfComment)) {
        functionTrigger = true;
      }
    } else {
      std::smatch sm;
      if (std::regex_search(line, sm, regexOfFunction)) {
        this->suites->back()->addFunction(std::string(sm[1]));
        functionTrigger = false;
      }
    }
  }

  file.close();
}

std::vector<std::string>* cppunit::Scanner::getIncludes() {
  return this->includes;
}

std::vector<cppunit::SuiteDescriptor*>* cppunit::Scanner::getSuites() {
  return this->suites;
}

std::ostream& operator<<=(std::ostream& stream, cppunit::Scanner& scanner) {
  stream << "(scanner (includes";
  std::vector<std::string>* includes = scanner.getIncludes();
  for (auto it = includes->begin(); it != includes->end(); it++) {
    stream << " '" << (*it);
  }

  stream << ") (suites";
  std::vector<cppunit::SuiteDescriptor*>* suites = scanner.getSuites();
  for (auto it = suites->begin(); it != suites->end(); ++it) {
    stream << " " <<= *(*it);
  }
  stream << "))";
  return stream;
}

std::ostream& operator<<(std::ostream& stream, cppunit::Scanner& scanner) {
  stream << "// includes";
  stream << "\n#include <iostream>";
  stream << "\n#include <cppunit/suite.hpp>";
  stream << "\n#include <cppunit/report.hpp>";

  std::vector<std::string>* includes = scanner.getIncludes();
  for (auto it = includes->begin(); it != includes->end(); it++) {
    stream << "\n#include \"" << (*it) << "\"";
  }

  std::vector<cppunit::SuiteDescriptor*>* suites = scanner.getSuites();
  stream << "\n// suites";
  for (auto it = suites->begin(); it != suites->end(); ++it) {
    stream << "\n// suite " << (*it)->getName() << "\n" << *(*it);
  }
  stream << "\n// main";
  stream << "\nint main() {";
  for (auto it = suites->begin(); it != suites->end(); ++it) {
    stream << "\n\t" << (*it)->getFunctionName() << "();";
  }
  stream << "\n}";
  return stream;
}
