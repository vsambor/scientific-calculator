#ifndef CALCULATOR_EXCEPTION_H
#define CALCULATOR_EXCEPTION_H

#include <iostream>

using namespace std;


enum CalculatorExceptionType {
  PARENTHESIS_R_MISSING,
  DIVISION_BY_ZERO,
  PRIMARY_EXPECTED
};

class CalculatorException {
private:
  string message;

public:
  CalculatorException(CalculatorExceptionType type);
  string getMessage();
};
  
#endif
