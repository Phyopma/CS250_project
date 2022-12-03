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

void testOpEqualEmptyObjs() {
// TEST ASSIGNMENT OPERATOR: PARAMETER OBJECT IS EMPTY
    cout << "Test Assignment Operator: Parameter object is empty\n";

// To print, create a variable of type string and use it
// as an argument to call the function retrieveAllCourses().
    string result;

// Create two objects of the class CourseList:
// courseList1 and courseList2
    CourseList courseList1;
    CourseList courseList2;

// Print courseList1 (should be empty)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n"
         << result << endl;

// Print courseList2 (should be empty)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n"
         << result << endl;

// CALL: courseList1 = courseList2;
    cout << "Assigning courseList1 as courseList2\n";
    courseList1 = courseList2;

// Print courseList1 (should be empty)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1 after assignment:\n"
         << result << endl;

// Print courseList2 (should be empty)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2 after assignment:\n"
         << result << endl;
}

void testOpEqSameLengthObjs() {
//TEST ASSIGNMENT OPERATOR: OBJECTS HAVE SAME LENGTH
    cout << "Test Assignment Operator: Objects have same length\n";

// To print, create a variable of type string and use it
// as an argument to call the function retrieveAllCourses().
    string result;

// Create courseList1 with two courses: 131 and 272
    set<int> s;
    CourseList courseList1;
    courseList1.addCourse(131, "Python 1", 4, s);
    courseList1.addCourse(272, "Java 2", 4, s);

// Create courseList2 with two courses: 150 and 170
    CourseList courseList2;
    courseList2.addCourse(150, "C++ 1", 4, s);
    courseList2.addCourse(170, "Java 1", 4, s);

// Print courseList1 (should show 131 and 272)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n"
         << result << endl;

// Print courseList2 (should show 150 and 170)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n"
         << result << endl;

// CALL: courseList1 = courseList2
    cout << "Assigning courseList1 as courseList2\n";
    courseList1 = courseList2;

// Print courseList1 (should show 150 and 170)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n"
         << result << endl;

// Print courseList2 (should show 150 and 170)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n"
         << result << endl;

// CLEAR courseList2
    courseList2.clearList();
    cout << "Clearing courseList2\n";

// Print courseList1 (should show 150 and 170)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n"
         << result << endl;

// Print courseList2 (should be empty)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n"
         << result << endl;
}

void testOpEqCallingLonger() {
//TEST ASSIGNMENT OPERATOR : CALLING OBJ IS LONGER
    cout << "Test Assignment Operator: Calling object is longer\n";

// To print, create a variable of type string and use it
// as an argument to call the function retrieveAllCourses().
    string result;

// Create courseList1 with four courses: 131, 170, 257, and 272
    set<int> s;
    CourseList courseList1;
    courseList1.addCourse(131, "Python 1", 4, s);
    courseList1.addCourse(170, "Java 1", 4, s);
    courseList1.addCourse(257, "Boolean Algebra", 3, s);
    courseList1.addCourse(272, "Java 2", 4, s);

// Create courseList2 with two courses: 150, and 170
    CourseList courseList2;
    courseList2.addCourse(150, "C++ 1", 4, s);
    courseList2.addCourse(170, "Java 1", 4, s);

// Print courseList1 (should show 131, 170, 257, 272)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n"
         << result << endl;;

// Print courseList2 (should show 150 and 170)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n"
         << result << endl;;

// CALL: courseList1 = courseList2
    cout << "Assigning courseList1 as courseList2\n";
    courseList1 = courseList2;

// Print courseList1 (should show 150 and 170)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1 after assignment:\n"
         << result << endl;;

// Print courseList2 (should show 150 and 170)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2 after assignment:\n"
         << result << endl;;

// CLEAR courseList2
    courseList2.clearList();
    cout << "Clearing courseList2\n";

// Print courseList1 (should show 150 and 170)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n"
         << result << endl;;

// Print courseList2 (should be empty)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n"
         << result << endl;;
}

void testOpEqCallingShorter() {
//TEST ASSIGNMENT OPERATOR: CALLING OBJ IS SHORTER
    cout << "Test Assignment Operator: Calling object is shorter\n";

// To print, create a variable of type string and use it
// as an argument to call the function retrieveAllCourses().
    string result;

// Create courseList1 with two courses: 131, 272
    set<int> s;
    CourseList courseList1;
    courseList1.addCourse(131, "Python 1", 4, s);
    courseList1.addCourse(272, "Java 2", 4, s);

// Create courseList2 with four courses: 150, 170, 250, and 257
    CourseList courseList2;
    courseList2.addCourse(150, "C++ 1", 4, s);
    courseList2.addCourse(170, "Java 1", 4, s);
    courseList2.addCourse(250, "C++ 2", 4, s);
    courseList2.addCourse(257, "Boolean Algebra", 3, s);

// Print courseList1 (should show 131 and 272)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n"
         << result << endl;;

// Print courseList2 (should show 150, 170, 250, 257)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n"
         << result << endl;;

// CALL: courseList1 = courseList2
    cout << "Assigning courseList1 as courseList2\n";
    courseList1 = courseList2;

// Print courseList1 (should show 150, 170, 250, 257)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n"
         << result << endl;;

// Print courseList2 (should show 150, 170, 250, 257)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n"
         << result << endl;;

// CLEAR courseList2
    courseList2.clearList();
    cout << "Clearing courseList2\n";

// Print courseList1 (should show 150, 170, 250, 257)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n"
         << result << endl;;

// Print courseList2 (should be empty)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n"
         << result << endl;;
}

//int main() {
//    testOpEqualEmptyObjs();
//    testOpEqSameLengthObjs();
//    testOpEqCallingLonger();
//    testOpEqCallingShorter();
//}