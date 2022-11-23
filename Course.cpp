/*
(name header)
*/
#include "Course.h"
#include <iostream>
#include <iomanip>
using namespace std;
const string Course::PREFIX = "CS A";

// Definition overloaded constructor
Course(int otherCourseNumber, const string &otherCourseName,
       int otherCourseUnits, set<int> &otherPrereqs) :
        courseNumber(otherCourseNumber),
        courseName(otherCourseName),
        courseUnits(otherCourseUnits),
        prereqs(otherPrereqs) {}

// Definition function getCourseNumber
int Course::getCourseNumber() const {}
{
    return courseNumber;
}

// Definition function getCourseName
string& Course::getCourseName() const
{
    return courseName;
}

// Definition function getCourseUnits
int Course::getCourseUnits() const
{
    return courseUnits;
}

// Definition function getPrereqs
set<int>& Course::getCoursePrereqs() const
{
    return prereqs;
}

// Definition function getCourse
Course& Course::getCourse() const {}
{
    return *this;
}

// Definition function getPrefix
static string Course::getPrefix()
{
    return PREFIX;
}

// Definition function setCourseName
void Course::setCourseName(string & newCourseName)
{
    courseName = newCourseName;
}

// Definition function setCourseNumber
void Course::setCourseNumber(int newCourseNumber)
{
    courseNumber = newCourseNumber;
}

// Definition function setCourseUnits
void Course::setCourseUnits(int newCourseUnits)
{
    courseUnits = newCourseUnits;
}

// Definition function setPrereqs
void Course::setPrereqs(int *prereqsArray, int lenArray)
{
    for(int prereq: prereqsArray)
    {
        prereqs.insert(prereq);
    }
}
