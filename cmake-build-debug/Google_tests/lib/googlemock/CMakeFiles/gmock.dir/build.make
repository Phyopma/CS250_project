# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/phyopyae/Desktop/CS250_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/phyopyae/Desktop/CS250_project/cmake-build-debug

# Include any dependencies generated for this target.
include Google_tests/lib/googlemock/CMakeFiles/gmock.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Google_tests/lib/googlemock/CMakeFiles/gmock.dir/compiler_depend.make

# Include the progress variables for this target.
include Google_tests/lib/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include Google_tests/lib/googlemock/CMakeFiles/gmock.dir/flags.make

Google_tests/lib/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: Google_tests/lib/googlemock/CMakeFiles/gmock.dir/flags.make
Google_tests/lib/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: ../Google_tests/lib/googlemock/src/gmock-all.cc
Google_tests/lib/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: Google_tests/lib/googlemock/CMakeFiles/gmock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phyopyae/Desktop/CS250_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Google_tests/lib/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /Users/phyopyae/Desktop/CS250_project/cmake-build-debug/Google_tests/lib/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Google_tests/lib/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o -MF CMakeFiles/gmock.dir/src/gmock-all.cc.o.d -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /Users/phyopyae/Desktop/CS250_project/Google_tests/lib/googlemock/src/gmock-all.cc

Google_tests/lib/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /Users/phyopyae/Desktop/CS250_project/cmake-build-debug/Google_tests/lib/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phyopyae/Desktop/CS250_project/Google_tests/lib/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

Google_tests/lib/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /Users/phyopyae/Desktop/CS250_project/cmake-build-debug/Google_tests/lib/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phyopyae/Desktop/CS250_project/Google_tests/lib/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

lib/libgmock.a: Google_tests/lib/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
lib/libgmock.a: Google_tests/lib/googlemock/CMakeFiles/gmock.dir/build.make
lib/libgmock.a: Google_tests/lib/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/phyopyae/Desktop/CS250_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libgmock.a"
	cd /Users/phyopyae/Desktop/CS250_project/cmake-build-debug/Google_tests/lib/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd /Users/phyopyae/Desktop/CS250_project/cmake-build-debug/Google_tests/lib/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Google_tests/lib/googlemock/CMakeFiles/gmock.dir/build: lib/libgmock.a
.PHONY : Google_tests/lib/googlemock/CMakeFiles/gmock.dir/build

Google_tests/lib/googlemock/CMakeFiles/gmock.dir/clean:
	cd /Users/phyopyae/Desktop/CS250_project/cmake-build-debug/Google_tests/lib/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : Google_tests/lib/googlemock/CMakeFiles/gmock.dir/clean

Google_tests/lib/googlemock/CMakeFiles/gmock.dir/depend:
	cd /Users/phyopyae/Desktop/CS250_project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/phyopyae/Desktop/CS250_project /Users/phyopyae/Desktop/CS250_project/Google_tests/lib/googlemock /Users/phyopyae/Desktop/CS250_project/cmake-build-debug /Users/phyopyae/Desktop/CS250_project/cmake-build-debug/Google_tests/lib/googlemock /Users/phyopyae/Desktop/CS250_project/cmake-build-debug/Google_tests/lib/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Google_tests/lib/googlemock/CMakeFiles/gmock.dir/depend

