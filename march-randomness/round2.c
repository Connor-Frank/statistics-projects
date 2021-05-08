/*
 * ROUND 2
 *
 * THE EXPERIMENT
 * Flip a coin four times. Will you get heads exactly one time?
 */

#include "utils.h"
#include <time.h>

int main(void) {
  seed_rand();

  long times_exactly_one = 0;
  const long trials = (long)1e+8; // takes about 2.3 seconds
  int coin_sum;

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    /*
     * 0 is tails
     * 1 is heads
     */
    coin_sum = 0;
    for (int j = 0; j < 4 && coin_sum < 2; j++) {
      coin_sum += int_rand(0, 1);
    }
    if (coin_sum == 1) {
      times_exactly_one++;
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  results("1 coin landed on heads", times_exactly_one, trials, duration);

  return 0;
}
