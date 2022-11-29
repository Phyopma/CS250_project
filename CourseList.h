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
    CourseList() : count(0);

// Functions addCourse
    void addCourse(const Course&&);

    void addCourse(int, const std::string&, double, const std::set<int>);

// Accessor functions
    std::string getPrefix() const;

    int getNumberOfCourses() const;

// Boolean functions
    bool isEmpty() const;

// Fucntion seachCourses
    Node *searchCourse(int) const;

    Node *searchCourse(int, std::string&) const;

// Function deleteCourse
    void deleteCourse(int);

// Function retrieveAllCourses
    void retrieveAllCourses(const std::string&) const;
// Function clearList
/********************* THE BIG THREE *********************/
// Copy constructor
// Overloaded assignment operator
// Destructor
private:
// Function getCourseLocation
// Function addInOrder
// Helper functions for overloaded assignment operator
    Node *first;
    Node *last;
    int count;
};

#endif