# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
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
CMAKE_SOURCE_DIR = /Users/songji/Desktop/algorithm-study/algorithm-int/jieun/boj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/songji/Desktop/algorithm-study/algorithm-int/jieun/boj/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/boj12486.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/boj12486.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/boj12486.dir/flags.make

CMakeFiles/boj12486.dir/boj12486.cpp.o: CMakeFiles/boj12486.dir/flags.make
CMakeFiles/boj12486.dir/boj12486.cpp.o: ../boj12486.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/songji/Desktop/algorithm-study/algorithm-int/jieun/boj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/boj12486.dir/boj12486.cpp.o"
	/usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boj12486.dir/boj12486.cpp.o -c /Users/songji/Desktop/algorithm-study/algorithm-int/jieun/boj/boj12486.cpp

CMakeFiles/boj12486.dir/boj12486.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boj12486.dir/boj12486.cpp.i"
	/usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/songji/Desktop/algorithm-study/algorithm-int/jieun/boj/boj12486.cpp > CMakeFiles/boj12486.dir/boj12486.cpp.i

CMakeFiles/boj12486.dir/boj12486.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boj12486.dir/boj12486.cpp.s"
	/usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/songji/Desktop/algorithm-study/algorithm-int/jieun/boj/boj12486.cpp -o CMakeFiles/boj12486.dir/boj12486.cpp.s

# Object files for target boj12486
boj12486_OBJECTS = \
"CMakeFiles/boj12486.dir/boj12486.cpp.o"

# External object files for target boj12486
boj12486_EXTERNAL_OBJECTS =

boj12486: CMakeFiles/boj12486.dir/boj12486.cpp.o
boj12486: CMakeFiles/boj12486.dir/build.make
boj12486: CMakeFiles/boj12486.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/songji/Desktop/algorithm-study/algorithm-int/jieun/boj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable boj12486"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boj12486.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/boj12486.dir/build: boj12486

.PHONY : CMakeFiles/boj12486.dir/build

CMakeFiles/boj12486.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/boj12486.dir/cmake_clean.cmake
.PHONY : CMakeFiles/boj12486.dir/clean

CMakeFiles/boj12486.dir/depend:
	cd /Users/songji/Desktop/algorithm-study/algorithm-int/jieun/boj/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/songji/Desktop/algorithm-study/algorithm-int/jieun/boj /Users/songji/Desktop/algorithm-study/algorithm-int/jieun/boj /Users/songji/Desktop/algorithm-study/algorithm-int/jieun/boj/cmake-build-debug /Users/songji/Desktop/algorithm-study/algorithm-int/jieun/boj/cmake-build-debug /Users/songji/Desktop/algorithm-study/algorithm-int/jieun/boj/cmake-build-debug/CMakeFiles/boj12486.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/boj12486.dir/depend

