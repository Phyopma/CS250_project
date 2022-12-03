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

void testCourseList() {
// Create an object of the class CourseList.
    cout << "isEmpty Test\t:" << endl;
    CourseList courseList1;
// Call function CourseList::isEmpty and print a message.
    if (courseList1.isEmpty()) {
        cout << "The list is empty" << endl << endl;
    } else {
        cout << "The list is not empty" << endl << endl;
    }
// NOTE: To properly test the functions, it is
// recommended you use the course number
// suggested in this guideline.
// Create three objects of the class Course using
// the overloaded constructor.
// Courses: 250, 150, 200
    set<int> s;
    Course course1(250, "C++ 1", 4, s);
    Course course2(150, "Java 1", 4, s);
    Course course3(200, "C++ 2", 4, s);

// Call function CourseList::addCourse(Course) to add the three courses.
    courseList1.addCourse(course1);
    courseList1.addCourse(course2);
    courseList1.addCourse(course3);

// Call function CourseList::addCourse(int, string, int, set)
// to add three additional courses: 131, 272, 216
    courseList1.addCourse(131, "Calculus 1", 4, s);
    courseList1.addCourse(272, "Boolean Algebra", 4, s);
    courseList1.addCourse(216, "Discrete Structure", 4, s);

// Create a string and use it as a parameter to
// call function CourseList::retrieveAllCourses().
    cout
            << "Test of adding courses to courseList using overload functions and"
               " retrieving all courses in the list\t:" << endl;
    string result;
    courseList1.retrieveAllCourses(result);
// Print the string.
    cout << result << endl;
// Call CourseList::search(int) to search for 150.
    courseList1.searchCourse(150);
    string tempName;
// Create a string to store a course name, and
// call CourseList::search(int, string) to
// retrieve the name of the course and print it.
    cout
            << "Searching course with courseNumber and retrieving course Name\t:"
            << endl;
    courseList1.searchCourse(150, tempName);
    cout << "Course Name: " << tempName << endl << endl;

// Create an empty course by using the default constructor.
    cout
            << "Searching course with courseNumber and retrieving course object\t:"
            << endl;
    Course emptyCourse;
// Call function CourseList::search(int, Course) to
// retrieve the course and print the prefix, the number
// the name and the units.
    courseList1.searchCourse(150, emptyCourse);
    cout << courseList1.getPrefix() << emptyCourse.getCourseNumber()
         << " - "
         << emptyCourse.getCourseName()
         << " " << emptyCourse.getCourseUnits() << " units" << endl
         << endl;

    cout
            << "Test of deleting courses and retrieving all courses in the list\t:"
            << endl;
// Call function CourseList::deleteCourse to delete 131.
    courseList1.deleteCourse(131);
// Call function CourseList::deleteCourse to delete 272.
    courseList1.deleteCourse(272);
// Call function CourseList::deleteCourse to delete 150.
    courseList1.deleteCourse(150);
// Call function CourseList::deleteCourse to delete 250.
    courseList1.deleteCourse(250);
// Print all courses to see what is left in the list.
    courseList1.retrieveAllCourses(result);
    cout << result;
}

//int main() {
//    testCourseList();
//
//}

