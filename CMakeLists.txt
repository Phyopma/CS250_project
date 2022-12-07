cmake_minimum_required(VERSION 3.23)
project(CS250_project)

set(CMAKE_CXX_STANDARD 14)

#add_executable(CS250_project Main.cpp Course.cpp Course.h CourseList.cpp
#        CourseList.h CourseListInsertInOrder.cpp CourseListBigThree.cpp)

#add_executable(CS250_project MainForPartB.cpp Course.cpp Course.h CourseList.cpp
#        CourseList.h CourseListInsertInOrder.cpp CourseListBigThree.cpp
#        TestFunctions.cpp TestCopyAssignmentOp.cpp TestCopyConstructor.cpp TestCourse.cpp)


add_executable(CS250_project Main.cpp Course.cpp Course.h CourseList.cpp
        CourseList.h CourseListInsertInOrder.cpp CourseListBigThree.cpp
        Interface.cpp TestingCases.cpp)

#add_executable(CS250_project_PartA MainForPartA.cpp Course.cpp Course.h)

#add_executable(testingCourseList Course.cpp Course.h CourseList.cpp
#        CourseList.h CourseListInsertInOrder.cpp CourseListBigThree.cpp
#        TestFunctions.cpp)
#
#add_executable(testingCopyAssignment Course.cpp Course.h CourseList.cpp
#        CourseList.h CourseListInsertInOrder.cpp CourseListBigThree.cpp
#        TestCopyAssignmentOp.cpp)
#
#add_executable(testingCopyConstuctor Course.cpp Course.h CourseList.cpp
#        CourseList.h CourseListInsertInOrder.cpp CourseListBigThree.cpp
#        TestCopyConstructor.cpp)
