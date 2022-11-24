/*
    Team name

    Aung, Phyo Pyae Moe
    Hlaing, Yu Yu

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <set>

class Course {
public:
// Constructors

// default constructor
    Course() : courseNumber(0),
               courseName("N/A"),
               courseUnits(0) {}

// overload constructor
    Course(int otherCourseNumber, const std::string& otherCourseName,
           int otherCourseUnits, std::set<int>& otherPrereqs);

// Accessor functions
    const std::string& getCourseName() const;

    int getCourseNumber() const;

    int getCourseUnits() const;

    const std::set<int>& getCoursePrereqs() const;

    const Course& getCourse() const;

    static std::string getPrefix();

// Mutator functions
    void setCourseName(const std::string&);

    void setCourseNumber(int);

    void setCourseUnits(int);

    void setPrereqs(int[], int);

// Destructor
    ~Course() = default;

private:
    int courseNumber;
    std::string courseName;
    int courseUnits;
    std::set<int> prereqs;
    static const std::string PREFIX;
};

#endif


