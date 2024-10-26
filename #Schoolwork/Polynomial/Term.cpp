//
// Created by 王海生 on 2024/4/22.
//

#include"Term.h"

Term::Term(int exponent, double scalar)
/*
Post: The Term is initialized with the given coefficient and exponent,
      or with default parameter values of 0.
*/
{
    degree = exponent;
    coefficient = scalar;
}