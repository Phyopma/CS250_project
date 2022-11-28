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

template<typename A, typename E>
void display(const string& title, const A& actual, const E& expected) {
    cout << title << ": " << endl;;
    cout << left << setw(20) << "\tActual: " << actual << endl;
    cout << left << setw(20) << "\tExpected: " << expected << "\n\n";
}

void hBar() {
    cout << "==============================" << endl;
}

// Part A
void constructorTest();

void courseGetterTest();

void courseSetterTest();

// Part B
void testCourseList();

void testCopyConstructor();

void testOpEqualEmptyObjs();

void testOpEqSameLengthObjs();

void testOpEqCallingLonger();

void testOpEqCallingShorter();


int main() {
    // Part A
    constructorTest();
    courseGetterTest();
    courseSetterTest();

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

void constructorTest() {
    // Default Constructor
    Course course1;

    // Overloaded Constructor
    set<int> prereqsSet = {11, 12, 13};
    Course course2(250, "C++ Programming 2", 4, prereqsSet);

    // Get Prefix
    hBar();
    display("Prefix", Course::getPrefix(), "CS A");

    // Getter methods on course1
    hBar();
    cout << "Course created by default constructor\n";

    display("Course Name", course1.getCourseName(), "N/A");

    display("Coruse Units", course1.getCourseUnits(), 0);

    prereqsSet = course1.getCoursePrereqs();
    display("Number of pre-requisites", prereqsSet.size(), 0);

    cout << "Prerequisites: ";
    for (int prereq: prereqsSet) {
        cout << prereq << " ";
    }
    cout << endl;
    cout << "Expected:\n\n";
}

void courseGetterTest() {
    // Default Constructor
    Course course1;

    // Overloaded Constructor
    set<int> prereqsSet = {11, 12, 13};
    Course course2(250, "C++ Programming 2", 4, prereqsSet);

    // Getter methods on course2
    hBar();
    cout << "Course created by overloaded constructor\n";

    display("Course Number", course2.getCourseNumber(), 250);

    display("Course Name", course2.getCourseName(), "C++ Programming 2");

    display("Course Units", course2.getCourseUnits(), 4);

    prereqsSet = course2.getCoursePrereqs();
    display("Number of pre-requisites", prereqsSet.size(), 3);

    cout << "Prerequisites: ";
    for (int prereq: prereqsSet) {
        cout << prereq << " ";
    }
    cout << endl;
    cout << "Expected: 11 12 13\n\n";

    // Get Course
    Course course3 = course2.getCourse();
    hBar();
    cout << "Testing getCourse()\n";

    display("Course Number", course3.getCourseNumber(), 250);

    display("Course Name", course3.getCourseName(), "C++ Programming 2");

    display("Course Units", course3.getCourseUnits(), 4);


    prereqsSet = course3.getCoursePrereqs();
    display("Number of pre-requisites", prereqsSet.size(), 3);

    cout << "Prerequisites: ";
    for (int prereq: prereqsSet) {
        cout << prereq << " ";
    }
    cout << endl;
    cout << "Expected: 11 12 13\n\n";
}

void courseSetterTest() {
    // Default Constructor
    Course course1;

    // Overloaded Constructor
    set<int> prereqsSet = {11, 12, 13};
    Course course2(250, "C++ Programming 2", 4, prereqsSet);

    // Setter methods
    hBar();
    cout << "Testing Setter methods\n";

    course1.setCourseNumber(150);
    display("Course Number", course1.getCourseNumber(), 150);


    course1.setCourseName("C++ Programming 1");
    display("Course Name", course1.getCourseName(), "C++ Programming 1");

    course1.setCourseUnits(4);
    display("Course Units", course1.getCourseUnits(), 4);


    // Set prereqs on empty set
    int prereqsArray[] = {170};
    course1.setPrereqs(prereqsArray, 1);
    prereqsSet = course1.getCoursePrereqs();

    display("Number of pre-requisites", prereqsSet.size(), 1);


    cout << "Prerequisites: ";
    for (int prereq: prereqsSet) {
        cout << prereq << " ";
    }
    cout << endl;
    cout << "Expected: 170\n\n";

    // Set prereqs on non-empty set
    int prereqsArray1[] = {170, 150};
    course2.setPrereqs(prereqsArray1, 2);
    prereqsSet = course2.getCoursePrereqs();
    display("Number of pre-requisites", prereqsSet.size(), 2);


    cout << "Prerequisites: ";
    for (int prereq: prereqsSet) {
        cout << prereq << " ";
    }
    cout << endl;
    cout << "Expected: 150 170\n\n";

    hBar();
}


