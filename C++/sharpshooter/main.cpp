//
// sharpshooter project by Connor Frank
//

#include <cmath>
#include <iostream>
#include <random>

bool consecutiveShots();
template <typename T, size_t n> double sumArray(T const (&arr)[n]);
int randomInt(double min, double max);

int main() {
  // 200 trials of whether the shooter makes 16 shots in a row
  int arr[200];
  for (int i = 1; i <= 200; i++) {
    if (consecutiveShots())
      arr[i - 1] = 1;
    else
      arr[i - 1] = 0;
  }
  // use sum function to find how many times the shooter made 16 shots (add one
  // for each time)
  double timesmade = sumArray(arr);
  double average = timesmade / 200;
  std::cout << "the shooter made 16 shots in a row " << timesmade << " times."
            << '\n';
  std::cout << "the shooter made 16 shots in a row " << average * 100
            << "% of the time for 200 trials." << '\n';

  return 0;
}

bool consecutiveShots() {
  int shot;
  int count = 0;
  do {
    // adds one for each shot made
    count++;
    // generates a random number between 1 and 100 (inclusive)
    shot = randomInt(1, 100);
  }
  // shooter's likelihood of making a shot is 82%
  while (shot <= 82);
  // subtract one from count due to nature of loop (could also start at -1, but
  // this makes more sense)
  count--;
  // returns whether the shooter made at least 16 shots
  return (count >= 16);
}

template <typename T, size_t n> double sumArray(T const (&arr)[n]) {
  int sum = 0;
  for (size_t i = 0; i < n; i++)
    sum += arr[i];
  return sum;
}

int randomInt(double min, double max) {
  static std::random_device random{};
  static std::mt19937 mt(random());
  static std::uniform_int_distribution<int> distInt{(int)floor(min),
                                                    (int)ceil(max)};
  return distInt(mt);
}
