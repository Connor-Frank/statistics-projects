/*
 * ROUND 3
 *
 * THE EXPERIMENT
 * A pouch has two blue balls and two red balls.
 * Shuffle and take out two balls at random.
 * Will both of them be red?
 */

#include "utils.h"
#include <stdlib.h>
#include <time.h>

int main(void) {
  seed_rand();

  long times_both_red = 0;
  const long trials = (long)1e+7; // takes about 0.85 seconds

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    int *draws = int_rand_no_rep(1, 4, 2);
    if (draws) {
      // 1 and 2 are red, 3 and 4 are blue
      if (draws[0] + draws[1] == 3) {
        times_both_red++;
      }
      free(draws);
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  results("the first two balls were red", times_both_red, trials, duration);

  return 0;
}
