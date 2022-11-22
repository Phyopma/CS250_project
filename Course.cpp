/*
(name header)
*/
#include "Course.h"
#include <iostream>
#include <iomanip>
using namespace std;
const string Course::PREFIX = "CS A";

const std::string& Course::getCourseName() const {
    return courseName;
}

int Course::getCourseNumber() const {
    return courseNumber;
}

int Course::getCourseUnits() const {
    return courseUnits;
}

const set<int>& Course::getCoursePrereqs() const  {
    return prereqs;
}

const Course &Course::getCourse()  {
    return *this;
}

std::string Course::getPrefix() {
    return std::string();
}

void Course::setCourseName(string &) {

}

void Course::setCourseNumber(int) {

}

void Course::setCourseUnits(int) {

}

void Course::setPrereqs(int *, int) {

}

Course::~Course() {

}
// Definition overloaded constructor
// Definition function getCourseNumber
// Definition function getCourseName
// Definition function getCourseUnits
// Definition function getPrereqs
// Definition function getCourse
// Definition function getPrefix
// Definition function setCourseName
// Definition function setCourseNumber
// Definition function setCourseUnits
// Definition function setPrereqs
