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
    cout << "Test isEmpty():\n";
    CourseList courseList1;

// Call function CourseList::isEmpty and print a message.
    if (courseList1.isEmpty()) {
        cout << "The list is empty\n\n";
    } else {
        cout << "The list is not empty\n\n";
    }

// NOTE: To properly test the functions, it is
// recommended you use the course number
// suggested in this guideline.
// Create three objects of the class Course using
// the overloaded constructor.
// Courses: 250, 150, 200
    set<int> s;
    Course course1(250, "C++ 2", 4, s);
    Course course2(150, "C++ 1", 4, s);
    Course course3(200, "Data Structures", 4, s);

// Call function CourseList::addCourse(Course) to add the three courses.
    cout << "Adding 250, 150, 200 to courseList1\n";
    courseList1.addCourse(course1);
    courseList1.addCourse(course2);
    courseList1.addCourse(course3);

// Call function CourseList::addCourse(int, string, int, set)
// to add three additional courses: 131, 272, 216
    cout << "Adding 131, 272, 216 to courseList1 (overloaded)\n";
    courseList1.addCourse(131, "Python 1", 4, s);
    courseList1.addCourse(272, "Java 2", 4, s);
    courseList1.addCourse(216, "Discrete Structure", 4, s);

// Create a string and use it as a parameter to
// call function CourseList::retrieveAllCourses().
    string result;
    courseList1.retrieveAllCourses(result);

// Print the string.
    cout << "courseList1:\n"
         << result << endl;

// Call CourseList::search(int) to search for 150.
    cout << "Searching for 150:\n";
    cout << (courseList1.searchCourse(150)
             ? "\tFound\n\n"
             : "\tNot Found\n\n");

// Create a string to store a course name, and
    string courseName;

// call CourseList::search(int, string) to
// retrieve the name of the course and print it.
    cout << "Searching for 150 and retrieving course name:\n";
    courseList1.searchCourse(150, courseName);
    cout << "\tCourse Name: " << courseName << endl << endl;

// Create an empty course by using the default constructor.
    Course course;

// Call function CourseList::search(int, Course) to
// retrieve the course and print the prefix, the number
// the name and the units.
    cout << "Searching for 150 and retrieving course object:\n";
    courseList1.searchCourse(150, course);
    cout << "\t" << courseList1.getPrefix() << course.getCourseNumber()
         << " - " << course.getCourseName()
         << " (" << course.getCourseUnits() << " units)\n\n";

// Call function CourseList::deleteCourse to delete 131.
    cout << "Deleting 131\n";
    courseList1.deleteCourse(131);
// Call function CourseList::deleteCourse to delete 272.
    cout << "Deleting 272\n";
    courseList1.deleteCourse(272);
// Call function CourseList::deleteCourse to delete 150.
    cout << "Deleting 150\n";
    courseList1.deleteCourse(150);
// Call function CourseList::deleteCourse to delete 250.
    cout << "Deleting 250\n";
    courseList1.deleteCourse(250);

// Print all courses to see what is left in the list.
    courseList1.retrieveAllCourses(result);
    cout << "courseList1:\n"
         << result << endl;
}

//int main() {
//    testCourseList();
//
//}

