#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

void seed_rand(void);

int int_rand(int min, int max);

int *int_rand_no_rep(int min, int max, int size);

int *int_rand_arr(int min, int max, int size);

int value_in_array(int val, const int *arr, int array_size);

bool consecutive(int a, int b, int c);

#endif // UTILS_H
