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
    insertInOrder(new Node(newCourse, nullptr));
}

// Definition function addCourse
void CourseList::addCourse(int courseNumber, const string& courseName,
                           int courseUnits, const set<int> prereqs) {
    Course newCourse(courseNumber, courseName, courseUnits, prereqs);
    insertInOrder(new Node(newCourse, nullptr));
}

// Definition function getPrefix
string CourseList::getPrefix() const {
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
bool CourseList::searchCourse(int courseNumber) const {
    return CourseList::getCourseLocation(courseNumber) != nullptr;
}

// Definition function searchCourse (courseNumber, courseName)
// Assume list is non-empty.
bool CourseList::searchCourse(int courseNumber, string& courseName) const {
    Node* result = CourseList::getCourseLocation(courseNumber);

    // Retrieve course name only if it is found
    if (result != nullptr) {
        courseName = result->getCourse().getCourseName();
        return true;
    }

    return false;
}

// Definition function searchCourse (courseNumber, course)
// Assume list is non-empty.
bool CourseList::searchCourse(int courseNumber, Course& course) const {
    Node* result = CourseList::getCourseLocation(courseNumber);

    // Retrieve course only if it is found
    if (result != nullptr) {
        course = result->getCourse();
        return true;
    }

    return false;
}

// Definition deleteCourse
// Assume list is non-empty.
// Assume course is in the list.
void CourseList::deleteCourse(int courseNumber) {
    Node* current = first;
    Node* previous = nullptr;
    bool isFound = false;

    // searching Node with course Number
    while (current != nullptr && !isFound) {
        if (current->getCourse().getCourseNumber() == courseNumber) {
            isFound = true;
        } else {
            previous = current;
            current = current->getNext();
        }
    }

    if (isFound) {
        // deleting first node
        if (current == first) {
            first = first->getNext();
        } else if (current == last) {
            last = previous;
            last->setNext(nullptr);
        } else {
            previous->setNext(current->getNext());
        }

        delete current;
        current = nullptr;

        --count;
    }

}

// Definition retrieveAllCourses
// Assume list is non-empty.
void CourseList::retrieveAllCourses(string& result) const {
    Node* current = first;
    ostringstream output;

    while (current != nullptr) {
        Course course = current->getCourse();
        output << getPrefix() << course.getCourseNumber() <<
               " - " << course.getCourseName() << endl;
        current = current->getNext();
    }

    result = output.str();
}

// Definition clearList
void CourseList::clearList() {
    // No need to clear an empty list
    if (count != 0) {
        Node* current = first;
        Node* tmp = first;

        // traversing the list
        while (current != nullptr) {
            current = current->getNext();
            delete tmp;
            tmp = current;
        }

        first = nullptr;
        last = nullptr;
        count = 0;
    }
}

// Definition function getCourseLocation
Node* CourseList::getCourseLocation(int courseNumber) const {
    Node* current = first;
    bool isFound = false;

    // Searching for the course
    while (current != nullptr && !isFound) {
        if (current->getCourse().getCourseNumber() == courseNumber) {
            isFound = true;
        } else {
            current = current->getNext();
        }
    }

    return current;
}






