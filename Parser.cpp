#include "./Parser.h"
#include "Tokenizer.h"
#include "CalculatorException.h"
#include "Calculator.h"


Parser::Parser() {}

Parser::Parser(Token *tokens) {
  this->tokens = tokens;
  this->result = expression();
}

Parser::Parser(const Parser &p) {
//  this->inputBuffer = t.inputBuffer;
//  this->delimiters = t.delimiters;
//
//  for (int i = 0; i < Tokenizer::tokensCount; i++) {
//    this->tokens[i] = t.tokens[i];
//  }
}

Parser& Parser::operator=(Parser& p) {
//  this->inputBuffer = t.inputBuffer;
//  this->delimiters = t.delimiters;
//
//  this->tokens = new Token[Tokenizer::tokensCount];
//
//  for (int i = 0; i < Tokenizer::tokensCount; i++) {
//    this->tokens[i] = t.tokens[i];
//  }
//
 return *this;
}

Parser::~Parser() {
//  cout << "Parser Destructor called!" << endl;
  if (this->tokens) {
    delete [] this->tokens;
    this->tokens = NULL;
  }
}

Token Parser::getNextToken() {
  Token currentToken = this->tokens[this->currentTokenIndex];
  this->currentTokenIndex++;
  return currentToken;
}

double Parser::getResult() {
  return this->result;
}

double Parser::expression() {
  double left = this->term();
  Token t = this->getNextToken();
  
  while(true) {
    if (t.getTokenType() == TokenType::OPERATOR) {
      if (t.getData().compare("+") == 0) {
        left = Calculator::add(left, this->term());
        break;
      }
      
      if (t.getData().compare("-") == 0) {
        left = Calculator::substract(left, this->term());
        break;
      }

      this->currentTokenIndex--;
      return left;
    }
    
    return left;
  }
  return left;
}

double Parser::term() {
  double left = primary();
  Token t = this->getNextToken();
  
  while (true) {
    if (t.getTokenType() == TokenType::OPERATOR) {
      if (t.getData().compare("*") == 0) {
        left = Calculator::multiply(left, this->primary());
        break;
      }
      
      if (t.getData().compare("/") == 0) {
        double p = primary();
        if (p == 0) {
          throw CalculatorException(CalculatorExceptionType::DIVISION_BY_ZERO);
          return -1;
        }
        
        left = Calculator::divide(left, p);
        break;
      }
    }
    
    this->currentTokenIndex--;
    return left;
  }
  
  return left;
}


double Parser::primary() {
  Token t = this->getNextToken();
  
  if (t.getTokenType() == TokenType::PARENTHESIS_L) {
    double d = expression();
    t = this->getNextToken();
    if (t.getTokenType() != TokenType::PARENTHESIS_R) {
      throw CalculatorException(CalculatorExceptionType::PARENTHESIS_R_MISSING);
    }
    return d;
  }
  
  if (t.getTokenType() == TokenType::NUMBER) {
    return stod(t.getData());
  }
  
  throw CalculatorException(CalculatorExceptionType::PRIMARY_EXPECTED);
  
  return -1;
}
