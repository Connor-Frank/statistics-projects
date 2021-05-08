/*
 * THE EXPERIMENT
 *
 * A pouch has one green ball and nine red balls.
 * Shuffle and take out three balls at random.
 * Will all be red?
 */

#include "utils.h"
#include <stdlib.h>
#include <time.h>

int main(void) {
  seed_rand();

  long times_all_red = 0;
  const long trials = (long)1e+8;
  const int num_draws = 3;

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    int *balls = int_rand_arr(1, 10, num_draws);
    if (balls) {
      if (!value_in_array(1, balls, num_draws)) {
        times_all_red++;
      }
      free(balls);
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  results("all three balls were red", times_all_red, trials, duration);

  return 0;
}
