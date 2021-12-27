#include "./Token.h"
#include <iostream>

using namespace std;


Token::Token(){}
Token::Token(TokenType type, string data) {
  this->type = type;
  this->data = data;
}

ostream& operator<<(ostream& out, Token& t) {
  string typeName = t.getTokenTypeName(t.type);
  out << "Token: [ data: " << t.data << ", type: " <<  typeName << "]";
  return out;
}

string Token::getTokenTypeName(TokenType type) {
  switch(type) {
    case TokenType::NUMBER:
      return "Number";
    case TokenType::OPERATOR:
      return "Operator";
    case TokenType::PARENTHESIS_L:
      return "Left Parenthesis";
    case TokenType::PARENTHESIS_R:
      return "Right Parenthesis";
  }
}

void Token::setTokenType(TokenType type) {
  //to do: add validator
  this->type = type;
}
TokenType Token::getTokenType() {
  return this->type;
}
void Token::setData(string data) {
  this->data = data;
}
string Token::getData() {
  return this->data;
}
