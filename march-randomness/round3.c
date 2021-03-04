/*
 * ROUND 3
 *
 * THE EXPERIMENT
 * A pouch has two blue balls and two red balls.
 * Shuffle and take out two balls at random.
 * Will both of them be red?
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seed_rand(void);
int int_rand(int min, int max);
int *int_rand_norep(int min, int max, int size);

int main(void) {
  seed_rand();

  long times_both_red = 0;
  long trials = 1e+7;

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    int *draws = int_rand_norep(1, 4, 4);
    if (draws) {
      if (draws[0] + draws[1] == 3) // 1 and 2 are red, 3 and 4 are blue
        times_both_red++;
      free(draws);
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("%ld trials were simulated.\n", trials);
  printf("the first two balls were red %ld times.\n", times_both_red);
  printf("that's equal to %Lf%% of the time\n",
         (long double)times_both_red / trials * 100.0);
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

int *int_rand_norep(int min, int max, int size) {
  if (size <= 0)
    return NULL;
  int *arr = malloc(size * 10);
  arr[0] = 0;
  int *draws = malloc(size);

  int ball;
  for (int i = 0; i < 4; ++i) {
    ball = int_rand(min, max);
    if (!arr[ball]) {
      draws[i] = ball;
    } else {
      i--;
    }
    arr[ball] = 1;
  }

  return draws;
}
