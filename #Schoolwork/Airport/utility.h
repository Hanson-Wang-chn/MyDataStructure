//
// Created by 王海生 on 2024/3/13.
//

#ifndef AIRPORT_UTILITY_H
#define AIRPORT_UTILITY_H

#include <iostream>

using namespace std;

// for the MyQueue class
const int MAX_SIZE = 100;
enum Error_code {underflow, overflow, success, fail};

// 检查输入流，修复流挂起
template <typename Input_type>
void check_stream(Input_type &x) {
    while (cin.fail()) {
        cout << "Must be a valid input!" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> x;
    }
}

// for the Plane class
enum Plane_status {null, arriving, departing};

// for the Runway class
enum Runway_activity {idle, land, takeoffs};

// for the main function
void initialize(int &end_time, int &queue_limit, double &arrival_rate, double &departure_rate);
void run_idle(int time);

#endif //AIRPORT_UTILITY_H
