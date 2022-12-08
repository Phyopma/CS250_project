/*
    Coffee Addicts

    Aung, Phyo Pyae Moe
    Hlaing, Yu Yu

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/
/**************************************************
EXPECTED OUTPUT:
java: CS A0 N/A 0
java: CS A272 Java 2 4 170
cpp: CS A250 C++ 2 4 150 170
aCourse: CS A272 Java 2 4 170
java: CS A370 Java 3 3 170 272
aCourse: CS A272 Java 2 4 170
***************************************************/
#include "Course.h"
#include <iostream>

using namespace std;

const int PREREQS = 5;

int main() {
// Create a course named "java" using the default constructor
    Course java;
// Print the course by using all the get functions.
    cout << "java: " << Course::getPrefix() << java.getCourseNumber();
    cout << " - " << java.getCourseName();
    cout << " (" << java.getCourseUnits() << " units)";
// To print the prerequisites, use a range-based loop
// (note that there is no need to create a set; you
// can call the getCoursePrereqs function in the loop header,
// because it would have the same running time as creating a new set.
    cout << " Prerequisites: ";
    for (int i: java.getCoursePrereqs()) {
        cout << i << " ";
    }
    // Set the values below to the "java" course by using mutator functions.
// Values: 272, "Java 2", 4
    java.setCourseNumber(272);
    java.setCourseName("Java 2");
    java.setCourseUnits(4);

// Create an array (no need to be dynamic) of length PREREQS,
// which is the global constant declared and initialized at the
// top of the file. You will need to declare the length of the
// array as well. Add one element to the array: 170
    int arr[PREREQS] = {170};
    java.setPrereqs(arr, 1);
// Call function setPrereqs to pass the array and the length.
// Print the course as you did above, to make sure the course
// has all new values.
    cout << "\njava: " << Course::getPrefix() << java.getCourseNumber();
    cout << " - " << java.getCourseName();
    cout << " (" << java.getCourseUnits() << " units)";
    cout << " Prerequisites: ";
    for (int i: java.getCoursePrereqs()) {
        cout << i << " ";
    }

// Create a course named "cpp" using the overloaded constructor with
// these values: 250, "C++ 2", 4, 150 170
// You can use as a fourth parameter the call: set<int>{150, 170}
    Course cpp = {250, "C++ 2", 4, set<int>{150, 170}};
    // Print the "cpp" course.
    cout << "\ncpp: " << &Course::getPrefix() << cpp.getCourseNumber();
    cout << " - " << cpp.getCourseName();
    cout << " (" << cpp.getCourseUnits() << " units)";
    cout << " Prerequisites: ";
    for (int i: cpp.getCoursePrereqs()) {
        cout << i << " ";
    }

// Create a course named "aCourse" as a copy of the "java" course
// by using the assignment operator and the function getCourse.
// This will call the default COPY constructor, which you do not
// need to implement, because the object is not pointing to any
// dynamic data.
    Course aCourse = java.getCourse();
// Print "aCourse" to make it is an exact copy of "java".
    cout << "\naCourse: ";
    cout << Course::getPrefix() << aCourse.getCourseNumber();
    cout << " - " << aCourse.getCourseName();
    cout << " (" << aCourse.getCourseUnits() << " units)";
    cout << " Prerequisites: ";
    for (int i: aCourse.getCoursePrereqs()) {
        cout << i << " ";
    }
// To check that "aCourse" and "java" are two distinct objects,
// modify "java" using the mutator functions to these new
// values: 370, "Java 3", 3, 170 272
    java.setCourseNumber(370);
    java.setCourseName("Java 3");
    java.setCourseUnits(3);
    arr[1] = 272;
    // Reuse the array by adding 272 to it, and increasing the length.
    java.setPrereqs(arr, 2);
// Print "java".
    cout << "\njava: ";
    cout << Course::getPrefix() << java.getCourseNumber();
    cout << " - " << java.getCourseName();
    cout << " (" << java.getCourseUnits() << " units)";
    cout << " Prerequisites: ";
    for (int i: java.getCoursePrereqs()) {
        cout << i << " ";
    }
// Print "aCourse", to make sure that it is still the same.
    cout << "\naCourse: ";
    cout << Course::getPrefix() << aCourse.getCourseNumber();
    cout << " - " << aCourse.getCourseName();
    cout << " (" << aCourse.getCourseUnits() << " units)";
    cout << " Prerequisites: ";
    for (int i: aCourse.getCoursePrereqs()) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}