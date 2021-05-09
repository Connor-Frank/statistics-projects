#include "utils.h"
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_LEVELS 100

static long numbers_generated = 0;

void error_msg(const char *msg) {
  fprintf(stderr, "%s\n\n", msg);
  void *buffer[STACK_LEVELS];
  const int levels = backtrace(buffer, STACK_LEVELS);
  backtrace_symbols_fd(buffer + 1, levels - 1, 2);
  exit(EXIT_FAILURE);
}

void results(const char *msg, long times, long trials, double duration) {
  printf("%ld trials were simulated\n", trials);
  printf("%s %ld times\n", msg, times);
  const long double percentage = (long double)times / trials * 100.0;
  printf("that's equal to %Lf%% of the time\n", percentage);
  printf("time to run: %f seconds\n", duration);
  printf("random numbers generated: %ld\n", numbers_generated);
}

#if __unix__ || __APPLE__

void seed_rand(void) {
  struct timespec ts;
  if (timespec_get(&ts, TIME_UTC) == 0) {
    error_msg("problem seeding the pseudorandom number generator");
  } else {
    unsigned int seed = ts.tv_nsec ^ ts.tv_sec;
    printf("random seed: %u\n", seed);
    srandom(seed);
  }
}

int int_rand(int min, int max) {
  if (min >= max) {
    error_msg("minimum value needs to be less than maximum value.");
  }
  numbers_generated++;

  return (random() % (max - min + 1)) + min;
}

#elif _WIN32

/*
 * IMPORTANT NOTE: This code *seems* like it should compile properly on Windows,
 * but it hasn't been tested. ¯\_(ツ)_/¯
 */

#include <Bcrypt.h>
#include <Ntstatus.h>
#include <Wincrypt.h>
#include <Windows.h>

void seed_rand(void) { printf("using BCryptGenRandom on Windows\n"); }

int int_rand(int min, int max) {
  if (min >= max) {
    error_msg("minimum value needs to be less than maximum value.");
  }
  int Buffer, val;
  BCRYPT_ALG_HANDLE Prov;
  if (!BCRYPT_SUCCESS(
          BCryptOpenAlgorithmProvider(&Prov, BCRYPT_RNG_ALGORITHM, NULL, 0))) {
    error_msg("error.");
  }
  if (!BCRYPT_SUCCESS(
          BCryptGenRandom(Prov, (PUCHAR)(&Buffer), sizeof(Buffer), 0))) {
    error_msg("error.");
  }
  val = (Buffer % (max - min + 1)) + min;
  numbers_generated++;

  BCryptCloseAlgorithmProvider(Prov, 0);
  return val;
}

#endif

int *int_rand_no_rep(int min, int max, int len) {
  if (len <= 0) {
    error_msg("invalid length of random number array.");
  }
  int *seen_arr = calloc(max + 1, sizeof(int));
  int *draws = malloc(len * sizeof(int));
  int drawn;

  for (int i = 0; i < len; ++i) {
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

int *int_rand_arr(int min, int max, int len) {
  if (len <= 0) {
    error_msg("invalid length of random number array.");
  }
  int *arr = malloc(len * sizeof(int));
  for (int i = 0; i < len; ++i) {
    arr[i] = int_rand(min, max);
  }

  return arr;
}

int value_in_array(int val, const int *arr, const int len) {
  for (int i = 0; i < len; ++i) {
    if (arr[i] == val) {
      return 1;
    }
  }

  return 0;
}

int consecutive(const int a, const int b, const int c) {
  switch (abs(c - a)) {
  case 2:
    return (2 * b == a + c);
  case 1:
    return consecutive(b, c, a);
  default:
    return 0;
  }
}

int all_equal(const int *arr, const int len) {
  for (int i = 0; i < len; ++i) {
    if (arr[0] != arr[i]) {
      return 0;
    }
  }

  return 1;
}

int find_sums(const int *arr, const int len, int target, int current, int i) {
  if (i == len) {
    if (target == current) {
      return 1;
    } else {
      return 0;
    }
  }

  return find_sums(arr, len, target, current + arr[i], i + 1) +
         find_sums(arr, len, target, current - arr[i], i + 1);
}
