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
    if (otherCourseList.count == 0) {
        count = 0;
        // Need to point to nullptr to avoid pointing random memory
        first = nullptr;
        last = nullptr;
    } else {
        copyCallingObjIsEmpty(otherCourseList);
    }
}

// Definition overloaded assignment operator
CourseList& CourseList::operator=(const CourseList& otherCourseList) {
    if (otherCourseList.count == 0) {
        count = 0;
        // Need to point to nullptr to avoid pointing random memory
        first = nullptr;
        last = nullptr;
    } else if (count == 0) {
        copyCallingObjIsEmpty(otherCourseList);
    } else if (count == otherCourseList.count) {
        copyObjectsSameLength(otherCourseList);
    } else if (count < otherCourseList.count) {
        copyCallingObjShorter(otherCourseList);
    } else {
        copyCallingObjLonger(otherCourseList);
    }
    return *this;
}

// Definition function copyCallingObjIsEmpty
void CourseList::copyCallingObjIsEmpty(const CourseList& otherCourseList) {
    Node* otherCurrent = otherCourseList.first;
    first = new Node(otherCourseList.first->getCourse(), nullptr);

    Node* thisCurrent = first;
    otherCurrent = otherCurrent->getNext();

    while (otherCurrent != nullptr) {
        thisCurrent->setNext(new Node(otherCurrent->getCourse(), nullptr));
        thisCurrent = thisCurrent->getNext();   // next is set, not a
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
        otherCurrent = otherCurrent->getNext();
        thisCurrent = thisCurrent->getNext();
    }
}

// Definition function copyCallingObjLonger
void CourseList::copyCallingObjLonger(const CourseList& otherCourseList) {
    Node* thisCurrent = first;
    Node* otherCurrent = otherCourseList.first;

    while (otherCurrent != nullptr) {
        thisCurrent->setCourse(otherCurrent->getCourse());
        otherCurrent = otherCurrent->getNext();
        if (otherCurrent == nullptr)
            last = thisCurrent;
        thisCurrent = thisCurrent->getNext();
    }

    Node* tmp = thisCurrent;

    while (tmp != nullptr) {
        thisCurrent = thisCurrent->getNext();
        delete tmp;
        tmp = thisCurrent;
    }
    last->setNext(nullptr);
    count = otherCourseList.count;
}

// Definition function copyCallingObjShorter
void CourseList::copyCallingObjShorter(const CourseList& otherCourseList) {
    Node* thisCurrent = first;
    Node* otherCurrent = otherCourseList.first;

    while (thisCurrent != nullptr) {
        thisCurrent->setCourse(otherCurrent->getCourse());
        thisCurrent = thisCurrent->getNext();
        otherCurrent = otherCurrent->getNext();
    }

    thisCurrent = last;

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
    cout << endl << "Destructor called"
         << endl; // For testing, to delete later
}



