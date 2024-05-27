#include "random.hpp"
#include <cstdlib>
#include <ctime>

bool rng_is_seeded = false;

void seed_rng() {
    if(!rng_is_seeded) {
        std::srand(std::time(nullptr));
        random_is_seeded = true;
    }
}


void fill_with_random_numbers(long* arr, long length, long min, long max) {
    seed_rng();
    for(int i = 0; i < length; i++)
        arr[i] = min + std::rand() % (max - min);
}
