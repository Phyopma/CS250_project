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
    cout << "Parameter object is empty\n";
// To print, create a variable of type string and use it
// as an argument to call the function retrieveAllCourses().
    string result;
// Create two objects of the class CourseList:
// courseList1 and courseList2
    CourseList courseList1;
    CourseList courseList2;

// Print courseList1 (should be empty)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1 created:\n" << result;

// Print courseList2 (should be empty)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2 created:\n" << result;

// CALL: courseList1 = courseList2;
    courseList1 = courseList2;
    cout << "courseList1 assigned as courseList2\n";

// Print courseList1 (should be empty)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1 after assignment\n" << result;

// Print courseList2 (should be empty)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2 after assignment\n" << result;
}

void testOpEqSameLengthObjs() {
//TEST ASSIGNMENT OPERATOR: OBJECTS HAVE SAME LENGTH
    cout << "Objects have same length\n";

// To print, create a variable of type string and use it
// as an argument to call the function retrieveAllCourses().
    string result;

// Create courseList1 with two courses: 131 and 272
    set<int> s;
    CourseList courseList1;
    courseList1.addCourse(131, "Python Programming 1", 4, s);
    courseList1.addCourse(272, "Java Programming 2", 4, s);

// Create courseList2 with two courses: 150 and 250
    CourseList courseList2;
    courseList2.addCourse(150, "C++ Programming1", 4, s);
    courseList2.addCourse(250, "C++ Programming 2", 4, s);

// Print courseList1 (should show 131 and 272)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n" << result;

// Print courseList2 (should show 150 and 170)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n" << result;

// CALL: courseList1 = courseList2
    courseList1 = courseList2;
    cout << "courseList1 assigned as courseList2\n";

// Print courseList1 (should show 150 and 170)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1 after assignment:\n" << result;

// Print courseList2 (should show 150 and 170)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2 after assignment:\n" << endl;

// CLEAR courseList2
    courseList2.clearList();
    cout << "After clearing courseList2\n";

// Print courseList1 (should show 150 and 170)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n" << result;

// Print courseList2 (should be empty)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n" << result;
}

void testOpEqCallingLonger() {
//TEST ASSIGNMENT OPERATOR : CALLING OBJ IS LONGER
    cout << "Calling object is longer\n";

// To print, create a variable of type string and use it
// as an argument to call the function retrieveAllCourses().
    string result;

// Create courseList1 with four courses: 131, 170, 257, and 272
    set<int> s;
    CourseList courseList1;
    courseList1.addCourse(131, "Python Programming 1", 4, s);
    courseList1.addCourse(170, "Java Programming 1", 4, s);
    courseList1.addCourse(257, "Boolean Algebra and Logic", 3, s);
    courseList1.addCourse(272, "Java Programming 2", 4, s);

// Create courseList2 with two courses: 150, and 250
    CourseList courseList2;
    courseList2.addCourse(150, "C++ Programming 1", 4, s);
    courseList2.addCourse(250, "C++ Programming 2", 4, s);

// Print courseList1 (should show 131, 170, 257, 272)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n" << result;

// Print courseList2 (should show 150 and 170)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n" << result;

// CALL: courseList1 = courseList2
    courseList1 = courseList2;
    cout << "courseList1 assigned as courseList2\n";

// Print courseList1 (should show 150 and 170)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1 after assignment:\n" << result;

// Print courseList2 (should show 150 and 170)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2 after assignment:\n" << result;

// CLEAR courseList2
    courseList2.clearList();
    cout << "After clearing courseList2\n";

// Print courseList1 (should show 150 and 170)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n" << result;

// Print courseList2 (should be empty)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n" << result;
}

void testOpEqCallingShorter() {
//TEST ASSIGNMENT OPERATOR: CALLING OBJ IS SHORTER
    cout << "Calling object is shorter\n";
// To print, create a variable of type string and use it
// as an argument to call the function retrieveAllCourses().
    string result;

// Create courseList1 with two courses: 131, 272
    set<int> s;
    CourseList courseList1;
    courseList1.addCourse(131, "Python Programming 1", 4, s);
    courseList1.addCourse(272, "Java Programming 2", 4, s);

// Create courseList2 with four courses: 150, 170, 250, and 257
    CourseList courseList2;
    courseList2.addCourse(150, "C++ Programming 1", 4, s);
    courseList2.addCourse(170, "Java Programming 1", 4, s);
    courseList2.addCourse(250, "C++ Programming 2", 4, s);
    courseList2.addCourse(257, "Boolean Algebra and Logic", 3, s);

// Print courseList1 (should show 131 and 272)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n" << result;

// Print courseList2 (should show 150, 170, 250, 257)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n" << result;

// CALL: courseList1 = courseList2
    courseList1 = courseList2;
    cout << "courseList1 assigned as courseList2\n";

// Print courseList1 (should show 150, 170, 250, 257)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n" << result;

// Print courseList2 (should show 150, 170, 250, 257)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n" << result;

// CLEAR courseList2
    courseList2.clearList();
    cout << "After clearing courseList2\n";

// Print courseList1 (should show 150, 170, 250, 257)
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n" << result;

// Print courseList2 (should be empty)
    courseList2.retrieveAllCourses(result);
    cout << "courseList2:\n" << result;
}