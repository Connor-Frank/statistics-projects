#ifndef MARCH_RANDOMNESS_UTILS_H_
#define MARCH_RANDOMNESS_UTILS_H_

/*
 * Seeds the random number generator using four bytes from /dev/random. Should
 * be called once at the beginning of every program.
 */
void seed_rand(void);

/*
 * Returns a random integer between min and max, inclusive.
 */
int int_rand(int min, int max);

/*
 * Returns an array of random integers with no duplicates.
 *
 * IMPORTANT: The array must be deallocated. An example is below:
 *
 * int *arr = int_rand_no_rep(min, max, size);
 * if (arr) {
 *   // do stuff here
 *   free(arr);
 * }
 */
int *int_rand_no_rep(int min, int max, int size);

/*
 * Returns an array of random integers. Similar to int_rand_no_rep, but allows
 * duplicates. Remember to deallocate the array.
 */
int *int_rand_arr(int min, int max, int size);

/*
 * Returns whether a value is in an array. Requires the array size to avoid
 * accessing invalid memory locations.
 */
int value_in_array(int val, const int *arr, int len);

/*
 * Returns whether three integer values are consecutive.
 */
int consecutive(int a, int b, int c);

/*
 * Returns whether all values of an array are equal.
 */
int all_equal(const int *arr, int len);

#endif // MARCH_RANDOMNESS_UTILS_H_
