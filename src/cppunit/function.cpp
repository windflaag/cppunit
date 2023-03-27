#include <cppunit/function.hpp>

cppunit::Function::Function() {
  this->function = nullptr;
  this->name = "";
}

cppunit::Function::Function(const cppunit::Function&& other) {
  this->operator=(other);
}

cppunit::Function::Function(const cppunit::Function& other) {
  this->operator=(other);
  //this->name = other.name;
  //this->function = other.function;
}

cppunit::Function::Function(function_t function, std::string name) {
  this->function = function;
  this->name = name;
}

cppunit::Function::~Function() {
  // TODO
}

void cppunit::Function::operator=(const Function& function) {
  this->function = function.function;
  this->name = function.name;
}

void cppunit::Function::operator=(const Function&& function) {
  this->function = function.function;
  this->name = function.name;
}


cppunit::function_t cppunit::Function::getFunction() {
  return this->function;
}

std::string cppunit::Function::getName() {
  return this->name;
}

std::ostream& operator<<=(std::ostream& stream, cppunit::Function& function) {
  stream << "(function '" << function.getName() << ")";
  return stream;
}

std::ostream& operator<<(std::ostream& stream, cppunit::Function& function) {
  stream << "\u001b[34m" << function.getName() << "\u001b[0m";
  return stream;
}
