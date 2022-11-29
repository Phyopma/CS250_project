/*
    Coffee Addicts

    Aung, Phyo Pyae Moe
    Hlaing, Yu Yu

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"
#include <string>
#include <set>

class Node {
public:
    Node() : course(), next(nullptr) {}

    Node(const Course& newCourse, Node *newNext)
            : course(newCourse), next(newNext) {}

    Course getCourse() const { return course; }

    Node *getNext() const { return next; }

    void setCourse(const Course& newCourse) { course = newCourse; }

    void setNext(Node *newNext) { next = newNext; }

    ~Node() {}

private:
    Course course;
    Node *next;
};

class CourseList {
public:
// Default constructor
// Functions addCourse
// Accessor functions
// Boolean functions
    bool isEmpty() const;

    bool searchCourse(int) const;

// Function deleteCourse
    void deleteCourse(int);

// Function retrieveAllCourses
    std::string& retrieveAllCourses() const;

// Function clearList
    void clearList();

/********************* THE BIG THREE *********************/
// Copy constructor
    CourseList(const CourseList&);

// Overloaded assignment operator
    CourseList& operator=(const CourseList&);

// Destructor
    ~CourseList();

private:
// Function getCourseLocation
// Function addInOrder
// Helper functions for overloaded assignment operator
    Node *first;
    Node *last;
    int count;
};

#endif