// PolishCal.h - This header file contains the declaration of the PolishCal function.
// Created by 王海生 on 2024/3/8.
// Copyright (c) 2024, East China Normal University. All rights reserved.

#ifndef POLISHCAL_POLISHCAL_H
#define POLISHCAL_POLISHCAL_H

#include "MyStack.h"

char get_command();
bool do_command(char command, MyStack &numbers);

#endif //POLISHCAL_POLISHCAL_H
