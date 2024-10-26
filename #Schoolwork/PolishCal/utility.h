// utility.h - This header file contains utility functions for common tasks.
// Created by 王海生 on 2024/3/8.
// Copyright (c) 2024, East China Normal University. All rights reserved.

#ifndef POLISHCAL_UTILITY_H
#define POLISHCAL_UTILITY_H

#include <iostream>
#include <cctype>

using namespace std;

const int MAX_SIZE = 101;
enum Error_code {success, overflow, underflow};
typedef double Data_type;

void introduction();
void instructions();

#endif //POLISHCAL_UTILITY_H
