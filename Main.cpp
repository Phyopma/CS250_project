#include "CourseList.h"
#include "TestingCases.h"
#include "Interface.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    /********************************************************
    *	TESTING database
    ********************************************************/
    CourseList courseList;
    createCourseList(courseList);
    if (courseList.isEmpty()) {
        cerr << "The database is empty." << endl;
    } else {
        processChoice(courseList);
    }

    cout << "\n";
    return 0;

}