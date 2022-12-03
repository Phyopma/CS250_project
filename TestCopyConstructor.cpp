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

void testCopyConstructor() {
/***************************************************
* TEST COPY CONSTRUCTOR: PARAMETER OBJECT IS EMPTY
****************************************************/
    cout << "Test Copy Constructor: Parameter object is empty\n";
// To print, create a variable of type string and use it
// as an argument to call the function retrieveAllCourses().
    string result;

// Create an object of the class CourseList named
// courseList1 using the default constructor.
    CourseList courseList1;

// Create an object of the class CourseList named
// courseList2 using the copy constructor with
// parameter courseList1.
// CALL: CourseList courseList1(courseList2)
    cout << "Constructing courseList2 using empty courseList 1\n";
    CourseList courseList2(courseList1);

// Print courseList1 (should be empty)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n"
         << result << endl;;

// Print courseList2 (should be empty)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n"
         << result << endl;;

/*****************************************************
* TEST COPY CONSTRUCTOR: PARAMETER OBJECT HAS COURSES
******************************************************/
    cout << "Test Copy Constructor: Parameter object has courses\n";
// Add 131 and 272 to courseList1
    set<int> s;
    courseList1.addCourse(131, "Python 1", 4, s);
    courseList1.addCourse(272, "Java 2", 4, s);

// Create an object of the class CourseList named
// courseList3 using the copy constructor with
// parameter courseList1.
// CALL: CourseList courseList3(courseList1)
    CourseList courseList3(courseList1);

// Print courseList1 (should show 131 and 272)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n"
         << result << endl;;

// Print courseList3 (should show 131 and 272)
    courseList3.retrieveAllCourses(result);
    cout << "courseList3 constructed from courseList1:\n"
         << result << endl;;

// CLEAR courseList1
    cout << "Clearing courseList1\n";
    courseList1.clearList();

// Print courseList1 (should be empty)
    courseList1.retrieveAllCourses(result);
    cout
            << "courseList1:\n"
            << result << endl;;

// Print courseList3 (should show 131 and 272)
    courseList3.retrieveAllCourses(result);
    cout
            << "courseList3:\n"
            << result << endl;;
}

//int main() {
//    testCopyConstructor();
//}