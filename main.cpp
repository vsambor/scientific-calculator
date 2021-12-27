// FUTURE IMPROVEMENTS:
// 1. For now the program requires to add space delimiters.
//    In future it can be done to identify tokens from context. (in tokenizer)
// 2. Make the destruction working correctly and allow insertion of multiple expressions in one run.
//    (for now it works only once)
// 3. Implement tokens operators to perform math operations directly with them.
// 4. Allow the use of [ ] and eventually { }
// 5. Do some more testing with different examples (maybe create unit testing)


#include <string>
#include <iostream>
#include "Tokenizer.h"
#include "Parser.h"
#include "CalculatorException.h"

using namespace std;


int main() {
  cout << "### SCIENTIFIC CALCULATOR ###" << endl;
  cout << "Author: Paula Petcu" << endl << endl;

  string input;

  while (true) {
    cout << "\n\nPlease enter a math expression or type 'exit' to stop the program: " << endl;
    
    getline(cin, input);

    if (input.compare("exit") == 0) {
      cout << "\nThank you for using our calculator!" << endl;
      break;
    }
    
    try {
      Tokenizer tokenizer(input);
      Token *tokens = tokenizer.getTokens();
      
//      Tokenizer::printTokens(tokens, Tokenizer::tokensCount);
      
      Parser parser(tokens);
      double result = parser.getResult();
      
      cout << "\nResult: " << result << endl;
    } catch(CalculatorException& e) {
       cout <<e.getMessage() << endl;
    }
  }

  return 0;
}
