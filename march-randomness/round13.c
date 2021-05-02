/*
 * THE EXPERIMENT
 *
 * Roll four 6-sided die.
 * Will there be a combination of at least two dice
 * that forms exactly sum 8?
 */

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_sums(int *arr, int target, int current, int i, int len);

int main(void) {
  seed_rand();

  long times_eight = 0;
  const long trials = (long)1e+7; // takes about 1.2 seconds

  clock_t start = clock();

  const int num_dice = 4;

  for (long i = 0; i < trials; i++) {
    int *dice_rolls = int_rand_arr(1, 6, num_dice);
    if (dice_rolls) {
      if (find_sums(dice_rolls, 8, 0, 0, num_dice)) {
        times_eight++;
      }
      free(dice_rolls);
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  results("there was a sum of exactly eight", times_eight, trials, duration);

  return 0;
}

int find_sums(int *arr, int target, int current, int i, int len) {
  if (i == len) {
    if (target == current) {
      return 1;
    } else {
      return 0;
    }
  }
  return find_sums(arr, target, current + arr[i], i + 1, len) +
         find_sums(arr, target, current - arr[i], i + 1, len);
}
