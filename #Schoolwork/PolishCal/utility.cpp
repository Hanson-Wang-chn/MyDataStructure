// utility.cpp - This file contains utility functions for common tasks.
// Created by 王海生 on 2024/3/8.
// Copyright (c) 2024, East China Normal University. All rights reserved.

#include "utility.h"

void introduction()
{
    cout << "This is a reverse Polish Calculator." << endl;
}

void instructions()
{
    cout << "Please enter a valid command:"   << endl
         << "[?]push to stack   [=]print top" << endl
         << "[+] [-] [*] [/]   are arithmetic operations" << endl
         << "[Q]uit." << endl;
}