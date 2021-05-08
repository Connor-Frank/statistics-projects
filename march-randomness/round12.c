/*
 * THE EXPERIMENT
 *
 * A pouch has three blue balls and nine red balls.
 * Shuffle and take out two balls at random.
 * Will both be red?
 */

#include "utils.h"
#include <stdlib.h>
#include <time.h>

int main(void) {
  seed_rand();

  long times_both_red = 0;
  const long trials = (long)5e7;

  clock_t start = clock();

  /*
   * KEY:
   * blue = 0
   * red = 1
   */

  const int pouch_size = 12;
  int *pouch = calloc((size_t)(pouch_size), sizeof(int));
  if (pouch) {
    for (int i = 3; i < 12; i++) {
      pouch[i] = 1;
    }
    for (long i = 0; i < trials; i++) {
      int *ball_choices = int_rand_no_rep(0, pouch_size - 1, 2);
      if (ball_choices) {
        int draws[] = {1, pouch[ball_choices[0]], pouch[ball_choices[1]]};
        if (all_equal(draws, sizeof(draws) / sizeof(draws[0]))) {
          times_both_red++;
        }
        free(ball_choices);
      }
    }
    free(pouch);
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  results("both balls were red", times_both_red, trials, duration);

  return 0;
}
