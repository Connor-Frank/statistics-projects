/*
 * THE EXPERIMENT
 *
 * A pouch has one green ball and nine red balls.
 * Shuffle and take out three balls at random.
 * Will all be red?
 */

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  seed_rand();

  long times_all_red = 0;
  long trials = (long)1e+8;
  int num_draws = 3;

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    int *balls = malloc(num_draws * sizeof(int));
    for (int j = 0; j < num_draws; j++)
      balls[j] = int_rand(1, 10);
    if (!value_in_array(1, balls, num_draws))
      times_all_red++;
    free(balls);
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("%ld trials were simulated.\n", trials);
  printf("all three balls were red %ld times.\n", times_all_red);
  printf("that's equal to %Lf%% of the time\n",
         (long double)times_all_red / trials * 100.0);
  printf("time to run: %f seconds\n", duration);

  return 0;
}
