//
// Created by Connor Frank on 20.12.2020.
//

#include "Craps.h"
#include <iostream>

int main() {
  Craps craps{};
  int wins = 0, games, recommendedGames = 100000000;
  std::cout << "input number of games (enter 0 for recommended max of "
            << recommendedGames << "): ";
  std::cin >> games;
  if (games == 0)
    games = recommendedGames;
  for (int i = 1; i <= games; ++i)
    wins += craps.game();
  std::cout << "\n" << wins << " wins out of " << games << " games" << '\n';
  craps.fout << "\n" << wins << " wins out of " << games << " games" << '\n';
  std::cout << "% of games won: " << (double)wins / games * 100 << '\n';
  craps.fout << "% of games won: " << (double)wins / games * 100 << '\n';

  return 0;
}
