#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Course.h"
using namespace std;

TEST_CASE("default constructor test"){
    Course c;
    CHECK_EQ(c.getCourseNumber(), 0);
    CHECK_EQ(c.getCoursePrereqs().size(), 0);
    CHECK_EQ(c.getCourseName(), "N/A");
    CHECK_EQ(c.getCoursePrereqs().size(), 0);
}


TEST_CASE("constructor test"){
    set<int> s = {1, 2};
    Course c(5, "CS250", 3, s);
    CHECK_EQ(c.getCoursePrereqs().size(), 2);
    CHECK_EQ(c.getCourseNumber(), 5);
    CHECK_EQ(c.getCourseName(), "CS250");
    CHECK_EQ(c.getCourseUnits(), 4);
    CHECK_EQ(c.getCoursePrereqs(), s);
}


