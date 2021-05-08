/*
 * THE EXPERIMENT
 *
 * Pouch A has two blue balls and one red ball.
 * Pouch B has three blue balls.
 * Pouch C has three red balls.
 *
 * Without looking, take two balls from Pouch A and put them in Pouch B.
 * Shuffle Pouch B and without looking,
 * take two balls from Pouch B and put them into Pouch C.
 * Finally, shuffle Pouch C and without looking take one ball from Pouch C.
 * Will it be red?
 */

#include "utils.h"
#include <stdlib.h>
#include <time.h>

int main(void) {
  seed_rand();

  long times_red = 0;
  const long trials = (long)1e+7; // takes about 1.75 seconds

  clock_t start = clock();

  /*
   * KEY:
   * blue = 0
   * red = 1
   */

  int pouch_a[3] = {0, 0, 1};
  int pouch_b[5] = {0, 0, 0};
  int pouch_c[5] = {1, 1, 1};

  for (long i = 0; i < trials; i++) {
    int *pouch_a_draws = int_rand_no_rep(0, 2, 2);
    if (pouch_a_draws) {
      pouch_b[3] = pouch_a[pouch_a_draws[0]];
      pouch_b[4] = pouch_a[pouch_a_draws[1]];
      free(pouch_a_draws);
    }
    int *pouch_b_draws = int_rand_no_rep(0, 4, 2);
    if (pouch_b_draws) {
      pouch_c[3] = pouch_b[pouch_b_draws[0]];
      pouch_c[4] = pouch_b[pouch_b_draws[1]];
      free(pouch_b_draws);
    }
    if (pouch_c[int_rand(0, 4)] == 1) {
      times_red++;
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  results("the final drawn ball was red", times_red, trials, duration);

  return 0;
}
