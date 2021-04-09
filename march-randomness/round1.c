/*
 * ROUND 1
 *
 * THE EXPERIMENT
 * Roll a 20-sided die and a 30-sided die.
 * Will the sum of the results be at least 20?
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float float_rand(float min, float max);

int main(void) {
  FILE *fp;
  fp = fopen("/dev/random", "r");
  unsigned long long rand_seed;
  fread(&rand_seed, sizeof(rand_seed), sizeof(char), fp);
  fclose(fp);
  printf("random seed: %llu\n", rand_seed);
  srand((unsigned int)rand_seed);

  long times = 0;
  long trials = (long)1e+8; // 1e+8 takes about 1.1 seconds, 1e+9 takes about 11
  int die1, die2, sum;

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    die1 = (int)float_rand(1, 20); // one die has 20 sides
    die2 = (int)float_rand(1, 30); // the other has 30
    sum = die1 + die2;        // find sum
    if (sum >= 20) {
      times++;
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("sum was >= 20 %ld times out of %ld trials\n", times, trials);
  printf("that's equal to %Lf%% of the time\n",
         (long double)times / trials * 100.0);
  printf("time to run: %f seconds\n", duration);

  return 0;
}

float float_rand(float min, float max) {
  float scale = rand() / (float)RAND_MAX;
  return min + scale * (max - min);
}
