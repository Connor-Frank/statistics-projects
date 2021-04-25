#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void seed_rand(void) {
  FILE *fp;
  fp = fopen("/dev/random", "r");
  unsigned int rand_seed;
  fread(&rand_seed, sizeof(rand_seed), sizeof(char), fp);
  fclose(fp);
  printf("random seed: %u\n", rand_seed);
  srand(rand_seed);
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

  int drawn;
  for (int i = 0; i < size; ++i) {
    drawn = int_rand(min, max);
    if (!seen_arr[drawn]) {
      draws[i] = drawn;
    } else {
      i--;
    }
    seen_arr[drawn]++;
  }

  free(seen_arr);
  return draws;
}

int *int_rand_arr(int min, int max, int size) {
  if (size <= 0)
    return NULL;
  int *arr = malloc(size * sizeof(int));
  for (int i = 0; i < size; ++i)
    arr[i] = int_rand(min, max);
  return arr;
}

int value_in_array(int val, const int *arr, int len) {
  for (int i = 0; i < len; i++)
    if (arr[i] == val)
      return 1;
  return 0;
}

int consecutive(int a, int b, int c) {
  switch (abs(c - a)) {
  case 2:
    return (2 * b == a + c);
  case 1:
    return consecutive(b, c, a);
  default:
    return 0;
  }
}

int all_equal(const int *arr, int len) {
  for (int i = 0; i < len; i++)
    if (arr[0] != arr[i])
      return 0;
  return 1;
}
