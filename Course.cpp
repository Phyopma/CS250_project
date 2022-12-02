/*
    Coffee Addicts

    Aung, Phyo Pyae Moe
    Hlaing, Yu Yu

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#include "Course.h"
#include <iostream>
#include <iomanip>

using namespace std;
const string Course::PREFIX = "CS A";

// Definition overloaded constructor
Course::Course(int otherCourseNumber, const string& otherCourseName,
               int otherCourseUnits, const set<int>& otherPrereqs) :
        courseNumber(otherCourseNumber),
        courseName(otherCourseName),
        courseUnits(otherCourseUnits),
        prereqs(otherPrereqs) {}

// Definition function getCourseName
const string& Course::getCourseName() const {
    return courseName;
}

// Definition function getCourseNumber
int Course::getCourseNumber() const {
    return courseNumber;
}

// Definition function getCourseUnits
int Course::getCourseUnits() const {
    return courseUnits;
}

// Definition function getPrereqs
const set<int>& Course::getCoursePrereqs() const {
    return prereqs;
}

// Definition function getCourse
const Course& Course::getCourse() const {
    return *this;
}

// Definition function getPrefix
string Course::getPrefix() {
    return Course::PREFIX;
}

// Definition function setCourseName
void Course::setCourseName(const string& newCourseName) {
    courseName = newCourseName;
}

// Definition function setCourseNumber
void Course::setCourseNumber(int newCourseNumber) {
    courseNumber = newCourseNumber;
}

// Definition function setCourseUnits
void Course::setCourseUnits(int newCourseUnits) {
    courseUnits = newCourseUnits;
}

// Definition function setPrereqs
void Course::setPrereqs(const int* prereqsArray, int length) {
    prereqs.clear();
    for (int i = 0; i < length; ++i) {
        prereqs.insert(prereqsArray[i]);
    }
}














