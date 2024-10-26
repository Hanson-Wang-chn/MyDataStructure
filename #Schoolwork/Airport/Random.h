//
// Created by 王海生 on 2024/3/13.
//

#ifndef AIRPORT_RANDOM_H
#define AIRPORT_RANDOM_H

class Random {
public:
    Random(bool pseudo = true);
    double random_real();
    int random_integer(int low, int high);
    int poisson(double mean);

private:
    int reseed(); // Re-randomize the seed.
    int seed, multiplier, add_on;
    // constants for use in arithmetic operations
};

#endif //AIRPORT_RANDOM_H
