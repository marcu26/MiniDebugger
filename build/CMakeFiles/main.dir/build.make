# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/eu/Desktop/Develop/PSOP-Debugger

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eu/Desktop/Develop/PSOP-Debugger/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eu/Desktop/Develop/PSOP-Debugger/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c /home/eu/Desktop/Develop/PSOP-Debugger/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eu/Desktop/Develop/PSOP-Debugger/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eu/Desktop/Develop/PSOP-Debugger/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/ext/linenoise/linenoise.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/ext/linenoise/linenoise.c.o: ../ext/linenoise/linenoise.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eu/Desktop/Develop/PSOP-Debugger/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/ext/linenoise/linenoise.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/ext/linenoise/linenoise.c.o   -c /home/eu/Desktop/Develop/PSOP-Debugger/ext/linenoise/linenoise.c

CMakeFiles/main.dir/ext/linenoise/linenoise.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/ext/linenoise/linenoise.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eu/Desktop/Develop/PSOP-Debugger/ext/linenoise/linenoise.c > CMakeFiles/main.dir/ext/linenoise/linenoise.c.i

CMakeFiles/main.dir/ext/linenoise/linenoise.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/ext/linenoise/linenoise.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eu/Desktop/Develop/PSOP-Debugger/ext/linenoise/linenoise.c -o CMakeFiles/main.dir/ext/linenoise/linenoise.c.s

CMakeFiles/main.dir/breakpoint.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/breakpoint.cpp.o: ../breakpoint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eu/Desktop/Develop/PSOP-Debugger/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/breakpoint.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/breakpoint.cpp.o -c /home/eu/Desktop/Develop/PSOP-Debugger/breakpoint.cpp

CMakeFiles/main.dir/breakpoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/breakpoint.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eu/Desktop/Develop/PSOP-Debugger/breakpoint.cpp > CMakeFiles/main.dir/breakpoint.cpp.i

CMakeFiles/main.dir/breakpoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/breakpoint.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eu/Desktop/Develop/PSOP-Debugger/breakpoint.cpp -o CMakeFiles/main.dir/breakpoint.cpp.s

CMakeFiles/main.dir/debugger.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/debugger.cpp.o: ../debugger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eu/Desktop/Develop/PSOP-Debugger/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/debugger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/debugger.cpp.o -c /home/eu/Desktop/Develop/PSOP-Debugger/debugger.cpp

CMakeFiles/main.dir/debugger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/debugger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eu/Desktop/Develop/PSOP-Debugger/debugger.cpp > CMakeFiles/main.dir/debugger.cpp.i

CMakeFiles/main.dir/debugger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/debugger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eu/Desktop/Develop/PSOP-Debugger/debugger.cpp -o CMakeFiles/main.dir/debugger.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/ext/linenoise/linenoise.c.o" \
"CMakeFiles/main.dir/breakpoint.cpp.o" \
"CMakeFiles/main.dir/debugger.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/ext/linenoise/linenoise.c.o
main: CMakeFiles/main.dir/breakpoint.cpp.o
main: CMakeFiles/main.dir/debugger.cpp.o
main: CMakeFiles/main.dir/build.make
main: ../ext/libelfin/dwarf/libdwarf++.so
main: ../ext/libelfin/elf/libelf++.so
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eu/Desktop/Develop/PSOP-Debugger/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/eu/Desktop/Develop/PSOP-Debugger/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eu/Desktop/Develop/PSOP-Debugger /home/eu/Desktop/Develop/PSOP-Debugger /home/eu/Desktop/Develop/PSOP-Debugger/build /home/eu/Desktop/Develop/PSOP-Debugger/build /home/eu/Desktop/Develop/PSOP-Debugger/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend
