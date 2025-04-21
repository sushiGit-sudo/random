#pragma once


#include <stdlib.h>

#define lli long long int
#define RAND_MUL 1664525
#define RAND_INC 1013904223

/// @brief Seed value is the initial value to the lcg (linear_congruential_generator) function
struct Seed
{
    lli value;
};

/// @brief Used to store general data for a random number
struct Rand
{
    struct Seed seed;
    lli multiplier;
    lli increment;
    lli frequency;
    lli min;
    lli max;
};

/// @brief An algorithm that yields a sequence of pseudo-randomized numbers calculated with a discontinuous piecewise linear equation.
lli linear_congruential_generator(struct Seed seed, lli multiplier, lli increment, lli modulus)
{
    return (multiplier * seed.value + increment) % modulus;
}

/// @brief Generates a random number
/// @note To get multiple numbers you need to take the first random number and replace the seed.
lli random(struct Seed seed, lli mul, lli inc, lli max, lli min)
{
    return linear_congruential_generator(seed, mul, inc + min, max + min);
}

/// @brief This creates a list of random numbers
/// @warning This Function Uses 'malloc' To Store The List OF lli's. Make Sure To Use 'free' To Free The List.
lli* random_list(struct Rand* rand)
{
    lli* random_number_list = (lli*)malloc(rand->frequency * sizeof(lli));

    for (int i = 0; i < rand->frequency; i++)
    {
        rand->seed.value = random(rand->seed, rand->multiplier, rand->increment, rand->max, rand->min);
        *(random_number_list + i) = rand->seed.value;
    }

    return random_number_list;
}