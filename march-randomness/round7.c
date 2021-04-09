/*
 * THE EXPERIMENT
 *
 * Roll a 10-sided die five times.
 * Will you get the same number at least twice in a row?
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seed_rand(void);
int int_rand(int min, int max);

int main(void) {
  seed_rand();

  long times_same = 0;
  long trials = (long)1e+8; // takes about 5 seconds to run

  clock_t start = clock();

  int die, last_die = 0;

  for (long i = 0; i < trials; i++) {
    for (int j = 0; j < 5; j++) {
      die = int_rand(1, 10);
      if (die == last_die) {
        times_same++;
        last_die = 0;
        break;
      } else {
        last_die = die;
      }
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("%ld trials were simulated.\n", trials);
  printf("the same number was rolled twice %ld times.\n", times_same);
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
