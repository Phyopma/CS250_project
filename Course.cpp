/*
(name header)
*/
#include "Course.h"
#include <iostream>
#include <iomanip>
using namespace std;
const string Course::PREFIX = "CS A";

// Definition overloaded constructor
Course::Course(int otherCourseNumber, const string &otherCourseName, int otherCourseUnits, set<int> &otherPrereqs) :
        courseNumber(otherCourseNumber),
        courseName(otherCourseName),
        courseUnits(otherCourseUnits),
        prereqs(otherPrereqs) {}

// Definition function getCourseName
const std::string& Course::getCourseName() const {
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
const set<int>& Course::getCoursePrereqs() const  {
    return prereqs;
}

// Definition function getCourse
const Course &Course::getCourse() const  {
    return *this;
}

// Definition function getPrefix
std::string Course::getPrefix() {
    return Course::PREFIX;
}

// Definition function setCourseName
void Course::setCourseName(string &) {

}

// Definition function setCourseNumber
void Course::setCourseNumber(int) {

}

// Definition function setCourseUnits
void Course::setCourseUnits(int) {

}

// Definition function setPrereqs
void Course::setPrereqs(int *, int) {

}














