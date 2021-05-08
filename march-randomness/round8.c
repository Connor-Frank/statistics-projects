/*
 * THE EXPERIMENT
 *
 * Pouch A has one blue ball and three red balls.
 * Pouch B has four blue balls.
 * Pouch C has four red balls.
 * Without looking, take two balls from Pouch A and put them in Pouch B.
 * Shuffle Pouch B and without looking, take two balls from Pouch B
 * and put them in Pouch C.
 * Shuffle Pouch C and without looking, take two balls from Pouch C.
 * Will they both be red?
 */

#include "utils.h"
#include <stdlib.h>
#include <time.h>

int main(void) {
  seed_rand();

  long times_both_red = 0;
  const long trials = (long)1e+7; // takes about 4 seconds to run

  const int reds[6] = {0, 1, 2, 3, 4, 5};
  const int blues[6] = {6, 7, 8, 9, 10, 11};

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    int *pouch_1 = int_rand_no_rep(3, 6, 2);
    int red_2 = 0;
    int blue_2 = 0;
    if (pouch_1) {
      for (int j = 0; j < 6; j++) {
        if (value_in_array(reds[j], pouch_1, 2)) {
          red_2++;
        } else if (value_in_array(blues[j], pouch_1, 2)) {
          blue_2++;
        }
      }
      free(pouch_1);
    }
    int *pouch_2 = int_rand_no_rep(6 - red_2, 9 + blue_2, 2);
    int red_3 = 0;
    int blue_3 = 0;
    if (pouch_2) {
      for (int j = 0; j < 6; j++) {
        if (value_in_array(reds[j], pouch_2, 2)) {
          red_3++;
        } else if (value_in_array(blues[j], pouch_2, 2)) {
          blue_3++;
        }
      }
      free(pouch_2);
    }
    int *pouch_3 = int_rand_no_rep(2 - red_3, 5 + blue_3, 2);
    int pouch_3_reds = 0;
    if (pouch_3) {
      for (int j = 0; j < 6; j++) {
        if (value_in_array(reds[j], pouch_3, 2)) {
          pouch_3_reds++;
        }
      }
      free(pouch_3);
    }
    if (pouch_3_reds == 2) {
      times_both_red++;
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  results("both pouch 3 balls were red", times_both_red, trials, duration);

  return 0;
}
