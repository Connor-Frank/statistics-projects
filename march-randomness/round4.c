/*
 * THE EXPERIMENT
 *
 * Roll a 6-sided die six times.
 * Will you roll a 2 at least one time?
 */

#include "utils.h"
#include <time.h>

int main(void) {
  seed_rand();

  long times_has_two = 0;
  const long trials = (long)1e+8; // takes about 2.6 seconds
  const int num_rolls = 6;

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    for (int j = 0; j < num_rolls; j++) {
      if (int_rand(1, 6) == 2) {
        times_has_two++;
        break;
      }
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  results("a 2 was rolled at least once", times_has_two, trials, duration);

  return 0;
}
