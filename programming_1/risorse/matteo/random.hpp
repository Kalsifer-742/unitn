#ifndef UTILS_FILL_WITH_RANDOM_HPP
#define UTILS_FILL_WITH_RANDOM_HPP

extern bool rng_is_seeded;

void seed_rng();
void fill_with_random_numbers(long* arr, long length, long min, long max);

#endif
