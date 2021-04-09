/*
 * THE EXPERIMENT
 *
 * Flip a coin six times.
 * Will the results be 4-2 for one side of the coin?
 *
 * For example, four heads and two tails in any order would be a "yes,"
 * or four tails and two heads in any order would be a "yes,"
 * any other combination would be a "no."
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seed_rand(void);
int int_rand(int min, int max);
int *int_rand_arr(int min, int max, int size);

int main(void) {
  seed_rand();

  long times_where_four = 0;
  long trials = (long)1e+7; // takes about 2.5 seconds

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    int *flips = int_rand_arr(0, 1, 6);
    if (flips) {
      int times_heads = 0;
      int times_tails = 0;
      for (int j = 0; j < 6; j++) {
        if (flips[j] == 0) {
          times_heads++;
        } else if (flips[j] == 1) {
          times_tails++;
        }
      }
      if (times_heads >= 4 || times_tails >= 4)
        times_where_four++;
      free(flips);
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("%ld trials were simulated.\n", trials);
  printf("4x of the same side for %ld times.\n", times_where_four);
  printf("that's equal to %Lf%% of the time\n",
         (long double)times_where_four / trials * 100.0);
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

int *int_rand_arr(int min, int max, int size) {
  if (size <= 0)
    return NULL;
  int *arr = malloc(size * sizeof(int));
  for (int i = 0; i < size; ++i)
    arr[i] = int_rand(min, max);
  return arr;
}
