#include "CourseList.h"
#include "TestingCases.h"
#include "Interface.h"

#include <iostream>

using namespace std;

int main() {
    /********************************************************
    *	TESTING database
    ********************************************************/
    CourseList courseList;
    createCourseList(courseList);
    displayMenu();
    if (courseList.isEmpty()) {
        cerr << "The database is empty." << endl;
    } else {
        processChoice(courseList);
    }

    cout << "\n";
    return 0;

}