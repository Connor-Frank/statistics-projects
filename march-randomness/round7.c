/*
 * THE EXPERIMENT
 *
 * Roll a 10-sided die five times.
 * Will you get the same number at least twice in a row?
 */

#include "utils.h"
#include <stdio.h>
#include <time.h>

int main(void) {
  seed_rand();

  long times_same = 0;
  long trials = (long)1e+8; // takes about 5 seconds to run

  clock_t start = clock();

  int die, last_die = 0;

  for (long i = 0; i < trials; i++) {
    for (int j = 0; j < 5; j++) {
      die = int_rand(1, 10);
      if (die == last_die) {
        times_same++;
        last_die = 0;
        break;
      } else {
        last_die = die;
      }
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("%ld trials were simulated.\n", trials);
  printf("the same number was rolled twice %ld times.\n", times_same);
  printf("that's equal to %Lf%% of the time\n",
         (long double)times_same / trials * 100.0);
  printf("time to run: %f seconds\n", duration);

  return 0;
}
