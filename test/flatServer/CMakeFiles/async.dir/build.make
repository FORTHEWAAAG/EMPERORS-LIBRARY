# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/max/Projects/TelemetryAgent/asyncServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/max/Projects/TelemetryAgent/asyncServer

# Include any dependencies generated for this target.
include CMakeFiles/async.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/async.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/async.dir/flags.make

CMakeFiles/async.dir/asyncServer.cpp.o: CMakeFiles/async.dir/flags.make
CMakeFiles/async.dir/asyncServer.cpp.o: asyncServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/Projects/TelemetryAgent/asyncServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/async.dir/asyncServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/async.dir/asyncServer.cpp.o -c /home/max/Projects/TelemetryAgent/asyncServer/asyncServer.cpp

CMakeFiles/async.dir/asyncServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/async.dir/asyncServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/max/Projects/TelemetryAgent/asyncServer/asyncServer.cpp > CMakeFiles/async.dir/asyncServer.cpp.i

CMakeFiles/async.dir/asyncServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/async.dir/asyncServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/max/Projects/TelemetryAgent/asyncServer/asyncServer.cpp -o CMakeFiles/async.dir/asyncServer.cpp.s

# Object files for target async
async_OBJECTS = \
"CMakeFiles/async.dir/asyncServer.cpp.o"

# External object files for target async
async_EXTERNAL_OBJECTS =

async: CMakeFiles/async.dir/asyncServer.cpp.o
async: CMakeFiles/async.dir/build.make
async: CMakeFiles/async.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/max/Projects/TelemetryAgent/asyncServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable async"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/async.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/async.dir/build: async

.PHONY : CMakeFiles/async.dir/build

CMakeFiles/async.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/async.dir/cmake_clean.cmake
.PHONY : CMakeFiles/async.dir/clean

CMakeFiles/async.dir/depend:
	cd /home/max/Projects/TelemetryAgent/asyncServer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/max/Projects/TelemetryAgent/asyncServer /home/max/Projects/TelemetryAgent/asyncServer /home/max/Projects/TelemetryAgent/asyncServer /home/max/Projects/TelemetryAgent/asyncServer /home/max/Projects/TelemetryAgent/asyncServer/CMakeFiles/async.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/async.dir/depend

