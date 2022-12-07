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

void option3(CourseList&);

void getBackToMenu(bool&);

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
            case 2: {
                cout << "Option 2: Add course" << endl;
                cout << "Please contact the Curriculum Committee to start "
                        "the process of adding a course.contact the "
                        "Curriculum Committee to start the process of "
                        "adding a course." << endl;
                getBackToMenu(isTerminated);
                break;

            }

            case 3:
                option3(courseList);
                break;
            case 4: {
                cout << "Option 4: Display all courses" << endl;
                string output;
                courseList.retrieveAllCourses(output);
                cout << output << endl;
                getBackToMenu(isTerminated);
                break;
            }
            case 5:
                cout << "Option 5" << endl;
                break;
            case 6:
                isTerminated = true;
                cout << "Option 6: Exit" << endl;
                break;
            default:
                cout << "Invalid Selection" << endl;
                break;
        }
    }
    cout << "Good bye msg" << endl;
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

void getBackToMenu(bool& isTerminated) {
    string searchOption;
    do {
        cout << "To go back, enter \"b\"" << endl;
        cout << "To exit, enter \"e\"" << endl;

        cin >> searchOption;
        if (searchOption == "e") {
            isTerminated = true;
        }
    } while (searchOption != "b" && searchOption != "e");
}

void option3(CourseList& courseList) {
    bool back = false;
    cout << "Option 3: Delete course" << endl;
    while (!back) {
        cout << "Enter the course number to be deleted (150, 200, etc ): ";
        int courseNumber;
        cin >> courseNumber;
        if (cin.fail()) {
            cout << "Err Message" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (!courseList.searchCourse(courseNumber)) {
            cout << "The course number you searched is not in "
                    "the list" << endl;
        } else {
            string confirmation;
            do {
                cout << "Are you sure to delete this course" << courseList
                        .getPrefix() << courseNumber << endl;
                cout << "\"Y\" to continue. \"N\" to abort." << endl;
                cin >> confirmation;
                if (confirmation == "Y") {
                    courseList.deleteCourse(courseNumber);
                    cout << "Successfully deleted" << endl;
                }
            } while (confirmation != "Y" && confirmation != "N");
        }

        string searchOption;
        do {
            cout << "To go back, enter \"b\"" << endl;
            cout << "To delete another course or retry again, enter \"r\""
                 << endl;
            cin >> searchOption;
            if (searchOption == "b") {
                back = true;
            }
        } while (searchOption != "b" && searchOption != "r");

    }
}


