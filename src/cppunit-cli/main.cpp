#include <cppunit/function.hpp>
#include <cppunit/scanner.hpp>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <fstream>

void exitWithError(const char* errorMessage) {
  std::cerr << "\u001b[31merror\u001b[0m: " << errorMessage << std::endl;
  exit(1);
}

void addArgumentFilesToScanner(cppunit::Scanner* scanner, int argc, char** args) {
  for (int i = 1; i < argc; i++) {
    scanner->exploreFile(args[i]);
  }
}

void writeScannerOutputToFile(cppunit::Scanner* scanner) {
  std::ofstream output; output.open("main.cpp");
  output << *scanner << std::endl;
  output.close();
}

int main(int argc, char** args) {
  if (argc < 2) {
    exitWithError("should specify at least a file");
  } else {
    cppunit::Scanner* scanner = new cppunit::Scanner();
    try {
      addArgumentFilesToScanner(scanner, argc, args);
      writeScannerOutputToFile(scanner);
    } catch(std::runtime_error* err) {
      exitWithError(err->what());
    }
    delete scanner;
  }
}
