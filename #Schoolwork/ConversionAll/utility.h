// utility.h - This header file contains utility functions for common tasks.
// Created by 王海生 on 2024/3/14.
// Copyright (c) 2024, East China Normal University. All rights reserved.

#ifndef CONVERSIONALL_UTILITY_H
#define CONVERSIONALL_UTILITY_H

#include <iostream>

using namespace std;

const int MAX_SIZE = 100;
enum Error_code {success, overflow, underflow};
typedef int Data_type;

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

#endif //CONVERSIONALL_UTILITY_H
