/*
 * ROUND 3
 *
 * THE EXPERIMENT
 * A pouch has two blue balls and two red balls.
 * Shuffle and take out two balls at random.
 * Will both of them be red?
 */

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *int_rand_no_rep(int min, int max, int size);

int main(void) {
  seed_rand();

  long times_both_red = 0;
  long trials = (long)1e+7; // takes about 1.4 seconds

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    int *draws = int_rand_no_rep(1, 4, 4);
    if (draws) {
      if (draws[0] + draws[1] == 3) // 1 and 2 are red, 3 and 4 are blue
        times_both_red++;
      free(draws);
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("%ld trials were simulated.\n", trials);
  printf("the first two balls were red %ld times.\n", times_both_red);
  printf("that's equal to %Lf%% of the time\n",
         (long double)times_both_red / trials * 100.0);
  printf("time to run: %f seconds\n", duration);

  return 0;
}

int *int_rand_no_rep(int min, int max, int size) {
  if (size <= 0)
    return NULL;
  int *seen_arr = calloc((size_t)(max + 1), sizeof(int));
  int *draws = malloc(size * sizeof(int));

  int drawn_ball;
  for (int i = 0; i < size; ++i) {
    drawn_ball = int_rand(min, max);
    if (!seen_arr[drawn_ball]) {
      draws[i] = drawn_ball;
    } else {
      i--;
    }
    seen_arr[drawn_ball] = 1;
  }

  free(seen_arr);
  return draws;
}
