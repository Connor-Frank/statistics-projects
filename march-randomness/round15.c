/*
 * THE EXPERIMENT
 *
 * Roll a 20-sided die four times.
 * Will you roll a 19 or a 20 at least one time?
 */

#include "utils.h"
#include <stdio.h>
#include <time.h>

int main(void) {
  seed_rand();

  long top_two = 0;
  long trials = (long)1e8; // takes just under 5 seconds

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    for (int j = 0; j < 4; j++) {
      if (int_rand(1, 20) >= 19) {
        top_two++;
      }
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("%ld trials were simulated.\n", trials);
  printf("a 19 or 20 was rolled %ld times.\n", top_two);
  printf("that's equal to %Lf%% of the time\n",
         (long double)top_two / trials * 100.0);
  printf("time to run: %f seconds\n", duration);

  return 0;
}
