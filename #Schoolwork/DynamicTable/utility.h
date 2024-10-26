//
// Created by 王海生 on 2024/4/4.
//

#ifndef LINKEDLIST_UTILITY_H
#define LINKEDLIST_UTILITY_H

#include <iostream>
#include <cstddef>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

enum Error_code {success, failed, underflow, overflow};
typedef int DataType;

vector<vector<string>> readCSV(const string& filename);

#endif //LINKEDLIST_UTILITY_H