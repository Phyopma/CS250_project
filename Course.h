/*
(name header)
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
    Course(int otherCourseNumber, const std::string &otherCourseName,
           int otherCourseUnits, std::set<int> &otherPrereqs) :
            courseNumber(otherCourseNumber),
            courseName(otherCourseName),
            courseUnits(otherCourseUnits),
            prereqs(otherPrereqs) {}

// Accessor functions
    std::string &getCourseName() const;

    int getCourseNumber() const;

    int getCourseUnits() const;

    std::set<int> &getCoursePrereqs() const;

    Course &getCourse() const;

    static std::string getPrefix();

// Mutator functions
    void setCourseName(std::string &);

    void setCourseNumber(int);

    void setCourseUnits(int);

    void setPrereqs(int[], int);

// Destructor
    ~Course();

private:
    int courseNumber;
    std::string courseName;
    int courseUnits;
    std::set<int> prereqs;
    static const std::string PREFIX;
};

#endif


