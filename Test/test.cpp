#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../Course.h"
using namespace std;

TEST_CASE("default constructor test"){
    Course c;
    CHECK_EQ(c.getCourseNumber(), 0);
    CHECK_EQ(c.getCoursePrereqs().size(), 0);
    CHECK_EQ(c.getCourseName(), "N/A");
}


TEST_CASE("constructor test"){
    set<int> s = {1,2};
    Course c(0,"CS250",4, s );
    CHECK_EQ(c.getCoursePrereqs().size(), 2);
    CHECK_EQ(c.getCourseName(), "CS250");
    string g = "CS150";
    c.setCourseName(g);
    CHECK_EQ(c.getCourseName(), g);
}


