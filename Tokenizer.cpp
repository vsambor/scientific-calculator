#include "Tokenizer.h"
#include <iostream>

using namespace std;


int Tokenizer::tokensCount = 0;

Tokenizer::Tokenizer() {}

Tokenizer::Tokenizer(string input) {
  this->inputBuffer = input;
  this->delimiters = DEFAULT_DELIMITERS;
  this->createTokens();
}

Tokenizer::Tokenizer(string input, string delimiters) {
  this->inputBuffer = input;
  this->delimiters = delimiters;
  this->createTokens();
}

Tokenizer::Tokenizer(const Tokenizer &t) {
  this->inputBuffer = t.inputBuffer;
  this->delimiters = t.delimiters;
  
  for (int i = 0; i < Tokenizer::tokensCount; i++) {
    this->tokens[i] = t.tokens[i];
  }
}

Tokenizer& Tokenizer::operator=(Tokenizer& t) {
  this->inputBuffer = t.inputBuffer;
  this->delimiters = t.delimiters;
  
  this->tokens = new Token[Tokenizer::tokensCount];
  
  for (int i = 0; i < Tokenizer::tokensCount; i++) {
    this->tokens[i] = t.tokens[i];
  }
  
  return *this;
}

Tokenizer::~Tokenizer() {
//  cout << "Tokenizer Destructor called!" << endl;
  if (this->tokens) {
//    delete [] this->tokens;
  }
}


void Tokenizer::createTokens() {
  this->tokens = new Token[this->inputBuffer.size()];
  string lastChunk;
  
  for (int i = 0; i < this->inputBuffer.size(); i++) {
    char c = this->inputBuffer[i];
    
    if (this->isDelimiter(c)) {
      this->createToken(lastChunk);
      lastChunk = "";
    }
    else {
      lastChunk.push_back(c);
    }
  }
  
  if (!lastChunk.empty()) {
    this->createToken(lastChunk);
  }
  
//  this->printTokens();
}

void Tokenizer::createToken(string chunk) {
  Token* token = new Token();
  token->setData(chunk);
  
  if (this->isNumber(chunk)) {
    token->setTokenType(TokenType::NUMBER);
  }
  else if (chunk.compare("(") == 0) {
    token->setTokenType(TokenType::PARENTHESIS_L);
  }
  else if (chunk.compare(")") == 0) {
    token->setTokenType(TokenType::PARENTHESIS_R);
  }
  else if (chunk.size() == 1 && this->isOperator(chunk[0])) {
    token->setTokenType(TokenType::OPERATOR);
  }
  
  this->tokens[Tokenizer::tokensCount] = *token;
  Tokenizer::tokensCount++;
}

void Tokenizer::printTokens(Token *tokens, int tokensCount) {
  cout << endl << "--- Print tokens ----" << endl;
  for (int i = 0; i < tokensCount; i++) {
    cout << tokens[i] << endl;
  }
}

bool Tokenizer::isDelimiter(char c) {
  for (int i = 0; i < this->delimiters.size(); ++i) {
    char delimiter = this->delimiters[i];
    if (c == delimiter) {
      return true;
    }
  }
  return false;
}

bool Tokenizer::isDigit(char c) {
  for (int i = 0; i < DIGITS.size(); ++i) {
    char digit = DIGITS[i];
    if (c == digit) {
      return true;
    }
  }
  return false;
}

bool Tokenizer::isNumber(string s) {
  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    if (this->isDigit(c)) {
      return true;
    }
  }
  return false;
}

bool Tokenizer::isOperator(char c) {
  for (int i = 0; i < OPERATORS.size(); ++i) {
    char op = OPERATORS[i];
    if (c == op) {
      return true;
    }
  }
  return false;
}

void Tokenizer:: setInputBuffer(string input) {
  this->inputBuffer = input;
}

string Tokenizer::getInputBuffer() {
  return this->inputBuffer;
}

void Tokenizer::setDelimiters(string delimiters) {
  this->delimiters = delimiters;
}

string Tokenizer::getDelimiters() {
  return this->delimiters;
}

void Tokenizer::setTokens(Token *tokens) {
  this->tokens = tokens;
}

Token* Tokenizer::getTokens() {
  return this->tokens;
}
