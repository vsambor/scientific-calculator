#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "Token.h"
#include <iostream>

using namespace std;

// space, tab, vertical tab, newline, carriage return, form feed
const string DEFAULT_DELIMITERS = " \t\v\n\r\f";
const string DIGITS = "0123456789";
const string OPERATORS = "+-*/^#";


class Tokenizer {
private:
  string inputBuffer;
  string delimiters;
  Token *tokens;
  
  bool isDelimiter(char c);
  bool isDigit(char c);
  bool isNumber(string s);
  bool isOperator(char c);
  void createToken(string chunk);
  
public:
  Tokenizer();
  Tokenizer(string input);
  Tokenizer(string input, string delimiters);
  Tokenizer(const Tokenizer &t);
  Tokenizer& operator=(Tokenizer& t);
  ~Tokenizer();
  
  void setInputBuffer(string input);
  string getInputBuffer();
  void setDelimiters(string delimiters);
  string getDelimiters();
  void createTokens();
  void setTokens(Token *tokens);
  Token* getTokens();
  
  static int tokensCount;
  static void printTokens(Token *tokens, int tokensCount);
};

#endif
