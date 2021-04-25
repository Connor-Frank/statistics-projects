#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

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

int *int_rand_arr(int min, int max, int size) {
  if (size <= 0)
    return NULL;
  int *arr = malloc(size * sizeof(int));
  for (int i = 0; i < size; ++i)
    arr[i] = int_rand(min, max);
  return arr;
}

bool consecutive(int a, int b, int c) {
  switch (abs(c - a)) {
  case 2:
    return (2 * b == a + c);
  case 1:
    return consecutive(b, c, a);
  default:
    return false;
  }
}
