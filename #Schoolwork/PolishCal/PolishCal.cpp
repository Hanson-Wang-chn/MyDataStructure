// PolishCal.cpp - This file contains the declaration of the PolishCal function.
// Created by 王海生 on 2024/3/8.
// Copyright (c) 2024, East China Normal University. All rights reserved.

#include "PolishCal.h"

char get_command()
{
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter>:";
    while (waiting) {
        cin >> command;
        command = tolower(command);
        if (command == '?' || command == '=' || command == '+' ||
            command == '-' || command == '*' || command == '/' ||
            command == 'q' ) {
            waiting = false;
        } else {
            cout << "Please enter a valid command:"   << endl
                 << "[?]push to stack   [=]print top" << endl
                 << "[+] [-] [*] [/]   are arithmetic operations" << endl
                 << "[Q]uit." << endl;
        }
    }
    return command;
}

bool do_command(char command, MyStack &numbers)
{
    Data_type p, q;
    switch (command) {
        case '?':
            cout << "Enter a real number: " << flush;
            cin >> p;
            if (numbers.push(p) == overflow) {
                cout << "Warning: Stack full, lost number" << endl;
            }
            break;
        case '=':
            if (numbers.peek(p) == underflow) {
                cout << "Stack empty" << endl;
            } else {
                cout << p << endl;
            }
            break;
        case '+':
            if (numbers.size() == 0) {
                cout << "Stack empty" << endl;
            } else if (numbers.size() == 1) {
                cout << "Stack has just one entry" << endl;
            } else {
                numbers.pop(p);
                numbers.pop(q);
                if (numbers.push(p + q) == overflow) {
                    cout << "Warning: Stack full, lost result" << endl; // 这里真的有可能溢出吗（两出一进）
                }
            }
            break;
        case '-':
            if (numbers.size() == 0) {
                cout << "Stack empty" << endl;
            } else if (numbers.size() == 1) {
                cout << "Stack has just one entry" << endl;
            } else {
                numbers.pop(p);
                numbers.pop(q);
                if (numbers.push(q - p) == overflow) {
                    cout << "Warning: Stack full, lost result" << endl;
                }
            }
            break;
        case '*':
            if (numbers.size() == 0) {
                cout << "Stack empty" << endl;
            } else if (numbers.size() == 1) {
                cout << "Stack has just one entry" << endl;
            } else {
                numbers.pop(p);
                numbers.pop(q);
                if (numbers.push(p * q) == overflow) {
                    cout << "Warning: Stack full, lost result" << endl;
                }
            }
            break;
        case '/':
            if (numbers.size() == 0) {
                cout << "Stack empty" << endl;
            } else if (numbers.size() == 1) {
                cout << "Stack has just one entry" << endl;
            } else {
                numbers.pop(p);
                numbers.pop(q);
                if (numbers.push(q / p) == overflow) {
                    cout << "Warning: Stack full, lost result" << endl;
                }
            }
            break;
        case 'q':
            cout << "Calculation finished." << endl;
            return false;
    }
    return true;
}