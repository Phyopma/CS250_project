#include "Interface.h"

#include <iostream>
#include <map>
#include <iomanip>
#include <sstream>

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
         << "    5: Calculate GPA\n"
         << "    6: To exit\n";
}

void searchRequest(const CourseList&);
void deleteRequest(CourseList&);
void getBackToMenu(bool&);
void calculateGPA(const CourseList&);
void invalidInputHandler(const CourseList&);
void displayCourses(const CourseList&);

void processChoice(CourseList& courseList) {
    bool isTerminated = false;
    while (!isTerminated) {
        cout << "\nChoose one of the operations from the Main Menu : ";
        int option;
        cin >> option;

        if (cin.fail()) {
            cout << "Please type a number." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),
                       '\n');
        } else {
            switch (option) {
                case 1: {
                    cout << "\nOption 1: Search Course" << endl;
                    searchRequest(courseList);
                    break;
                }

                case 2: {
                    cout << "\nOption 2: Add course" << endl;
                    cout << "\nPlease contact the Curriculum Committee to "
                            "start the process of adding a course."
                         << endl;
                    getBackToMenu(isTerminated);
                    break;
                }

                case 3: {
                    cout << "\nOption 3: Delete course" << endl;
                    deleteRequest(courseList);
                    break;
                }

                case 4: {
                    cout << "\nOption 4: Display all courses" << endl;
                    displayCourses(courseList);
                    getBackToMenu(isTerminated);
                    break;
                }

                case 5: {
                    cout << "\nOption 5: Calculate GPA" << endl;
                    calculateGPA(courseList);
                    break;
                }

                case 6: {
                    isTerminated = true;
                    cout << "\nOption 6: Exit" << endl;
                    break;
                }

                default: {
                    cout << "\nInvalid Selection" << endl;
                    displayMenu();
                    break;
                }
            }
        }
        if (!isTerminated) {
            cout << endl;
            displayMenu();
        }
    }

    cout << "Thank you. Goodbye." << endl;
    cout << "\nEnter any key to exit." << endl;
    string s;
    cin >> s;
}

void searchRequest(const CourseList& courseList) {
    bool back = false;

    while (!back) {
        cout << "\nEnter the course number (150, 200, etc) : ";
        int courseNumber;
        cin >> courseNumber;

        if (cin.fail()) {
            invalidInputHandler(courseList);
        } else {
            Course tmpCourse;
            if (!courseList.searchCourse(courseNumber, tmpCourse)) {
                cout
                        << "The course number you searched is not in "
                           "the list!!"
                        << endl;
            } else {
                cout << "\t" << courseList.getPrefix() << tmpCourse
                        .getCourseNumber()
                     << " - " << tmpCourse.getCourseName()
                     << " (" << tmpCourse.getCourseUnits() << " units)\n"
                     << "\tPrerequisites :";
                const set<int>& prereqs = tmpCourse.getCoursePrereqs();
                if (prereqs.empty()) {
                    cout << " None\n";
                } else {
                    for (int i: prereqs) {
                        cout << " " << i;
                    }
                    cout << endl;
                }
            }

            string searchOption;
            do {
                cout << endl;
                cout << R"(Enter "b" to go back or "r" to retry again)"
                     << " : ";

                cin >> searchOption;
                if (searchOption == "b") {
                    back = true;
                }
            } while (searchOption != "b" && searchOption != "r");
        }
    }
}

void deleteRequest(CourseList& courseList) {
    bool back = false;

    while (!back) {
        cout << "\nEnter the course number to be deleted (150, 200, etc )"
                " : ";
        int courseNumber;
        cin >> courseNumber;

        if (cin.fail()) {
            invalidInputHandler(courseList);
        } else {

            if (!courseList.searchCourse(courseNumber)) {
                cout << "The course number you searched is not in the "
                        "list!!"
                     << endl;
            } else {
                string confirmation;
                do {
                    cout << "\nAre you sure to delete this course ("
                         << courseList.getPrefix() << courseNumber
                         << ")?\n";
                    cout << R"(Enter "Y" to continue or "N" to abort)"
                         << " : ";
                    cin >> confirmation;
                    if (confirmation == "Y") {
                        courseList.deleteCourse(courseNumber);
                        cout << "Successfully deleted" << endl;
                    }
                } while (confirmation != "Y" && confirmation != "N");
            }

            string searchOption;
            do {
                cout << endl;
                cout << R"(Enter "b" to go back or "d" to delete again)";
                cout << " : ";
                cin >> searchOption;
                if (searchOption == "b") {
                    back = true;
                }
            } while (searchOption != "b" && searchOption != "d");
        }
    }
}

void getBackToMenu(bool& isTerminated) {
    string searchOption;
    do {
        cout << endl;
        cout << R"(Enter "b" to go back or "e" to exit)";
        cout << " : ";

        cin >> searchOption;
        if (searchOption == "e") {
            isTerminated = true;
        }
    } while (searchOption != "b" && searchOption != "e");
}

void calculateGPA(const CourseList& courseList) {
    bool done = false;
    int totalUnits = 0;
    double totalGrade = 0;
    set<int> addedCourses;
    ostringstream display;
    display << setw(20) << left << "Course Number" << setw(40) <<
            "Course Name";
    display << setw(10) << right << "Units" << setw(10) << "Grade"
            << endl;
    while (!done) {
        int courseNumber;
        cout << "\nEnter the course number : ";
        cin >> courseNumber;

        if (cin.fail()) {
            invalidInputHandler(courseList);
        } else {
            Course course;
            const string gradeLetters = "A-B-C-D-F";
            const map<char, double> gradeLetterToPoint = {
                    {'A', 4.0},
                    {'B', 3.0},
                    {'C', 2.0},
                    {'D', 1.0},
                    {'F', 0.0}
            };
            if (addedCourses.find(courseNumber) != addedCourses.end()) {
                cout << "\nAlready added!!" << endl;
                continue;
            } else if (!courseList.searchCourse(courseNumber, course)) {
                cout
                        << "The course number you searched is not in "
                           "the list!!"
                        << endl;
            } else {
                string grade;
                do {
                    cout << "Enter letter grade (A B C D F(Fail)) : ";
                    cin >> grade;
                } while (gradeLetters.find(grade[0]) == string::npos);

                if (grade[0] != 'F') {
                    addedCourses.insert(course.getCourseNumber());
                } // fail must retake again

                display << setw(20) << left << course.getCourseNumber()
                        <<
                        setw(40) << course.getCourseName();
                display << setw(10) << right << course.getCourseUnits()
                        << setw(10) << grade[0] << "\t"
                        << (grade[0] == 'F' ?
                            "Fail *" : "") << endl;

                totalUnits += course.getCourseUnits();
                totalGrade += course.getCourseUnits() *
                              gradeLetterToPoint.at(grade[0]);
                string input;
                do {
                    cout << endl;
                    cout << R"(Enter "a" to add more or "c" to calculate)";
                    cout << " : ";
                    cin >> input;
                    if (input == "c") {
                        done = true;
                        cout << "\nTaken courses : " << endl;
                        cout << display.str() << endl;
                        cout << "Total units taken : " << totalUnits;
                        cout << fixed << setprecision(2);
                        cout << "\nAverage gpa : " << totalGrade /
                                                      totalUnits << endl;
                    }
                } while (input != "a" && input != "c");
            }
        }
    }
}

void invalidInputHandler(const CourseList& courseList) {
    cout << "\nInvalid Input. Enter a course number from the following "
            "list." << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    displayCourses(courseList);
}

void displayCourses(const CourseList& courseList) {
    string output;
    courseList.retrieveAllCourses(output);
    cout << "\n" << output;
}