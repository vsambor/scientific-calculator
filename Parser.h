#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "Token.h"

using namespace std;

class Parser {
private:
  Token* tokens;
  Token getNextToken();
  int currentTokenIndex = 0;
  double result;
  
  // Inspired by - Programming Principles and Practice Using C++ : Bjarne Stroustrup - Chapter 6
  double expression();   // Exp = Exp or Exp + Term or Exp - term
  double term();         // Term = Term or Term * Primary or Term / Primary
  double primary();      // Primary = '(' or Number ; Number = double precision number;

public:
  Parser();
  Parser(Token *tokens);
  Parser(const Parser &p);
  Parser& operator=(Parser& p);
  ~Parser();
  double getResult();
};

#endif
