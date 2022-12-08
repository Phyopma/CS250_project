/*
    Coffee Addicts

    Aung, Phyo Pyae Moe
    Hlaing, Yu Yu

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#include "CourseList.h"
#include <iostream>

using namespace std;

// Part B
void testCourseList();

void testCopyConstructor();

void testOpEqualEmptyObjs();

void testOpEqSameLengthObjs();

void testOpEqCallingLonger();

void testOpEqCallingShorter();

int main() {
    // Part B
    testCourseList();
    testCopyConstructor();
    testOpEqualEmptyObjs();
    testOpEqSameLengthObjs();
    testOpEqCallingLonger();
    testOpEqCallingShorter();

    cout << "\n";
    return 0;
}




