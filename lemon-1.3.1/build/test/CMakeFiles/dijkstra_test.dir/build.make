# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/build

# Include any dependencies generated for this target.
include test/CMakeFiles/dijkstra_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/dijkstra_test.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/dijkstra_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/dijkstra_test.dir/flags.make

test/CMakeFiles/dijkstra_test.dir/dijkstra_test.cc.o: test/CMakeFiles/dijkstra_test.dir/flags.make
test/CMakeFiles/dijkstra_test.dir/dijkstra_test.cc.o: ../test/dijkstra_test.cc
test/CMakeFiles/dijkstra_test.dir/dijkstra_test.cc.o: test/CMakeFiles/dijkstra_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/dijkstra_test.dir/dijkstra_test.cc.o"
	cd /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/dijkstra_test.dir/dijkstra_test.cc.o -MF CMakeFiles/dijkstra_test.dir/dijkstra_test.cc.o.d -o CMakeFiles/dijkstra_test.dir/dijkstra_test.cc.o -c /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/test/dijkstra_test.cc

test/CMakeFiles/dijkstra_test.dir/dijkstra_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dijkstra_test.dir/dijkstra_test.cc.i"
	cd /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/test/dijkstra_test.cc > CMakeFiles/dijkstra_test.dir/dijkstra_test.cc.i

test/CMakeFiles/dijkstra_test.dir/dijkstra_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dijkstra_test.dir/dijkstra_test.cc.s"
	cd /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/test/dijkstra_test.cc -o CMakeFiles/dijkstra_test.dir/dijkstra_test.cc.s

# Object files for target dijkstra_test
dijkstra_test_OBJECTS = \
"CMakeFiles/dijkstra_test.dir/dijkstra_test.cc.o"

# External object files for target dijkstra_test
dijkstra_test_EXTERNAL_OBJECTS =

test/dijkstra_test: test/CMakeFiles/dijkstra_test.dir/dijkstra_test.cc.o
test/dijkstra_test: test/CMakeFiles/dijkstra_test.dir/build.make
test/dijkstra_test: lemon/libemon.a
test/dijkstra_test: test/CMakeFiles/dijkstra_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dijkstra_test"
	cd /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dijkstra_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/dijkstra_test.dir/build: test/dijkstra_test
.PHONY : test/CMakeFiles/dijkstra_test.dir/build

test/CMakeFiles/dijkstra_test.dir/clean:
	cd /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/build/test && $(CMAKE_COMMAND) -P CMakeFiles/dijkstra_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/dijkstra_test.dir/clean

test/CMakeFiles/dijkstra_test.dir/depend:
	cd /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1 /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/test /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/build /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/build/test /mnt/c/Users/Manuel/Desktop/coisas/42/alg2/euclidian_tsp/lemon-1.3.1/build/test/CMakeFiles/dijkstra_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/dijkstra_test.dir/depend

