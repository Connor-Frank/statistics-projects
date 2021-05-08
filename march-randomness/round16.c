/*
 * THE EXPERIMENT
 *
 * A pouch has six blue balls and one red ball.
 * Shuffle and take out four balls at random.
 * Will the red ball be taken out?
 */

#include "utils.h"
#include <stdlib.h>
#include <time.h>

int main(void) {
  seed_rand();

  long red_picked = 0;
  const long trials = (long)1e7; // takes under 1.5 seconds

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    int *balls = int_rand_no_rep(1, 7, 4);
    if (balls) {
      for (int j = 0; j < 4; j++) {
        if (balls[j] == 7) {
          red_picked++;
          break;
        }
      }
      free(balls);
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  results("a red ball was picked", red_picked, trials, duration);

  return 0;
}
