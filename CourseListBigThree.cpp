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


// Copy constructor
CourseList::CourseList(const CourseList& otherCourseList) {

}

// Definition overloaded assignment operator
CourseList& CourseList::operator=(const CourseList&) {
    return this;
}

// Definition function copyCallingObjIsEmpty
void CourseList::copyCallingObjIsEmpty(const CourseList& otherCourseList) {
    Node* otherCurrent = otherCourseList.first;
    first = new Node(otherCourseList.first->getCourse(), nullptr);

    Node* thisCurrent = first;
    otherCurrent = otherCurrent->getNext();

    while (otherCurrent != nullptr) {
        thisCurrent->setNext(new Node(otherCurrent->getCourse(), nullptr));
        thisCurrent = thisCurrent->getNext();   // next is set, not a nullptr
        otherCurrent = otherCurrent->getNext();
    }

    last = thisCurrent;
    count = otherCourseList.count;
}

// Definition function copyObjectsSameLength
void CourseList::copyObjectsSameLength(const CourseList& otherCourseList) {
    Node* thisCurrent = first;
    Node* otherCurrent = otherCourseList.first;

    while (otherCurrent != nullptr) {
        thisCurrent->setCourse(otherCurrent->getCourse());
        thisCurrent = thisCurrent->getNext();
        otherCurrent = otherCurrent->getNext();
    }
}

// Definition function copyCallingObjLonger
void CourseList::copyCallingObjLonger(const CourseList& otherCourseList) {
    Node* thisCurrent = first;
    Node* otherCurrent = otherCourseList.first;

    while (otherCurrent != nullptr) {
        thisCurrent->setCourse(otherCurrent->getCourse());
        thisCurrent = thisCurrent->getNext();
        otherCurrent = otherCurrent->getNext();
    }

    Node* next;
    while (thisCurrent != nullptr) {
        next = thisCurrent->getNext();
        delete thisCurrent;
        thisCurrent = next;
    }
    // need to set last
    count = otherCourseList.count;
}

// Definition function copyCallingObjShorter
void CourseList::copyCallingObjShorter(const CourseList&) {

}

// Destructor
CourseList::~CourseList() {

}


