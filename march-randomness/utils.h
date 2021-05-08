#ifndef MARCH_RANDOMNESS_UTILS_H_
#define MARCH_RANDOMNESS_UTILS_H_

/*
 * Simple function to handle critical errors. Prints the error to stderr (with
 * a newline automatically appended) and provides a stacktrace before killing
 * the program.
 */
void error_msg(const char *message);

/*
 * Prints a multi-line message containing the results of the program. The
 * message should be formatted such that it can precede "x times". Also prints
 * the duration of time the program took to run and the number of random
 * numbers that were generated.
 */
void results(const char *msg, long times, long trials, double duration);

/*
 * Seeds the random number generator. Should be called once at the beginning of
 * every program. The method it uses is dependent on operating system:
 *
 * POSIX - seeds the random number generator using the system clock.
 * Windows - theoretically uses BCryptGenRandom() to generate a random seed for
 *           rand(), but the code is untested. Your guess is as good as mine.
 */
void seed_rand(void);

/*
 * Returns a random integer in a range, including the minimum and maximum
 * values of that range.
 */
int int_rand(int min, int max);

/*
 * Returns an array of random integers in a range with no duplicate values. The
 * minimum value of the range cannot be negative.
 *
 * IMPORTANT: The array must be deallocated. An example is below:
 *
 * int *arr = int_rand_no_rep(min, max, size);
 * if (arr) {
 *   // do stuff here
 *   free(arr);
 * }
 *
 */
int *int_rand_no_rep(int min, int max, int len);

/*
 * Returns an array of random integers in a range. Similar to int_rand_no_rep,
 * but allows duplicates and negative minimum values. Remember to deallocate
 * the array.
 */
int *int_rand_arr(int min, int max, int len);

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

/*
 * Returns the number of sums in an array that equal a target. The variables
 * "current" and "i" should usually be 0 in the original function call.
 */
int find_sums(const int *arr, int len, int target, int current, int i);

#endif // MARCH_RANDOMNESS_UTILS_H_
