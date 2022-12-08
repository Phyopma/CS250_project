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
    // If parameter object is empty
    if (otherCourseList.count == 0) {
        // Need to point to nullptr to avoid pointing random memory
        first = nullptr;
        last = nullptr;
        count = 0;
    } else {
        copyCallingObjIsEmpty(otherCourseList);
    }
}

// Definition overloaded assignment operator
CourseList& CourseList::operator=(const CourseList& otherCourseList) {
    // If the objects are the same
    if (this == &otherCourseList) {
        cerr << "Attempted assignment to itself." << endl;
    } else if (otherCourseList.count == 0) {
        clearList();
    } else if (count == 0) {
        copyCallingObjIsEmpty(otherCourseList);
    } else if (count == otherCourseList.count) {
        copyObjectsSameLength(otherCourseList);
    } else if (count > otherCourseList.count) {
        copyCallingObjLonger(otherCourseList);
    } else {
        copyCallingObjShorter(otherCourseList);
    }
    return *this;
}

// Definition function copyCallingObjIsEmpty
void CourseList::copyCallingObjIsEmpty(const CourseList& otherCourseList) {
    // Create new node for first
    Node* otherCurrent = otherCourseList.first;
    first = new Node(otherCurrent->getCourse(), nullptr);

    otherCurrent = otherCurrent->getNext();
    Node* thisCurrent = first;

    // Create new nodes for each course
    while (otherCurrent != nullptr) {
        thisCurrent->setNext(new Node(otherCurrent->getCourse(), nullptr));
        // The new node created is set to thisCurrent
        thisCurrent = thisCurrent->getNext();
        otherCurrent = otherCurrent->getNext();
    }

    last = thisCurrent;
    count = otherCourseList.count;
}

// Definition function copyObjectsSameLength
void CourseList::copyObjectsSameLength(const CourseList& otherCourseList) {
    Node* thisCurrent = first;
    Node* otherCurrent = otherCourseList.first;

    // Copy courses to the existing nodes
    while (otherCurrent != nullptr) {
        thisCurrent->setCourse(otherCurrent->getCourse());
        otherCurrent = otherCurrent->getNext();
        thisCurrent = thisCurrent->getNext();
    }
}

// Definition function copyCallingObjLonger
void CourseList::copyCallingObjLonger(const CourseList& otherCourseList) {
    Node* thisCurrent = first;
    Node* otherCurrent = otherCourseList.first;
    Node* thisPrev = nullptr;

    // Copy courses to the existing nodes
    while (otherCurrent != nullptr) {
        thisCurrent->setCourse(otherCurrent->getCourse());
        otherCurrent = otherCurrent->getNext();
        thisPrev = thisCurrent;
        thisCurrent = thisCurrent->getNext();
    }

    last = thisPrev;
    last->setNext(nullptr);

    thisPrev = thisCurrent;

    // Delete the remaining extra nodes
    while (thisPrev != nullptr) {
        thisCurrent = thisCurrent->getNext();
        delete thisPrev;
        thisPrev = thisCurrent;
    }

    count = otherCourseList.count;
}

// Definition function copyCallingObjShorter
void CourseList::copyCallingObjShorter(const CourseList& otherCourseList) {
    Node* thisCurrent = first;
    Node* otherCurrent = otherCourseList.first;

    // Copy courses to the existing nodes
    while (thisCurrent != nullptr) {
        thisCurrent->setCourse(otherCurrent->getCourse());
        thisCurrent = thisCurrent->getNext();
        otherCurrent = otherCurrent->getNext();
    }

    thisCurrent = last;

    // Create new nodes for the remainding courses
    while (otherCurrent != nullptr) {
        thisCurrent->setNext(new Node(otherCurrent->getCourse(), nullptr));
        thisCurrent = thisCurrent->getNext();
        otherCurrent = otherCurrent->getNext();
    }

    last = thisCurrent;
    count = otherCourseList.count;
}

// Destructor
CourseList::~CourseList() {
    if (count != 0) {
        clearList();
    }
}



