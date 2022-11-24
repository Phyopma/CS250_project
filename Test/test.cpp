#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Course.h"
using namespace std;

TEST_CASE("default constructor test") {
    Course c;
    CHECK_EQ(c.getCourseNumber(), 0);
    CHECK_EQ(c.getCoursePrereqs().size(), 0);
    CHECK_EQ(c.getCourseName(), "N/A");
    CHECK_EQ(c.getCoursePrereqs().size(), 0);
}

//
TEST_CASE("constructor test") {
    set<int> s = {1, 2};
    Course c(250, "C++ Programming 2", 3, s);
    CHECK_EQ(c.getCoursePrereqs().size(), 2);
    CHECK_EQ(c.getCourseNumber(), 250);
    CHECK_EQ(c.getCourseName(), "C++ Programming 2");
    CHECK_EQ(c.getCourseUnits(), 3);
    CHECK_EQ(c.getCoursePrereqs(), s);
}

TEST_CASE("getCourseName test") {
    set<int> s = {1, 2};
    Course c(250, "C++ Programming 2", 3, s);
    CHECK_EQ(c.getCourseName(), "C++ Programming 2");
}

TEST_CASE("getCourseNumber test") {
    set<int> s = {1, 2};
    Course c(250, "C++ Programming 2", 3, s);
    CHECK_EQ(c.getCourseNumber(), 250);
}

TEST_CASE("getCourseUnits test") {
    set<int> s = {1, 2};
    Course c(250, "C++ Programming 2", 3, s);
    CHECK_EQ(c.getCourseUnits(), 3);
}

TEST_CASE("getCoursePrereqs test") {
    set<int> s = {1, 2};
    Course c(250, "C++ Programming 2", 3, s);
    CHECK_EQ(c.getCoursePrereqs(), s);
}

TEST_CASE("getCourse test") {
    set<int> s = {1, 2};
    Course c(250, "C++ Programming 2", 3, s);
    Course c1 = c.getCourse();
    CHECK_EQ(&c1, &c);
}

TEST_CASE("getPrefix test") {
    CHECK_EQ(Course::getPrefix(), "CS A");
}

TEST_CASE("setCourseName test") {
    Course c;
    c.setCourseName("Programming");
    CHECK_EQ(c.getCourseName(), "Programming");
}

TEST_CASE("setCourseNumber test") {
    Course c;
    c.setCourseNumber(250);
    CHECK_EQ(c.getCourseNumber(), 250);
}

TEST_CASE("setCourseUnits test") {
    Course c;
    c.setCourseUnits(4);
    CHECK_EQ(c.getCourseUnits(), 4);
}

//TEST_CASE("setCoursePrereqs test") {
//    int array[] = {170, 150, 250};
//    set<int> s = {170, 150, 250};
//    Course c;
//    c.setPrereqs(array, 3);
//    CHECK_EQ(c.getCoursePrereqs(), s);
//}
