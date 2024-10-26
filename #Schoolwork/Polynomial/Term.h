//
// Created by 王海生 on 2024/4/22.
//

#ifndef POLYNOMIAL_TERM_H
#define POLYNOMIAL_TERM_H

#include "utility.h"

struct Term {
    Term(int exponent = 0, double scalar = 0);
    int degree;
    double coefficient;
};

#endif //POLYNOMIAL_TERM_H