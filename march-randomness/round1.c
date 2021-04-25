/*
 * ROUND 1
 *
 * THE EXPERIMENT
 * Roll a 20-sided die and a 30-sided die.
 * Will the sum of the results be at least 20?
 */

#include "utils.h"
#include <stdio.h>
#include <time.h>

int main(void) {
  seed_rand();

  long times = 0;
  long trials = (long)1e+8; // 1e+8 takes about 1.1 seconds, 1e+9 takes about 11

  clock_t start = clock();

  int die1, die2, sum;

  for (long i = 0; i < trials; i++) {
    die1 = int_rand(1, 20); // one die has 20 sides
    die2 = int_rand(1, 30); // the other has 30
    sum = die1 + die2;      // find sum
    if (sum >= 20) {
      times++;
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("sum was >= 20 %ld times out of %ld trials\n", times, trials);
  printf("that's equal to %Lf%% of the time\n",
         (long double)times / trials * 100.0);
  printf("time to run: %f seconds\n", duration);

  return 0;
}
