# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.7.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.7.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tangxiangru/code/uniquelab-2017-summer-assignment-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tangxiangru/code/uniquelab-2017-summer-assignment-1

# Include any dependencies generated for this target.
include CMakeFiles/set.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/set.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/set.dir/flags.make

CMakeFiles/set.dir/set.cpp.o: CMakeFiles/set.dir/flags.make
CMakeFiles/set.dir/set.cpp.o: set.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tangxiangru/code/uniquelab-2017-summer-assignment-1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/set.dir/set.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/set.dir/set.cpp.o -c /Users/tangxiangru/code/uniquelab-2017-summer-assignment-1/set.cpp

CMakeFiles/set.dir/set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/set.dir/set.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tangxiangru/code/uniquelab-2017-summer-assignment-1/set.cpp > CMakeFiles/set.dir/set.cpp.i

CMakeFiles/set.dir/set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/set.dir/set.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tangxiangru/code/uniquelab-2017-summer-assignment-1/set.cpp -o CMakeFiles/set.dir/set.cpp.s

CMakeFiles/set.dir/set.cpp.o.requires:

.PHONY : CMakeFiles/set.dir/set.cpp.o.requires

CMakeFiles/set.dir/set.cpp.o.provides: CMakeFiles/set.dir/set.cpp.o.requires
	$(MAKE) -f CMakeFiles/set.dir/build.make CMakeFiles/set.dir/set.cpp.o.provides.build
.PHONY : CMakeFiles/set.dir/set.cpp.o.provides

CMakeFiles/set.dir/set.cpp.o.provides.build: CMakeFiles/set.dir/set.cpp.o


# Object files for target set
set_OBJECTS = \
"CMakeFiles/set.dir/set.cpp.o"

# External object files for target set
set_EXTERNAL_OBJECTS =

libset.a: CMakeFiles/set.dir/set.cpp.o
libset.a: CMakeFiles/set.dir/build.make
libset.a: CMakeFiles/set.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tangxiangru/code/uniquelab-2017-summer-assignment-1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libset.a"
	$(CMAKE_COMMAND) -P CMakeFiles/set.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/set.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/set.dir/build: libset.a

.PHONY : CMakeFiles/set.dir/build

CMakeFiles/set.dir/requires: CMakeFiles/set.dir/set.cpp.o.requires

.PHONY : CMakeFiles/set.dir/requires

CMakeFiles/set.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/set.dir/cmake_clean.cmake
.PHONY : CMakeFiles/set.dir/clean

CMakeFiles/set.dir/depend:
	cd /Users/tangxiangru/code/uniquelab-2017-summer-assignment-1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tangxiangru/code/uniquelab-2017-summer-assignment-1 /Users/tangxiangru/code/uniquelab-2017-summer-assignment-1 /Users/tangxiangru/code/uniquelab-2017-summer-assignment-1 /Users/tangxiangru/code/uniquelab-2017-summer-assignment-1 /Users/tangxiangru/code/uniquelab-2017-summer-assignment-1/CMakeFiles/set.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/set.dir/depend
