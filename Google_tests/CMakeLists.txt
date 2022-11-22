project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Test_run ConstructorTests.cpp)

target_link_libraries(Google_Tests_run CS250_project)
target_link_libraries(Google_Tests_run gtest gtest_main)