/*
 *  THE EXPERIMENT
 *
 *  Two red cards have an A on the back,
 *  and two red cards have a B on the back.
 *
 *  Two green cards have an A on the back,
 *  and one green card has a B on the back.
 *
 *  Shuffle the cards and select one red and one green at random.
 *  Will both cards have the same letter on the back?
 */

#include "utils.h"
#include <time.h>

int main(void) {
  seed_rand();

  /*
   * 1-3 are red, 1 has A and 2/3 have B on the back
   *
   * 4-6 are green, 4/5 have A and 6 has B on the back
   */

  long times_same = 0;
  const long trials = (long)1e+8; // takes about 2 seconds to run

  clock_t start = clock();

  int red, green;

  for (long i = 0; i < trials; i++) {
    red = int_rand(1, 3);
    green = int_rand(4, 6);
    if ((red == 1 && green <= 5) || (green == 6 && red >= 2)) {
      times_same++;
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  results("the same letters were drawn", times_same, trials, duration);

  return 0;
}
