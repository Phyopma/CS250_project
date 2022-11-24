/*
    Team name

    Aung, Phyo Pyae Moe
    Hlaing, Yu Yu

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "Course.h"

using namespace std;

TEST_CASE("default constructor test") {
    Course c;
    CHECK_EQ(c.getCourseNumber(), 0);
    CHECK_EQ(c.getCoursePrereqs().size(), 0);
    CHECK_EQ(c.getCourseName(), "N/A");
    CHECK_EQ(c.getCoursePrereqs().size(), 0);
}

//
TEST_CASE("constructor") {
    set<int> s = {1, 2};
    Course c(250, "C++ Programming 2", 3, s);
    CHECK_EQ(c.getCoursePrereqs().size(), 2);
    CHECK_EQ(c.getCourseNumber(), 250);
    CHECK_EQ(c.getCourseName(), "C++ Programming 2");
    CHECK_EQ(c.getCourseUnits(), 3);
    CHECK_EQ(c.getCoursePrereqs(), s);
    CHECK_EQ(&c, &(c.getCourse()));
}

TEST_CASE("static method test") {
    CHECK_EQ(Course::getPrefix(), "CS A");
}

TEST_CASE("setter methods test") {
    Course c;
    c.setCourseName("Programming");
    CHECK_EQ(c.getCourseName(), "Programming");
    c.setCourseNumber(250);
    CHECK_EQ(c.getCourseNumber(), 250);
    c.setCourseUnits(4);
    CHECK_EQ(c.getCourseUnits(), 4);
}

TEST_CASE("setPreReqs test") {
    Course c;
    SUBCASE("Empty set") {
        int array[] = {170, 150, 250};
        set<int> s = {170, 150, 250};
        c.setPrereqs(array, 3);
        CHECK_EQ(c.getCoursePrereqs(), s);
    }
    SUBCASE("Not empty set") {
        int array1[] = {45, 12, 50, 93};
        set<int> s1 = {45, 12, 50, 93};
        c.setPrereqs(array1, 4);
        REQUIRE_GT(c.getCoursePrereqs().size(), 3);
        CHECK_EQ(c.getCoursePrereqs(), s1);
    }
}


