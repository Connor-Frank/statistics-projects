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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seed_rand(void);
int int_rand(int min, int max);

int main(void) {
  seed_rand();

  /*
   * 1-3 are red, 1 has A and 2/3 have B on the back
   *
   * 4-6 are green, 4/5 have A and 6 has B on the back
   */

  long times_same = 0;
  long trials = (long)1e+8; // takes about 2 seconds to run

  clock_t start = clock();

  int red, green;

  for (long i = 0; i < trials; i++) {
    red = int_rand(1, 3);
    green = int_rand(4, 6);
    if (red == 1 && (green == 4 || green == 5)) {
      times_same++;
    } else if (green == 6 && (red == 2 || red == 3)) {
      times_same++;
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("%ld trials were simulated.\n", trials);
  printf("the same letters were drawn %ld times.\n", times_same);
  printf("that's equal to %Lf%% of the time\n",
         (long double)times_same / trials * 100.0);
  printf("time to run: %f seconds\n", duration);

  return 0;
}

void seed_rand(void) {
  FILE *fp;
  fp = fopen("/dev/random", "r");
  unsigned long long rand_seed;
  fread(&rand_seed, sizeof(rand_seed), sizeof(char), fp);
  fclose(fp);
  printf("random seed: %llu\n", rand_seed);
  srand((unsigned int)rand_seed);
}

int int_rand(int min, int max) {
  if (min >= max)
    printf("you messed up.\n");
  return (rand() % (max - min + 1)) + min;
}
