# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.26.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.26.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/leomaisnam/PersonalProjects/Testing/square_jump

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/leomaisnam/PersonalProjects/Testing/square_jump

# Include any dependencies generated for this target.
include CMakeFiles/square_jump.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/square_jump.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/square_jump.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/square_jump.dir/flags.make

CMakeFiles/square_jump.dir/sjump.c.o: CMakeFiles/square_jump.dir/flags.make
CMakeFiles/square_jump.dir/sjump.c.o: sjump.c
CMakeFiles/square_jump.dir/sjump.c.o: CMakeFiles/square_jump.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leomaisnam/PersonalProjects/Testing/square_jump/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/square_jump.dir/sjump.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/square_jump.dir/sjump.c.o -MF CMakeFiles/square_jump.dir/sjump.c.o.d -o CMakeFiles/square_jump.dir/sjump.c.o -c /Users/leomaisnam/PersonalProjects/Testing/square_jump/sjump.c

CMakeFiles/square_jump.dir/sjump.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/square_jump.dir/sjump.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/leomaisnam/PersonalProjects/Testing/square_jump/sjump.c > CMakeFiles/square_jump.dir/sjump.c.i

CMakeFiles/square_jump.dir/sjump.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/square_jump.dir/sjump.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/leomaisnam/PersonalProjects/Testing/square_jump/sjump.c -o CMakeFiles/square_jump.dir/sjump.c.s

# Object files for target square_jump
square_jump_OBJECTS = \
"CMakeFiles/square_jump.dir/sjump.c.o"

# External object files for target square_jump
square_jump_EXTERNAL_OBJECTS =

square_jump: CMakeFiles/square_jump.dir/sjump.c.o
square_jump: CMakeFiles/square_jump.dir/build.make
square_jump: /usr/local/lib/libSDL2.dylib
square_jump: CMakeFiles/square_jump.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/leomaisnam/PersonalProjects/Testing/square_jump/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable square_jump"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/square_jump.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/square_jump.dir/build: square_jump
.PHONY : CMakeFiles/square_jump.dir/build

CMakeFiles/square_jump.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/square_jump.dir/cmake_clean.cmake
.PHONY : CMakeFiles/square_jump.dir/clean

CMakeFiles/square_jump.dir/depend:
	cd /Users/leomaisnam/PersonalProjects/Testing/square_jump && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/leomaisnam/PersonalProjects/Testing/square_jump /Users/leomaisnam/PersonalProjects/Testing/square_jump /Users/leomaisnam/PersonalProjects/Testing/square_jump /Users/leomaisnam/PersonalProjects/Testing/square_jump /Users/leomaisnam/PersonalProjects/Testing/square_jump/CMakeFiles/square_jump.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/square_jump.dir/depend

