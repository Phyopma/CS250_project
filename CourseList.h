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

    Node(const Course& newCourse, Node* newNext)
            : course(newCourse), next(newNext) {}

    Course getCourse() const { return course; }

    Node* getNext() const { return next; }

    void setCourse(const Course& newCourse) { course = newCourse; }

    void setNext(Node* newNext) { next = newNext; }

    ~Node() {}

private:
    Course course;
    Node* next;
};

class CourseList {
public:
// Default constructor
    CourseList() : first(nullptr), last(nullptr), count(0) {}

// Functions addCourse
    void addCourse(const Course&);

    void addCourse(int, const std::string&, int, const std::set<int>);

// Accessor functions
    std::string getPrefix() const;

    int getNumberOfCourses() const;

// Boolean functions
    bool isEmpty() const;

// Function seachCourses
    bool searchCourse(int) const;

    bool searchCourse(int, std::string&) const;

    bool searchCourse(int, Course&) const;

// Function deleteCourse
    void deleteCourse(int);

// Function retrieveAllCourses
    void retrieveAllCourses(std::string&) const;

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
    Node* getCourseLocation(int) const;

// Function addInOrder
    void insertInOrder(Node*);

// Helper functions for overloaded assignment operator
    void copyCallingObjIsEmpty(const CourseList&);

    void copyObjectsSameLength(const CourseList&);

    void copyCallingObjLonger(const CourseList&);

    void copyCallingObjShorter(const CourseList&);

    Node* first;
    Node* last;
    int count;
};

#endif