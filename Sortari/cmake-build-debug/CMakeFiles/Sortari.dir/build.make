# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\cpp facultate\Sortari"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\cpp facultate\Sortari\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Sortari.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Sortari.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sortari.dir/flags.make

CMakeFiles/Sortari.dir/main.cpp.obj: CMakeFiles/Sortari.dir/flags.make
CMakeFiles/Sortari.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\cpp facultate\Sortari\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sortari.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Sortari.dir\main.cpp.obj -c "E:\cpp facultate\Sortari\main.cpp"

CMakeFiles/Sortari.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sortari.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\cpp facultate\Sortari\main.cpp" > CMakeFiles\Sortari.dir\main.cpp.i

CMakeFiles/Sortari.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sortari.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\cpp facultate\Sortari\main.cpp" -o CMakeFiles\Sortari.dir\main.cpp.s

# Object files for target Sortari
Sortari_OBJECTS = \
"CMakeFiles/Sortari.dir/main.cpp.obj"

# External object files for target Sortari
Sortari_EXTERNAL_OBJECTS =

Sortari.exe: CMakeFiles/Sortari.dir/main.cpp.obj
Sortari.exe: CMakeFiles/Sortari.dir/build.make
Sortari.exe: CMakeFiles/Sortari.dir/linklibs.rsp
Sortari.exe: CMakeFiles/Sortari.dir/objects1.rsp
Sortari.exe: CMakeFiles/Sortari.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\cpp facultate\Sortari\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Sortari.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Sortari.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sortari.dir/build: Sortari.exe

.PHONY : CMakeFiles/Sortari.dir/build

CMakeFiles/Sortari.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Sortari.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Sortari.dir/clean

CMakeFiles/Sortari.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\cpp facultate\Sortari" "E:\cpp facultate\Sortari" "E:\cpp facultate\Sortari\cmake-build-debug" "E:\cpp facultate\Sortari\cmake-build-debug" "E:\cpp facultate\Sortari\cmake-build-debug\CMakeFiles\Sortari.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Sortari.dir/depend
