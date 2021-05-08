/*
 * THE EXPERIMENT
 *
 * Flip a coin six times.
 * Will the results be 4-2 for one side of the coin?
 *
 * For example, four heads and two tails in any order would be a "yes,"
 * or four tails and two heads in any order would be a "yes,"
 * any other combination would be a "no."
 */

#include "utils.h"
#include <stdlib.h>
#include <time.h>

int main(void) {
  seed_rand();

  long times_where_four = 0;
  const long trials = (long)1e+7; // takes about 2.5 seconds

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    int *flips = int_rand_arr(0, 1, 6);
    if (flips) {
      int times_heads = 0;
      int times_tails = 0;
      for (int j = 0; j < 6; j++) {
        switch (flips[j]) {
        case 0:
          times_heads++;
          break;
        case 1:
          times_tails++;
          break;
        default:
          break;
        }
      }
      if (times_heads >= 4 || times_tails >= 4) {
        times_where_four++;
      }
      free(flips);
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  results("4x of the same side for", times_where_four, trials, duration);

  return 0;
}
