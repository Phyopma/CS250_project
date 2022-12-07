#include "Interface.h"

#include <iostream>

using namespace std;

int TOTAL_CLASSES;

void displayMenu() {
    cout
            << "**************************************************************\n"
            << "                          MAIN MENU\n"
            << "**************************************************************\n";
    cout << "\nSelect one of the following:\n\n"
         << "    1: Search course\n"
         << "    2: Add course\n"
         << "    3: Delete course\n"
         << "    4: Display all courses\n"
         << "    5: (your choice)\n"
         << "    6: To exit\n";
}

void option1(CourseList&);

void processChoice(CourseList& courseList) {
    // Write your code in here...
    bool isTerminated = false;
    while (!isTerminated) {
        displayMenu();
        int option;
        cin >> option;
        if (cin.fail()) {
            cout << "Err Message" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch (option) {
            case 1: {
                option1(courseList);
                break;
            }
            case 2:
                cout << "Option 2" << endl;
                break;
            case 3:
                cout << "Option 3" << endl;
                break;
            case 4:
                cout << "Option 4" << endl;
                break;
            case 5:
                cout << "Option 5" << endl;
                break;
            case 6:
                isTerminated = true;
                cout << "Option 6" << endl;
                break;
            default:
                cout << "Option 7" << endl;
                break;
        }
    }
}

void option1(CourseList& courseList) {
    bool back = false;
    cout << "Option 1: Search Course" << endl;
    while (!back) {
        cout << "Enter the course number (150, 200, etc ): ";
        int courseNumber;
        cin >> courseNumber;
        if (cin.fail()) {
            cout << "Err Message" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        Course tmpCourse;
        if (!courseList.searchCourse(courseNumber, tmpCourse)) {
            cout << "The course number you searched is not in "
                    "the list" << endl;
        } else {
            cout << "\t" << courseList.getPrefix() << tmpCourse
                    .getCourseNumber()
                 << " - " << tmpCourse.getCourseName()
                 << " (" << tmpCourse.getCourseUnits() << " units)\n\n";
        }
        string searchOption;
        do {
            cout << "To go back, enter \"b\"" << endl;
            cout << "To retry again, enter \"r\"" << endl;

            cin >> searchOption;
            if (searchOption == "b") {
                back = true;
            }
        } while (searchOption != "b" && searchOption != "r");

    }

}



