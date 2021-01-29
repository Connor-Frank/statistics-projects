//
// Created by Connor Frank on 20.12.2020.
//

#include "Craps.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
namespace fs = std::__fs::filesystem;

int randomInt(double min, double max);

int Craps::game() {
  first = true;
  while (true) {
    die1 = randomInt(1, 6); // value for die is random number 1-6
    die2 = randomInt(1, 6);
    dice = die1 + die2; // sum of dice

    if (first) {
      if (dice == 7 || dice == 11)
        return 1; // on first roll, 7 or 11 are a win
      if (dice == 2 || dice == 3 || dice == 12)
        return 0;       // 2, 3, or 12 lose
      firstDice = dice; // store value of first roll
      first = false;
    } else {
      if (dice == 7)
        return 0; // after first roll, 7 is loss
      if (dice == firstDice)
        return 1; // rolling same as first roll is win
    }
  }
}

Craps::Craps() {
  currentDirectory = fs::current_path(); // get directory for binary
  buildType = currentDirectory.substr(currentDirectory.find_last_of("\\/"));
  if (buildType == "/cmake-build-files")
    outputDirectory =
        currentDirectory.substr(0, currentDirectory.find_last_of("\\/"));
  else
    outputDirectory = currentDirectory;
  outputFile = outputDirectory + "/output.txt"; // path to output file
  std::cout << "output file: " << outputFile << '\n';
  remove(outputFile.c_str()); // delete file if it exists (to start again)
  fout.open(outputFile, std::ofstream::out | std::ofstream::app); // open file
  fout << "craps simulation - connor frank" << '\n';
  die1 = die2 = dice = firstDice = 0; // initialize variables
  first = true;                       // set this so the first roll works
}

Craps::~Craps() {
  fout.close(); // close the file output at end of program
}

int randomInt(double min, double max) {
  static std::random_device random{}; // seeds mt
  static std::mt19937 mt(random());   // seeds distInt
  static std::uniform_int_distribution<int> distInt{
      (int)min, (int)max}; // integer distribution
  return distInt(mt);      // generates a random number
}
