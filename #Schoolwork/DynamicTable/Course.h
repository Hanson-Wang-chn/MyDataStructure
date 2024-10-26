//
// Created by 王海生 on 2024/5/15.
//

#ifndef DYNAMICTABLE_COURSE_H
#define DYNAMICTABLE_COURSE_H

#include "utility.h"

class Course {
private:
    int id;
    string class_name;
    string instructor;
    double duration;

public:
    void get_id(int id);
    void get_class_name(string class_name);
    void get_instructor(string instructor);
    void get_duration(double duration);
};

#endif //DYNAMICTABLE_COURSE_H