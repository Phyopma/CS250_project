/*
    Coffee Addicts

    Aung, Phyo Pyae Moe
    Hlaing, Yu Yu

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#include "CourseList.h"

#include "CourseList.h"
#include <iostream>
#include <sstream>

using namespace std;

// Definition function addCourse
void CourseList::addCourse(const Course& newCourse) {
    CourseList::insertInOrder(new Node(newCourse, nullptr));
}

// Definition function addCourse
void CourseList::addCourse(int courseNumber, const string& courseName, int courseUnits, const std::set<int> prereqs) {
    Course newCourse(courseNumber, courseName, courseNumber, prereqs);
    CourseList::insertInOrder(new Node(newCourse, nullptr));
}

// Definition function getPrefix
std::string CourseList::getPrefix() const {
    return Course::getPrefix();
}

// Definition function getNumberOfCourses
int CourseList::getNumberOfCourses() const {
    return count;
}

// Definition function isEmpty
bool CourseList::isEmpty() const {
    return (count == 0);
}

// Definition function searchCourse (courseNumber)
// Assume list is non-empty.
Node* CourseList::searchCourse(int courseNumber) const {
    return CourseList::getCourseLocation(courseNumber);
}

// Definition function searchCourse (courseNumber, courseName)
// Assume list is non-empty.
Node* CourseList::searchCourse(int courseNumber, string& courseName) const {
    Node* result = CourseList::getCourseLocation(courseNumber);
    courseName = result->getCourse().getCourseName();
    return result;
}

// Definition function searchCourse (courseNumber, course)
// Assume list is non-empty.
Node* CourseList::searchCourse(int courseNumber, Course& course) const {
    Node* result = CourseList::getCourseLocation(courseNumber);
    course = result->getCourse();
    return result;
}

// Definitiion deleteCourse
// Assume list is non-empty.
// Assume course is in the list.
void CourseList::deleteCourse(int courseNumber) {
    Node* current = first;
    Node* previous = nullptr;
    bool isFound = false;
    // searching Node with course Number
    while (current != nullptr && !isFound) {
        if (current->getCourse().getCourseNumber() == courseNumber) {
            isFound = !isFound;
        } else {
            previous = current;
            current = current->getNext();
        }
    }
    if (isFound) {
        previous->setNext(current->getNext());
        count--;
    }

}

// Definition retrieveAllCourses
// Assume list is non-empty.
void CourseList::retrieveAllCourses(string& result) const {
    Node* current = first;
    ostringstream output;
    while (current != nullptr) {
        Course course = current->getCourse();
        output << getPrefix() << " " << course.getCourseNumber() <<
               " - " << course.getCourseName() << " " << course.getCourseUnits() << endl;
        current = current->getNext();
    }
    result = output.str();
}

// Definition clearList
void CourseList::clearList() {
    count = 0;
    Node* current = first;
    // transversing the list
    while (current != nullptr) {
        Node* tmp = current;
        current = current->getNext();
        delete tmp;
        tmp = nullptr;
    }
    first = nullptr;
    last = nullptr;
}

// Definition function getCourseLocation
Node* CourseList::getCourseLocation(int courseNumber) const {
    Node* current = first;
    bool isFound = false;
    while (current != nullptr && !isFound) {
        if (current->getCourse().getCourseNumber() == courseNumber) {
            isFound = !isFound;
        } else {
            current = current->getNext();
        }
    }
    return current;
}






