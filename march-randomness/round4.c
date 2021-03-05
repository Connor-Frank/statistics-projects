/*
 * THE EXPERIMENT
 *
 * Roll a 6-sided die six times.
 * Will you roll a 2 at least one time?
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seed_rand(void);
int int_rand(int min, int max);

int main(void) {
  seed_rand();

  long times_has_two = 0;
  long trials = 1e+8; // takes about 2.6 seconds
  int num_rolls = 6;

  clock_t start = clock();

  int roll;

  for (long i = 0; i < trials; i++) {
    for (int j = 0; j < num_rolls - 1; j++) {
      roll = int_rand(1, 6);
      if (roll == 2) {
        times_has_two++;
        break;
      }
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("%ld trials were simulated.\n", trials);
  printf("a 2 was rolled at least once %ld times.\n", times_has_two);
  printf("that's equal to %Lf%% of the time\n",
         (long double)times_has_two / trials * 100.0);
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
  srand(rand_seed);
}

int int_rand(int min, int max) {
  if (min >= max)
    printf("you messed up.\n");
  return (rand() % (max - min + 1)) + min;
}