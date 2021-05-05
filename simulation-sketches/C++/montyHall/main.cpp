//
// Created by Connor Frank on 04.12.2020.
//

#include "Monty.h"
#include <iostream>

int main() {
  Monty monty;
  std::cout << "monty hall simulation" << '\n';
  std::cout << '\n';
  int input;
  int recommendedTrials = 100000000;
  std::cout << "manual or auto? enter 0 for auto, enter number of trials for "
               "manual: ";
  std::cin >> input;
  if (input > 0) {
    monty.fout << "manual mode selected." << '\n' << '\n';
    monty.fout << input << " trials:" << '\n';
    monty.comparison(input);
  } else if (input == 0) {
    monty.fout << "auto mode selected." << '\n' << '\n';
    std::cout << "enter max number of trials 0 for recommended max of "
              << recommendedTrials << "): ";
    std::cin >> input;
    if (input == 0)
      input = recommendedTrials;
    for (int i = 10; i <= input; i *= 10) {
      std::cout << i << " trials:" << '\n';
      monty.fout << i << " trials:" << '\n';
      monty.comparison(i);
      if (i != input) {
        std::cout << '\n';
        monty.fout << '\n';
      }
    }
  }
  return 0;
}
