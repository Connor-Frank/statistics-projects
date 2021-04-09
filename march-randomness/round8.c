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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seed_rand(void);
int int_rand(int min, int max);
int *int_rand_norep(int min, int max, int size);
int value_in_array(int val, const int *arr, int array_size);

int main(void) {
  seed_rand();

  long times_both_red = 0;
  long trials = (long)1e+7; // takes about 4 seconds to run

  int reds[6] = {0, 1, 2, 3, 4, 5};
  int blues[6] = {6, 7, 8, 9, 10, 11};

  clock_t start = clock();

  for (long i = 0; i < trials; i++) {
    int *pouch_1 = int_rand_norep(3, 6, 2);
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
    int *pouch_2 = int_rand_norep(6 - red_2, 9 + blue_2, 2);
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
    int *pouch_3 = int_rand_norep(2 - red_3, 5 + blue_3, 2);
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

  printf("%ld trials were simulated.\n", trials);
  printf("both pouch 3 balls were red %ld times.\n", times_both_red);
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
  srand((unsigned int)rand_seed);
}

int int_rand(int min, int max) {
  if (min >= max)
    printf("you messed up.\n");
  return (rand() % (max - min + 1)) + min;
}

int *int_rand_norep(int min, int max, int size) {
  if (size <= 0)
    return NULL;
  int *seen_arr = NULL;
  seen_arr = calloc((size_t)(max + 1), sizeof(*seen_arr));
  int *draws = malloc(size * sizeof(int));

  int drawn_ball;
  for (int i = 0; i < size; ++i) {
    drawn_ball = int_rand(min, max);
    if (!seen_arr[drawn_ball]) {
      draws[i] = drawn_ball;
    } else {
      i--;
    }
    seen_arr[drawn_ball]++;
  }

  free(seen_arr);
  return draws;
}

int value_in_array(int val, const int *arr, int array_size) {
  for (int i = 0; i < array_size; i++)
    if (arr[i] == val)
      return 1;
  return 0;
}
