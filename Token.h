#ifndef TOKEN_H
#define TOKEN_H

#include<iostream>

using namespace std;


enum TokenType {
  NUMBER,
  OPERATOR,
  PARENTHESIS_L,
  PARENTHESIS_R
};


class Token {
private:
  TokenType type;
  string data;
  
  string getTokenTypeName(TokenType type);
public:
  Token();
  Token(TokenType type, string data );
  friend ostream& operator<<(ostream& out, Token& t);
  void setTokenType(TokenType type);
  TokenType getTokenType();
  void setData(string data);
  string getData();
};
    
#endif
