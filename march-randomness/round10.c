/*
 * THE EXPERIMENT
 *
 * Pouch A has two blue balls and one red ball.
 * Pouch B has three blue balls.
 * Pouch C has three red balls.
 *
 * Without looking, take two balls from Pouch A and put them in Pouch B.
 * Shuffle Pouch B and without looking,
 * take two balls from Pouch B and put them into Pouch C.
 * Finally, shuffle Pouch C and without looking take one ball from Pouch C.
 * Will it be red?
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seed_rand(void);
int int_rand(int min, int max);
int *int_rand_no_rep(int min, int max, int size);

int main(void) {
  seed_rand();

  long times_red = 0;
  long trials = (long)1e+7; // takes about 1.75 seconds

  clock_t start = clock();

  /*
   * KEY:
   * blue = 0
   * red = 1
   */

  for (long i = 0; i < trials; i++) {
    int pouch_a[3] = {0, 0, 1};
    int pouch_b[5] = {0, 0, 0};
    int pouch_c[5] = {1, 1, 1};
    int *pouch_a_draws = int_rand_no_rep(0, 2, 2);
    pouch_b[3] = pouch_a[pouch_a_draws[0]];
    pouch_b[4] = pouch_a[pouch_a_draws[1]];
    free(pouch_a_draws);
    int *pouch_b_draws = int_rand_no_rep(0, 4, 2);
    pouch_c[3] = pouch_b[pouch_b_draws[0]];
    pouch_c[4] = pouch_b[pouch_b_draws[1]];
    free(pouch_b_draws);
    if (pouch_c[int_rand(0, 4)] == 1) {
      times_red++;
    }
  }

  clock_t end = clock();
  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("%ld trials were simulated.\n", trials);
  printf("the final drawn ball was red %ld times.\n", times_red);
  printf("that's equal to %Lf%% of the time\n",
         (long double)times_red / trials * 100.0);
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

int *int_rand_no_rep(int min, int max, int size) {
  if (size <= 0)
    return NULL;
  int *seen_arr = calloc((size_t)(max + 1), sizeof(int));
  int *draws = malloc(size * sizeof(int));

  int drawn_ball;
  for (int i = 0; i < size; ++i) {
    drawn_ball = int_rand(min, max);
    if (!seen_arr[drawn_ball]) {
      draws[i] = drawn_ball;
    } else {
      i--;
    }
    seen_arr[drawn_ball] = 1;
  }

  free(seen_arr);
  return draws;
}
