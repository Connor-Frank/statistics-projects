/*
 * ROUND 1
 *
 * THE EXPERIMENT
 * Roll a 20-sided die and a 30-sided die.
 * Will the sum of the results be at least 20?
 */

#include "utils.h"
#include <time.h>

int main(void) {
  seed_rand();

  long times = 0;
  const long trials = (long)1e+8; // 1e+8 takes about 1.1 seconds

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    // one die has 20 sides and the other has 30
    if (int_rand(1, 20) + int_rand(1, 30) >= 20) {
      times++;
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  results("the sum was >= 20", times, trials, duration);

  return 0;
}
