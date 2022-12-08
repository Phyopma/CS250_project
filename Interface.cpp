#include "Interface.h"

#include <iostream>
#include "map"

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
        cout << "\nChoose options 1-6: "; // TODO: Please change
        int option;
        cin >> option;

        if (cin.fail()) {
            cout << "Please type a number." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    }

    cout << "Thank you. Good bye." << endl; // TODO: Please Change
}

void searchRequest(const CourseList& courseList) {
    bool back = false;

    while (!back) {
        cout << "\nEnter the course number (150, 200, etc ): ";
        int courseNumber;
        cin >> courseNumber;

        if (cin.fail()) {
            invalidInputHandler(courseList);
        } else {
            Course tmpCourse;
            if (!courseList.searchCourse(courseNumber, tmpCourse)) {
                cout
                        << "\nThe course number you searched is not in "
                           "the list!!"
                        << endl;
            } else {
                cout << "\t" << courseList.getPrefix() << tmpCourse
                        .getCourseNumber()
                     << " - " << tmpCourse.getCourseName()
                     << " (" << tmpCourse.getCourseUnits() << " units)\n";
            }

            string searchOption;
            do {
                cout << endl;
                cout << R"(Enter "b" to go back or "r" to retry again)"
                     << "\t:";

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
                ": ";
        int courseNumber;
        cin >> courseNumber;

        if (cin.fail()) {
            invalidInputHandler(courseList);
        } else {

            if (!courseList.searchCourse(courseNumber)) {
                cout << "\nThe course number you searched is not in the "
                        "list!!"
                     << endl;
            } else {
                string confirmation;
                do {
                    cout << "\nAre you sure to delete this course"
                         << courseList
                                 .getPrefix() << courseNumber << endl;
                    cout << R"(Enter "Y" to continue or "N" to abort.)"
                         << "\t:";
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
                cout << "\t:";
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
        cout << "\t:";

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

    while (!done) {
        int courseNumber;
        cout << "\nEnter course number: ";
        cin >> courseNumber;

        if (cin.fail()) {
            invalidInputHandler(courseList);
        } else {
            Course course;
            const string gradeLetters = "A-B-C-D-E-F";
            const map<char, double> gradeLetterToPoint = {
                    {'A', 4.0},
                    {'B', 3.0},
                    {'C', 2.0},
            };
            if (addedCourses.find(courseNumber) != addedCourses.end()) {
                cout << "\nAlready added!!" << endl;
                continue;
            } else if (!courseList.searchCourse(courseNumber, course)) {
                cout
                        << "\nThe course number you searched is not in "
                           "the list!!"
                        << endl;
            } else {
                string grade;
                do {
                    cout << "Enter letter grade (A B C)\t: ";
                    cin >> grade;
                } while (gradeLetters.find(grade[0]) == string::npos);

                addedCourses.insert(course.getCourseNumber());
                totalUnits += course.getCourseUnits();
                totalGrade += course.getCourseUnits() *
                              gradeLetterToPoint.at(grade[0]);
                string input;
                do {
                    cout << endl;
                    cout << R"(Enter "a" to add more or "c" to calculate)";
                    cout << "\t: ";
                    cin >> input;
                    if (input == "c") {
                        done = true;
                        cout << "Taken courses\t: " << endl;
                        for (int i: addedCourses) {
                            string display;
                            courseList.searchCourse(i, display);
                            cout << "\t" << display << endl;
                        }
                        cout << "\nAverage gpa : " << totalGrade /
                                                      totalUnits << endl;
                    }
                } while (input != "a" && input != "c");
            }
        }
    }
}

void invalidInputHandler(const CourseList& courseList) {
    cout << "\nInvalid Input." << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    displayCourses(courseList);
}

void displayCourses(const CourseList& courseList) {
    string output;
    courseList.retrieveAllCourses(output);
    cout << output << endl;
}