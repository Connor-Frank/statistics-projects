/*
 * ROUND 2
 *
 * THE EXPERIMENT
 * Flip a coin four times. Will you get heads exactly one time?
 */

#include "utils.h"
#include <stdio.h>
#include <time.h>

int main(void) {
  seed_rand();

  long times_exactly_one = 0;
  long trials = (long)1e+8; // takes about 2.3 seconds
  int coin1, coin2, coin3, coin4, coin_sum;

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    /* 0 is tails, 1 is heads */
    coin1 = int_rand(0, 1);
    coin2 = int_rand(0, 1);
    coin3 = int_rand(0, 1);
    coin4 = int_rand(0, 1);
    coin_sum = coin1 + coin2 + coin3 + coin4;
    if (coin_sum == 1)
      times_exactly_one++;
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  results("1 coin landed on heads", times_exactly_one, trials, duration);

  return 0;
}
