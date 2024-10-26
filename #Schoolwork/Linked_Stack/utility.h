//
// Created by 王海生 on 2024/3/14.
//

#ifndef LINKEDSTACK_UTILITY_H
#define LINKEDSTACK_UTILITY_H

#include <cstddef>
#include <iostream>

using namespace std;

enum Error_code {underflow, overflow, success};
typedef double Stack_entry;
typedef Stack_entry Node_entry;

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

#endif //LINKEDSTACK_UTILITY_H
