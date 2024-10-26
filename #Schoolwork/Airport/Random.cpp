//
// Created by 王海生 on 2024/3/13.
//

#include "random.h"
#include <time.h>
#include <math.h>
#include <limits.h>

int Random::reseed()
/* Pre: None
   Post:The seed is replaced by a pseudorandom successor.*/
{
    seed = seed * multiplier + add_on;
    return seed;
}

Random::Random(bool pseudo)
/* Pre: None
   Post:The values of seed, add_on, and multiplier are
        initialized.  The seed is initialized randomly only if pseudo == false.*/
{
    if (pseudo)
        seed = 1;
    else
        seed = time(NULL) % INT_MAX;
    multiplier = 2743;
    add_on = 5923;
}

double Random::random_real()
/* Pre: None
   Post:A random real number between 0 and 1 is returned.*/
{
    double max = INT_MAX + 1.0;  //INT_MAX = (2)31 -1
    double temp = reseed();
    if (temp < 0)
        temp = temp + max;
    return temp / max;
}

int Random::random_integer(int low, int high)
/* Pre: None
   Post:A random integer between low and high (inclusive) is returned.*/
{
    if (low > high)
        return random_integer(high, low);
    return ((int) ((high - low + 1) * random_real())) + low;
}

int Random::poisson(double mean)
/* Pre: None
   Post:A random integer, reflecting a Poisson distribution
        with parameter mean, is returned.*/
{
    double limit = exp(-mean);
    double product = random_real();
    int count = 0;
    while (product > limit) {
        count++;
        product *= random_real();
    }
    return count;
}