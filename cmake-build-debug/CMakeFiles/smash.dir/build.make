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
CMAKE_COMMAND = /opt/clion-2020.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/CLionProjects/Smash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/CLionProjects/Smash/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/smash.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/smash.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/smash.dir/flags.make

CMakeFiles/smash.dir/smash.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/smash.cpp.o: ../smash.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/smash.dir/smash.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/smash.cpp.o -c /home/student/CLionProjects/Smash/smash.cpp

CMakeFiles/smash.dir/smash.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/smash.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Smash/smash.cpp > CMakeFiles/smash.dir/smash.cpp.i

CMakeFiles/smash.dir/smash.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/smash.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Smash/smash.cpp -o CMakeFiles/smash.dir/smash.cpp.s

CMakeFiles/smash.dir/Commands.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/Commands.cpp.o: ../Commands.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/smash.dir/Commands.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/Commands.cpp.o -c /home/student/CLionProjects/Smash/Commands.cpp

CMakeFiles/smash.dir/Commands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/Commands.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Smash/Commands.cpp > CMakeFiles/smash.dir/Commands.cpp.i

CMakeFiles/smash.dir/Commands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/Commands.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Smash/Commands.cpp -o CMakeFiles/smash.dir/Commands.cpp.s

CMakeFiles/smash.dir/signals.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/signals.cpp.o: ../signals.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/smash.dir/signals.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/signals.cpp.o -c /home/student/CLionProjects/Smash/signals.cpp

CMakeFiles/smash.dir/signals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/signals.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Smash/signals.cpp > CMakeFiles/smash.dir/signals.cpp.i

CMakeFiles/smash.dir/signals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/signals.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Smash/signals.cpp -o CMakeFiles/smash.dir/signals.cpp.s

CMakeFiles/smash.dir/ShowPidCommand.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/ShowPidCommand.cpp.o: ../ShowPidCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/smash.dir/ShowPidCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/ShowPidCommand.cpp.o -c /home/student/CLionProjects/Smash/ShowPidCommand.cpp

CMakeFiles/smash.dir/ShowPidCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/ShowPidCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Smash/ShowPidCommand.cpp > CMakeFiles/smash.dir/ShowPidCommand.cpp.i

CMakeFiles/smash.dir/ShowPidCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/ShowPidCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Smash/ShowPidCommand.cpp -o CMakeFiles/smash.dir/ShowPidCommand.cpp.s

CMakeFiles/smash.dir/GetCurrDirCommand.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/GetCurrDirCommand.cpp.o: ../GetCurrDirCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/smash.dir/GetCurrDirCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/GetCurrDirCommand.cpp.o -c /home/student/CLionProjects/Smash/GetCurrDirCommand.cpp

CMakeFiles/smash.dir/GetCurrDirCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/GetCurrDirCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Smash/GetCurrDirCommand.cpp > CMakeFiles/smash.dir/GetCurrDirCommand.cpp.i

CMakeFiles/smash.dir/GetCurrDirCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/GetCurrDirCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Smash/GetCurrDirCommand.cpp -o CMakeFiles/smash.dir/GetCurrDirCommand.cpp.s

CMakeFiles/smash.dir/ChangeDirCommand.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/ChangeDirCommand.cpp.o: ../ChangeDirCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/smash.dir/ChangeDirCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/ChangeDirCommand.cpp.o -c /home/student/CLionProjects/Smash/ChangeDirCommand.cpp

CMakeFiles/smash.dir/ChangeDirCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/ChangeDirCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Smash/ChangeDirCommand.cpp > CMakeFiles/smash.dir/ChangeDirCommand.cpp.i

CMakeFiles/smash.dir/ChangeDirCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/ChangeDirCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Smash/ChangeDirCommand.cpp -o CMakeFiles/smash.dir/ChangeDirCommand.cpp.s

CMakeFiles/smash.dir/JobsCommand.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/JobsCommand.cpp.o: ../JobsCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/smash.dir/JobsCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/JobsCommand.cpp.o -c /home/student/CLionProjects/Smash/JobsCommand.cpp

CMakeFiles/smash.dir/JobsCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/JobsCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Smash/JobsCommand.cpp > CMakeFiles/smash.dir/JobsCommand.cpp.i

CMakeFiles/smash.dir/JobsCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/JobsCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Smash/JobsCommand.cpp -o CMakeFiles/smash.dir/JobsCommand.cpp.s

CMakeFiles/smash.dir/Wrappers.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/Wrappers.cpp.o: ../Wrappers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/smash.dir/Wrappers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/Wrappers.cpp.o -c /home/student/CLionProjects/Smash/Wrappers.cpp

CMakeFiles/smash.dir/Wrappers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/Wrappers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Smash/Wrappers.cpp > CMakeFiles/smash.dir/Wrappers.cpp.i

CMakeFiles/smash.dir/Wrappers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/Wrappers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Smash/Wrappers.cpp -o CMakeFiles/smash.dir/Wrappers.cpp.s

CMakeFiles/smash.dir/PipeCommand.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/PipeCommand.cpp.o: ../PipeCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/smash.dir/PipeCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/PipeCommand.cpp.o -c /home/student/CLionProjects/Smash/PipeCommand.cpp

CMakeFiles/smash.dir/PipeCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/PipeCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Smash/PipeCommand.cpp > CMakeFiles/smash.dir/PipeCommand.cpp.i

CMakeFiles/smash.dir/PipeCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/PipeCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Smash/PipeCommand.cpp -o CMakeFiles/smash.dir/PipeCommand.cpp.s

CMakeFiles/smash.dir/RedirectionCommand.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/RedirectionCommand.cpp.o: ../RedirectionCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/smash.dir/RedirectionCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/RedirectionCommand.cpp.o -c /home/student/CLionProjects/Smash/RedirectionCommand.cpp

CMakeFiles/smash.dir/RedirectionCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/RedirectionCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Smash/RedirectionCommand.cpp > CMakeFiles/smash.dir/RedirectionCommand.cpp.i

CMakeFiles/smash.dir/RedirectionCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/RedirectionCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Smash/RedirectionCommand.cpp -o CMakeFiles/smash.dir/RedirectionCommand.cpp.s

CMakeFiles/smash.dir/MyException.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/MyException.cpp.o: ../MyException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/smash.dir/MyException.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/MyException.cpp.o -c /home/student/CLionProjects/Smash/MyException.cpp

CMakeFiles/smash.dir/MyException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/MyException.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Smash/MyException.cpp > CMakeFiles/smash.dir/MyException.cpp.i

CMakeFiles/smash.dir/MyException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/MyException.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Smash/MyException.cpp -o CMakeFiles/smash.dir/MyException.cpp.s

CMakeFiles/smash.dir/killCommand.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/killCommand.cpp.o: ../killCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/smash.dir/killCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/killCommand.cpp.o -c /home/student/CLionProjects/Smash/killCommand.cpp

CMakeFiles/smash.dir/killCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/killCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Smash/killCommand.cpp > CMakeFiles/smash.dir/killCommand.cpp.i

CMakeFiles/smash.dir/killCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/killCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Smash/killCommand.cpp -o CMakeFiles/smash.dir/killCommand.cpp.s

CMakeFiles/smash.dir/BackgroundCommand.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/BackgroundCommand.cpp.o: ../BackgroundCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/smash.dir/BackgroundCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/BackgroundCommand.cpp.o -c /home/student/CLionProjects/Smash/BackgroundCommand.cpp

CMakeFiles/smash.dir/BackgroundCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/BackgroundCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Smash/BackgroundCommand.cpp > CMakeFiles/smash.dir/BackgroundCommand.cpp.i

CMakeFiles/smash.dir/BackgroundCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/BackgroundCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Smash/BackgroundCommand.cpp -o CMakeFiles/smash.dir/BackgroundCommand.cpp.s

CMakeFiles/smash.dir/ForegroundCommand.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/ForegroundCommand.cpp.o: ../ForegroundCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/smash.dir/ForegroundCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/ForegroundCommand.cpp.o -c /home/student/CLionProjects/Smash/ForegroundCommand.cpp

CMakeFiles/smash.dir/ForegroundCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/ForegroundCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Smash/ForegroundCommand.cpp > CMakeFiles/smash.dir/ForegroundCommand.cpp.i

CMakeFiles/smash.dir/ForegroundCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/ForegroundCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Smash/ForegroundCommand.cpp -o CMakeFiles/smash.dir/ForegroundCommand.cpp.s

CMakeFiles/smash.dir/QuitCommand.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/QuitCommand.cpp.o: ../QuitCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/smash.dir/QuitCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/QuitCommand.cpp.o -c /home/student/CLionProjects/Smash/QuitCommand.cpp

CMakeFiles/smash.dir/QuitCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/QuitCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Smash/QuitCommand.cpp > CMakeFiles/smash.dir/QuitCommand.cpp.i

CMakeFiles/smash.dir/QuitCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/QuitCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Smash/QuitCommand.cpp -o CMakeFiles/smash.dir/QuitCommand.cpp.s

# Object files for target smash
smash_OBJECTS = \
"CMakeFiles/smash.dir/smash.cpp.o" \
"CMakeFiles/smash.dir/Commands.cpp.o" \
"CMakeFiles/smash.dir/signals.cpp.o" \
"CMakeFiles/smash.dir/ShowPidCommand.cpp.o" \
"CMakeFiles/smash.dir/GetCurrDirCommand.cpp.o" \
"CMakeFiles/smash.dir/ChangeDirCommand.cpp.o" \
"CMakeFiles/smash.dir/JobsCommand.cpp.o" \
"CMakeFiles/smash.dir/Wrappers.cpp.o" \
"CMakeFiles/smash.dir/PipeCommand.cpp.o" \
"CMakeFiles/smash.dir/RedirectionCommand.cpp.o" \
"CMakeFiles/smash.dir/MyException.cpp.o" \
"CMakeFiles/smash.dir/killCommand.cpp.o" \
"CMakeFiles/smash.dir/BackgroundCommand.cpp.o" \
"CMakeFiles/smash.dir/ForegroundCommand.cpp.o" \
"CMakeFiles/smash.dir/QuitCommand.cpp.o"

# External object files for target smash
smash_EXTERNAL_OBJECTS =

smash: CMakeFiles/smash.dir/smash.cpp.o
smash: CMakeFiles/smash.dir/Commands.cpp.o
smash: CMakeFiles/smash.dir/signals.cpp.o
smash: CMakeFiles/smash.dir/ShowPidCommand.cpp.o
smash: CMakeFiles/smash.dir/GetCurrDirCommand.cpp.o
smash: CMakeFiles/smash.dir/ChangeDirCommand.cpp.o
smash: CMakeFiles/smash.dir/JobsCommand.cpp.o
smash: CMakeFiles/smash.dir/Wrappers.cpp.o
smash: CMakeFiles/smash.dir/PipeCommand.cpp.o
smash: CMakeFiles/smash.dir/RedirectionCommand.cpp.o
smash: CMakeFiles/smash.dir/MyException.cpp.o
smash: CMakeFiles/smash.dir/killCommand.cpp.o
smash: CMakeFiles/smash.dir/BackgroundCommand.cpp.o
smash: CMakeFiles/smash.dir/ForegroundCommand.cpp.o
smash: CMakeFiles/smash.dir/QuitCommand.cpp.o
smash: CMakeFiles/smash.dir/build.make
smash: CMakeFiles/smash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable smash"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/smash.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/smash.dir/build: smash

.PHONY : CMakeFiles/smash.dir/build

CMakeFiles/smash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/smash.dir/cmake_clean.cmake
.PHONY : CMakeFiles/smash.dir/clean

CMakeFiles/smash.dir/depend:
	cd /home/student/CLionProjects/Smash/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/CLionProjects/Smash /home/student/CLionProjects/Smash /home/student/CLionProjects/Smash/cmake-build-debug /home/student/CLionProjects/Smash/cmake-build-debug /home/student/CLionProjects/Smash/cmake-build-debug/CMakeFiles/smash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/smash.dir/depend

