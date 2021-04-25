/*
 * THE EXPERIMENT
 *
 * A pouch has three blue balls and nine red balls.
 * Shuffle and take out two balls at random.
 * Will both be red?
 */

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  seed_rand();

  long times_both_red = 0;
  long trials = (long)5e7;

  clock_t start = clock();

  /*
   * KEY:
   * blue = 0
   * red = 1
   */

  int pouch_size = 12;
  int *pouch = calloc((size_t)(pouch_size), sizeof(int));
  for (int i = 3; i < 12; i++)
    pouch[i] = 1;

  for (long i = 0; i < trials; i++) {
    int *ball_choices = int_rand_no_rep(0, pouch_size - 1, 2);
    int ball_draws[] = {1, pouch[ball_choices[0]], pouch[ball_choices[1]]};
    free(ball_choices);
    if (all_equal(ball_draws, sizeof(ball_draws) / sizeof(ball_draws[0]))) {
      times_both_red++;
    }
  }
  free(pouch);

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("%ld trials were simulated.\n", trials);
  printf("both balls were red %ld times.\n", times_both_red);
  printf("that's equal to %Lf%% of the time\n",
         (long double)times_both_red / trials * 100.0);
  printf("time to run: %f seconds\n", duration);

  return 0;
}
