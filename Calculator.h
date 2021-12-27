#ifndef CALCULATOR_H
#define CALCULATOR_H

#include<iostream>

using namespace std;


class Calculator {
public:
  Calculator();
  
  static double add(double a, double b);
  static double substract(double a, double b);
  static double multiply(double a, double b);
  static double divide(double a, double b);
  static double power(double a, double b);
  static double root(double a, double b);
};
    
#endif
