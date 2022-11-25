/*
    Team name

    Aung, Phyo Pyae Moe
    Hlaing, Yu Yu

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#include "Course.h"
#include <iostream>

using namespace std;

int main()
{
    // Default Constructor
    Course course1;

    // Overloaded Constructor
    set<int> prereqsSet = {11, 12, 13};
    Course course2(250, "C++ Programming 2", 4, prereqsSet);

    // Get Prefix
    cout << "==============================" << endl;
    cout << "Prefix: " << Course::getPrefix() << endl;
    cout << "Expected: CS A\n\n";
    // Getter methods on course1
    cout << "==============================" << endl;
    cout << "Course created by default constructor\n";

    cout << "Course Number: " << course1.getCourseNumber() << endl;
    cout << "Expected: 0\n\n";

    cout << "Course Name: " << course1.getCourseName() << endl;
    cout << "Expected: N/A\n\n";

    cout << "Course Units: " << course1.getCourseUnits() << endl;
    cout << "Expected: 0\n\n";

    prereqsSet = course1.getCoursePrereqs();
    cout << "Number of prerequisites: " << prereqsSet.size() << endl;
    cout << "Expected: 0\n\n";

    cout << "Prerequisites: ";
    for(int prereq: prereqsSet)
    {
        cout << prereq << ", ";
    }
    cout << endl;
    cout << "Expected:\n\n";

    // Getter methods on course2
    cout << "==============================" << endl;
    cout << "Course created by overloaded constructor\n";

    cout << "Course Number: " << course2.getCourseNumber() << endl;
    cout << "Expected: 250\n\n";

    cout << "Course Name: " << course2.getCourseName() << endl;
    cout << "Expected: C++ Programming 2\n\n";

    cout << "Course Units: " << course2.getCourseUnits() << endl;
    cout << "Expected: 4\n\n";

    prereqsSet = course2.getCoursePrereqs();
    cout << "Number of prerequisites: " << prereqsSet.size() << endl;
    cout << "Expected: 3\n\n";

    cout << "Prerequisites: ";
    for(int prereq: prereqsSet)
    {
        cout << prereq << ", ";
    }
    cout << endl;
    cout << "Expected: 11, 12, 13\n\n";

    // Get Course
    Course course3 = course2.getCourse();
    cout << "==============================" << endl;
    cout << "Testing getCourse()\n";

    cout << "Course Number: " << course3.getCourseNumber() << endl;
    cout << "Expected: 250\n\n";

    cout << "Course Name: " << course3.getCourseName() << endl;
    cout << "Expected: C++ Programming 2\n\n";

    cout << "Course Units: " << course3.getCourseUnits() << endl;
    cout << "Expected: 4\n\n";

    prereqsSet = course3.getCoursePrereqs();
    cout << "Number of prerequisites: " << prereqsSet.size() << endl;
    cout << "Expected: 3\n\n";

    cout << "Prerequisites: ";
    for(int prereq: prereqsSet)
    {
        cout << prereq << ", ";
    }
    cout << endl;
    cout << "Expected: 11 12 13\n\n";

    // Setter methods
    cout << "==============================" << endl;
    cout << "Testing Setter methods\n";

    course1.setCourseNumber(150);
    cout << "Course Number: " << course1.getCourseNumber() << endl;
    cout << "Expected: 150\n\n";

    course1.setCourseName("C++ Programming 1");
    cout << "Course Name: " << course1.getCourseName() << endl;
    cout << "Expected: C++ Programming 1\n\n";

    course1.setCourseUnits(4);
    cout << "Course Units: " << course1.getCourseUnits() << endl;
    cout << "Expected: 4\n\n";

    // Set prereqs on empty set
    int prereqsArray[] = {170};
    course1.setPrereqs(prereqsArray, 1);
    prereqsSet = course1.getCoursePrereqs();

    cout << "Number of prerequisites: " << prereqsSet.size() << endl;
    cout << "Expected: 1\n\n";

    cout << "Prerequisites: ";
    for(int prereq: prereqsSet)
    {
        cout << prereq << ", ";
    }
    cout << endl;
    cout << "Expected: 170\n\n";

    // Set prereqs on non-empty set
    int prereqsArray1[] = {170, 150};
    course2.setPrereqs(prereqsArray1, 2);
    prereqsSet = course2.getCoursePrereqs();

    cout << "Number of prerequisites: " << prereqsSet.size() << endl;
    cout << "Expected: 2\n\n";

    cout << "Prerequisites: ";
    for(int prereq: prereqsSet)
    {
        cout << prereq << ", ";
    }
    cout << endl;
    cout << "Expected: 150, 170\n\n";

    cout << "==============================" << endl;
    cout << "End of testing" << endl;

}


