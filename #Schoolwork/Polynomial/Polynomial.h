//
// Created by 王海生 on 2024/4/22.
//

#ifndef POLYNOMIAL_POLYNOMIAL_H
#define POLYNOMIAL_POLYNOMIAL_H

#include "MyLinkedQueue.h"

class Polynomial: private MyExtendedLinkedQueue {  //  Use private inheritance.
public:
    Polynomial();
    Polynomial(const Polynomial &original);
    void operator=(const Polynomial &original);
    void read();
    void print() const;
    void equals_sum(Polynomial p, Polynomial q);
    void equals_difference(Polynomial p, Polynomial q);
    void mult_term(Polynomial p, Term t);
    int degree() const;
};

#endif //POLYNOMIAL_POLYNOMIAL_H