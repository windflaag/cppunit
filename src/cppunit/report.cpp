#include <cppunit/report.hpp>
#include <string>

cppunit::Report::Report(std::string suiteName) {
  this->suiteName = suiteName;
  this->records = new std::vector<std::pair<cppunit::Function, cppunit::Result*>>();
}

cppunit::Report::~Report() {
  for (auto it = this->records->begin(); it != this->records->end(); ++it) {
    delete it->second;
  }
  delete this->records;
}

void cppunit::Report::addRecord(Function function, Result* result) {
  this->records->push_back({function, result});
}

std::string cppunit::Report::getSuiteName() {
  return this->suiteName;
}

std::vector<std::pair<cppunit::Function, cppunit::Result*>>* cppunit::Report::getRecords() {
  return this->records;
}

std::ostream& operator<<=(std::ostream& stream, cppunit::Report& report) {
  double score = 0;
  stream << "(report '" << report.getSuiteName() << " (records";

  std::vector<std::pair<cppunit::Function, cppunit::Result*>>* records = report.getRecords();
  for (auto it = records->begin(); it != records->end(); ++it) {
    ((stream << " (" <<= it->first) << " . " <<= it->second) << ")";
    if (it->second->isOk()) {
      score += 1;
    }
  }

  stream << ") " << (score / records->size()) * 100 << ")";
  return stream;
}

std::ostream& operator<<(std::ostream& stream, cppunit::Report& report) {
  double score = 0;
  stream << "cppunit::Report(suite = " << report.getSuiteName() << ") {";

  std::vector<std::pair<cppunit::Function, cppunit::Result*>>* records = report.getRecords();
  for (auto it = records->begin(); it != records->end(); ++it) {
    stream << "\n\t" << it->first << " :: " << it->second;
    if (it->second->isOk()) {
      score += 1;
    }
  }

  stream << "\n}\ntotal score = " << (score / records->size()) * 100 << "%";
  return stream;
}
