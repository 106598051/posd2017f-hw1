#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "scanner.h"
#include "parser.h"
using namespace std;

string &specialInput(string &input);

int main(int argc, char **argv) {
  // stringstream input = "";
  string input = "";
  string inputLine = "";
  // string inputPart = "";
  // string command = "";
  // Scanner scanner;
  // Parser parser;
  do {

    // while (inputLine == "" ||  inputLine.back() != '.') {
    //   if (inputLine == "") {
    //     cout << "?- ";
    //   } else {
    //     cout << "|  ";
    //   }
    //   getline(cin, inputLine);
    //   input << inputLine;
    //   while (input >> inputPart) {
    //     command += part;
    //   }
    //   if (specialInput(command) == "halt.") {
    //     break;
    //   }
    //   else if (specialInput(command) == "") {
    //     continue;
    //   }
    //   else {
    //     Scanner scanner(input);
    //     Parser parser(scanner);
    //     try {
    //       parser.buildExpression();
    //       cout << parser.getExpressionResult() << endl;
    //     } catch (string &errorMessage) {
    //       cout << errorMessage << endl;
    //     }
    //   }
    //
    // }
    // command = "";
    // input = "";

    cout << "?- ";
    getline(cin, input);
    if (specialInput(input) == "halt.") {
      break;
    }
    else if (specialInput(input) == "") {
      continue;
    }
    else {
      Scanner scanner(input);
      Parser parser(scanner);
      try {
        parser.buildExpression();
        cout << parser.getExpressionResult() << endl;
      } catch (string &errorMessage) {
        cout << errorMessage << endl;
      }
    }
  } while(true);
}

string &specialInput(string &input) {
  string result = "";
  if (!input.empty()) {
    int index = 0;
    for (size_t i = 0; i < input.size(); i++) {
      if (input[i] != ' ') {
        index = i;
        result += input[i];
      }
    }
  }
  input = result;
  return input;
}
