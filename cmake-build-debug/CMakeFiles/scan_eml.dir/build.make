# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\piotr\CLionProjects\scan_eml

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\piotr\CLionProjects\scan_eml\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/scan_eml.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/scan_eml.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/scan_eml.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/scan_eml.dir/flags.make

CMakeFiles/scan_eml.dir/src/main.c.obj: CMakeFiles/scan_eml.dir/flags.make
CMakeFiles/scan_eml.dir/src/main.c.obj: C:/Users/piotr/CLionProjects/scan_eml/src/main.c
CMakeFiles/scan_eml.dir/src/main.c.obj: CMakeFiles/scan_eml.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\piotr\CLionProjects\scan_eml\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/scan_eml.dir/src/main.c.obj"
	"D:\Program files\JetBrains\CLion 2023.3.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/scan_eml.dir/src/main.c.obj -MF CMakeFiles\scan_eml.dir\src\main.c.obj.d -o CMakeFiles\scan_eml.dir\src\main.c.obj -c C:\Users\piotr\CLionProjects\scan_eml\src\main.c

CMakeFiles/scan_eml.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/scan_eml.dir/src/main.c.i"
	"D:\Program files\JetBrains\CLion 2023.3.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\piotr\CLionProjects\scan_eml\src\main.c > CMakeFiles\scan_eml.dir\src\main.c.i

CMakeFiles/scan_eml.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/scan_eml.dir/src/main.c.s"
	"D:\Program files\JetBrains\CLion 2023.3.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\piotr\CLionProjects\scan_eml\src\main.c -o CMakeFiles\scan_eml.dir\src\main.c.s

CMakeFiles/scan_eml.dir/src/utils/validateFile.c.obj: CMakeFiles/scan_eml.dir/flags.make
CMakeFiles/scan_eml.dir/src/utils/validateFile.c.obj: C:/Users/piotr/CLionProjects/scan_eml/src/utils/validateFile.c
CMakeFiles/scan_eml.dir/src/utils/validateFile.c.obj: CMakeFiles/scan_eml.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\piotr\CLionProjects\scan_eml\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/scan_eml.dir/src/utils/validateFile.c.obj"
	"D:\Program files\JetBrains\CLion 2023.3.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/scan_eml.dir/src/utils/validateFile.c.obj -MF CMakeFiles\scan_eml.dir\src\utils\validateFile.c.obj.d -o CMakeFiles\scan_eml.dir\src\utils\validateFile.c.obj -c C:\Users\piotr\CLionProjects\scan_eml\src\utils\validateFile.c

CMakeFiles/scan_eml.dir/src/utils/validateFile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/scan_eml.dir/src/utils/validateFile.c.i"
	"D:\Program files\JetBrains\CLion 2023.3.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\piotr\CLionProjects\scan_eml\src\utils\validateFile.c > CMakeFiles\scan_eml.dir\src\utils\validateFile.c.i

CMakeFiles/scan_eml.dir/src/utils/validateFile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/scan_eml.dir/src/utils/validateFile.c.s"
	"D:\Program files\JetBrains\CLion 2023.3.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\piotr\CLionProjects\scan_eml\src\utils\validateFile.c -o CMakeFiles\scan_eml.dir\src\utils\validateFile.c.s

CMakeFiles/scan_eml.dir/src/utils/validatePesel.c.obj: CMakeFiles/scan_eml.dir/flags.make
CMakeFiles/scan_eml.dir/src/utils/validatePesel.c.obj: C:/Users/piotr/CLionProjects/scan_eml/src/utils/validatePesel.c
CMakeFiles/scan_eml.dir/src/utils/validatePesel.c.obj: CMakeFiles/scan_eml.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\piotr\CLionProjects\scan_eml\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/scan_eml.dir/src/utils/validatePesel.c.obj"
	"D:\Program files\JetBrains\CLion 2023.3.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/scan_eml.dir/src/utils/validatePesel.c.obj -MF CMakeFiles\scan_eml.dir\src\utils\validatePesel.c.obj.d -o CMakeFiles\scan_eml.dir\src\utils\validatePesel.c.obj -c C:\Users\piotr\CLionProjects\scan_eml\src\utils\validatePesel.c

CMakeFiles/scan_eml.dir/src/utils/validatePesel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/scan_eml.dir/src/utils/validatePesel.c.i"
	"D:\Program files\JetBrains\CLion 2023.3.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\piotr\CLionProjects\scan_eml\src\utils\validatePesel.c > CMakeFiles\scan_eml.dir\src\utils\validatePesel.c.i

CMakeFiles/scan_eml.dir/src/utils/validatePesel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/scan_eml.dir/src/utils/validatePesel.c.s"
	"D:\Program files\JetBrains\CLion 2023.3.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\piotr\CLionProjects\scan_eml\src\utils\validatePesel.c -o CMakeFiles\scan_eml.dir\src\utils\validatePesel.c.s

CMakeFiles/scan_eml.dir/src/searchFile.c.obj: CMakeFiles/scan_eml.dir/flags.make
CMakeFiles/scan_eml.dir/src/searchFile.c.obj: C:/Users/piotr/CLionProjects/scan_eml/src/searchFile.c
CMakeFiles/scan_eml.dir/src/searchFile.c.obj: CMakeFiles/scan_eml.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\piotr\CLionProjects\scan_eml\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/scan_eml.dir/src/searchFile.c.obj"
	"D:\Program files\JetBrains\CLion 2023.3.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/scan_eml.dir/src/searchFile.c.obj -MF CMakeFiles\scan_eml.dir\src\searchFile.c.obj.d -o CMakeFiles\scan_eml.dir\src\searchFile.c.obj -c C:\Users\piotr\CLionProjects\scan_eml\src\searchFile.c

CMakeFiles/scan_eml.dir/src/searchFile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/scan_eml.dir/src/searchFile.c.i"
	"D:\Program files\JetBrains\CLion 2023.3.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\piotr\CLionProjects\scan_eml\src\searchFile.c > CMakeFiles\scan_eml.dir\src\searchFile.c.i

CMakeFiles/scan_eml.dir/src/searchFile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/scan_eml.dir/src/searchFile.c.s"
	"D:\Program files\JetBrains\CLion 2023.3.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\piotr\CLionProjects\scan_eml\src\searchFile.c -o CMakeFiles\scan_eml.dir\src\searchFile.c.s

# Object files for target scan_eml
scan_eml_OBJECTS = \
"CMakeFiles/scan_eml.dir/src/main.c.obj" \
"CMakeFiles/scan_eml.dir/src/utils/validateFile.c.obj" \
"CMakeFiles/scan_eml.dir/src/utils/validatePesel.c.obj" \
"CMakeFiles/scan_eml.dir/src/searchFile.c.obj"

# External object files for target scan_eml
scan_eml_EXTERNAL_OBJECTS =

scan_eml.exe: CMakeFiles/scan_eml.dir/src/main.c.obj
scan_eml.exe: CMakeFiles/scan_eml.dir/src/utils/validateFile.c.obj
scan_eml.exe: CMakeFiles/scan_eml.dir/src/utils/validatePesel.c.obj
scan_eml.exe: CMakeFiles/scan_eml.dir/src/searchFile.c.obj
scan_eml.exe: CMakeFiles/scan_eml.dir/build.make
scan_eml.exe: CMakeFiles/scan_eml.dir/linkLibs.rsp
scan_eml.exe: CMakeFiles/scan_eml.dir/objects1.rsp
scan_eml.exe: CMakeFiles/scan_eml.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\piotr\CLionProjects\scan_eml\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable scan_eml.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\scan_eml.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/scan_eml.dir/build: scan_eml.exe
.PHONY : CMakeFiles/scan_eml.dir/build

CMakeFiles/scan_eml.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\scan_eml.dir\cmake_clean.cmake
.PHONY : CMakeFiles/scan_eml.dir/clean

CMakeFiles/scan_eml.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\piotr\CLionProjects\scan_eml C:\Users\piotr\CLionProjects\scan_eml C:\Users\piotr\CLionProjects\scan_eml\cmake-build-debug C:\Users\piotr\CLionProjects\scan_eml\cmake-build-debug C:\Users\piotr\CLionProjects\scan_eml\cmake-build-debug\CMakeFiles\scan_eml.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/scan_eml.dir/depend

