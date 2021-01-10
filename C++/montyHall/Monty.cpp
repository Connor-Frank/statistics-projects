//
// Created by Connor Frank on 04.12.2020.
//

#include "Monty.h"
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
namespace fs = std::__fs::filesystem;

int randomInt(double min, double max) {
  static std::random_device random;
  static std::mt19937 mt(random());
  static std::uniform_int_distribution<int> distInt{(int)floor(min),
                                                    (int)ceil(max)};
  return distInt(mt);
}

int Monty::noChange() const {
  int wins = 0;
  for (int i = 1; i <= trials; i++) {
    int prize = randomInt(0, 2);
    int choice = randomInt(0, 2);

    if (choice == prize)
      wins++;
  }
  return wins;
}

int Monty::yesChange() const {
  int wins = 0;
  for (int i = 1; i <= trials; i++) {
    int prize = randomInt(0, 2);
    int choice = randomInt(0, 2);

    int wrong = prize;
    while (wrong == prize || wrong == choice)
      wrong = randomInt(0, 2);

    int other = 3 - (choice + wrong);

    if (other == prize)
      wins++;
  }
  return wins;
}

void Monty::comparison(int inputTrials) {
  int wins;
  trials = inputTrials;
  std::cout << "door unchanged:" << '\n';
  fout << "door unchanged:" << '\n';
  wins = noChange();
  std::cout << "total wins out of " << trials << ": " << wins << '\n';
  fout << "total wins out of " << trials << ": " << wins << '\n';
  std::cout << "percent win: " << (double)wins / trials * 100 << "%" << '\n';
  fout << "percent win: " << (double)wins / trials * 100 << "%" << '\n';

  std::cout << "door changed:" << '\n';
  fout << "door changed:" << '\n';
  wins = yesChange();
  std::cout << "total wins out of " << trials << ": " << wins << '\n';
  fout << "total wins out of " << trials << ": " << wins << '\n';
  std::cout << "percent win: " << (double)wins / trials * 100 << "%" << '\n';
  fout << "percent win: " << (double)wins / trials * 100 << "%" << '\n';
}

Monty::Monty() {
  currentDirectory = fs::current_path();
  buildType = currentDirectory.substr(currentDirectory.find_last_of("\\/"));
  if (buildType == "/cmake-build-files")
    outputDirectory =
        currentDirectory.substr(0, currentDirectory.find_last_of("\\/"));
  else
    outputDirectory = currentDirectory;
  outputFile = outputDirectory + "/output.txt";
  std::cout << "output file: " << outputFile << '\n';
  remove(outputFile.c_str());
  fout.open(outputFile, std::ofstream::out | std::ofstream::app);
  fout << "monty hall simulation - connor frank\n";
  trials = 0;
}

Monty::~Monty() { fout.close(); }
