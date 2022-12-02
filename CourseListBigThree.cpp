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
    if (this == &otherCourseList) {
        cerr << "Attempted assignment to itself" << endl;
    } else {
        if (otherCourseList.count == 0) {
            clearList();
        } else if (count == 0) {
            copyCallingObjIsEmpty(otherCourseList);
        } else if (count == otherCourseList.count) {
            copyObjectsSameLength(otherCourseList);
        } else if (count < otherCourseList.count) {
            copyCallingObjShorter(otherCourseList);
        } else {
            copyCallingObjLonger(otherCourseList);
        }
    }
    return *this;
}

// Definition function copyCallingObjIsEmpty
void CourseList::copyCallingObjIsEmpty(const CourseList& otherCourseList) {
    Node* otherCurrent = otherCourseList.first;
    first = new Node(otherCurrent->getCourse(), nullptr);

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
    Node* thisPrev = nullptr;

    while (otherCurrent != nullptr) {
        thisCurrent->setCourse(otherCurrent->getCourse());
        otherCurrent = otherCurrent->getNext();
        thisPrev = thisCurrent;
        thisCurrent = thisCurrent->getNext();
    }

    last = thisPrev;
    last->setNext(nullptr);

    thisPrev = thisCurrent;

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



