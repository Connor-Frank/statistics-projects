/*
 * THE EXPERIMENT
 *
 * Two red cards have an A on the back,
 * and two red cards have a B on the back.
 * Two green cards have an A on the back,
 * and one green card has a B on the back.
 *
 * Shuffle the cards and select one red and one green at random.
 * Will both cards have an A on the back?
 */

#include "utils.h"
#include <time.h>

#define A 1
#define B 2

int main(void) {
  seed_rand();

  long both_A = 0;
  const long trials = (long)1e8;

  clock_t start = clock();

  const int red_cards[] = {A, A, B, B};
  const int green_cards[] = {A, A, B};
  int red_draw, green_draw;

  for (long i = 0; i < trials; i++) {
    red_draw = red_cards[int_rand(0, 3)];
    green_draw = green_cards[int_rand(0, 2)];
    if (red_draw == A && green_draw == A) {
      both_A++;
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  results("both cards had an A on the back", both_A, trials, duration);

  return 0;
}
