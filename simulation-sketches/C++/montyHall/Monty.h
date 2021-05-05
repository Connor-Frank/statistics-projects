//
// Created by Connor Frank on 04.12.2020.
//

#ifndef MONTYHALL_MONTY_H
#define MONTYHALL_MONTY_H

#include <fstream>
#include <string>

class Monty {
private:
  std::string currentDirectory, buildType, outputDirectory, outputFile;
  int trials;
  int noChange() const;
  int yesChange() const;

public:
  std::ofstream fout;
  void comparison(int inputTrials);
  Monty();
  virtual ~Monty();
};

#endif // MONTYHALL_MONTY_H
