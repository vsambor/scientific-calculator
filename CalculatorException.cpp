#include "CalculatorException.h"

CalculatorException::CalculatorException(CalculatorExceptionType type) {
  switch (type) {
    case CalculatorExceptionType::DIVISION_BY_ZERO:
      this->message = "Error: Division by zero";
      break;
      
    case CalculatorExceptionType::PARENTHESIS_R_MISSING:
      this->message = "Error: Right parenthesis is missing. Expected ')'";
      break;
      
    case CalculatorExceptionType::PRIMARY_EXPECTED:
      this->message = "Error: Primary expected";
      break;
      
    default:
      this->message = "Error: Generic calculator error";
      break;
  }
}

string CalculatorException::getMessage() {
  return this->message;
}
