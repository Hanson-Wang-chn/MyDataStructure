//
// Created by 王海生 on 2024/4/22.
//

#ifndef POLYNOMIAL_UTILITY_H
#define POLYNOMIAL_UTILITY_H

#include <cstddef>
#include <iostream>

using namespace std;

enum Error_code {underflow, overflow, success};

void introduction();
void instructions();

// Check input stream, resolve stream blocking and loop until a valid input is entered.
template <typename Input_type>
void check_stream(Input_type &x) {
    while (cin.fail()) {
        cout << "Must be a valid input!" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> x;
    }
}

#endif //POLYNOMIAL_UTILITY_H