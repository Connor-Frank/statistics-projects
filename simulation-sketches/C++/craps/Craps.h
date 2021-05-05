//
// Created by Connor Frank on 20.12.2020.
//

#ifndef CRAPS_CRAPS_H
#define CRAPS_CRAPS_H

#include <fstream>
#include <string>

class Craps {
private:
  std::string currentDirectory, buildType, outputDirectory, outputFile;
  int die1, die2, dice, firstDice;
  bool first;

public:
  std::ofstream fout;
  int game();
  Craps();
  virtual ~Craps();
};

#endif // CRAPS_CRAPS_H
