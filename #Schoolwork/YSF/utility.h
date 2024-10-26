//
// Created by 王海生 on 2024/4/5.
//

#ifndef CIRCULARLINKEDSTACK_UTILITY_H
#define CIRCULARLINKEDSTACK_UTILITY_H

#include <iostream>
#include <cstddef>

using namespace std;

enum Error_code {success, failed, underflow, overflow};
typedef int DataType;

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

#endif //CIRCULARLINKEDSTACK_UTILITY_H