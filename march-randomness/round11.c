/*
 * THE EXPERIMENT
 *
 * Roll a 10-sided die, then roll a 20-sided die,
 * then roll a 30-sided die, keeping track of each result in order.
 *
 * Will the results be in strictly increasing order?
 */

#include "utils.h"
#include <stdio.h>
#include <time.h>

int main(void) {
  seed_rand();

  long times_increasing = 0;
  long trials = (long)1e+8; // takes about 2 seconds

  clock_t start = clock();

  int ten_sided, twenty_sided, thirty_sided;

  for (long i = 0; i < trials; i++) {
    ten_sided = int_rand(1, 10);
    twenty_sided = int_rand(1, 20);
    thirty_sided = int_rand(1, 30);
    if (consecutive(ten_sided, twenty_sided, thirty_sided)) {
      times_increasing++;
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  results("the results were in strictly increasing order", times_increasing,
          trials, duration);

  return 0;
}
