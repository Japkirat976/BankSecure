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
CMAKE_SOURCE_DIR = /home/japkirat/BankSecure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/japkirat/BankSecure/build

# Include any dependencies generated for this target.
include src/CMakeFiles/bank_secure.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/bank_secure.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/bank_secure.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/bank_secure.dir/flags.make

src/CMakeFiles/bank_secure.dir/bank_secure.cpp.o: src/CMakeFiles/bank_secure.dir/flags.make
src/CMakeFiles/bank_secure.dir/bank_secure.cpp.o: ../src/bank_secure.cpp
src/CMakeFiles/bank_secure.dir/bank_secure.cpp.o: src/CMakeFiles/bank_secure.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/japkirat/BankSecure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/bank_secure.dir/bank_secure.cpp.o"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/bank_secure.dir/bank_secure.cpp.o -MF CMakeFiles/bank_secure.dir/bank_secure.cpp.o.d -o CMakeFiles/bank_secure.dir/bank_secure.cpp.o -c /home/japkirat/BankSecure/src/bank_secure.cpp

src/CMakeFiles/bank_secure.dir/bank_secure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_secure.dir/bank_secure.cpp.i"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/japkirat/BankSecure/src/bank_secure.cpp > CMakeFiles/bank_secure.dir/bank_secure.cpp.i

src/CMakeFiles/bank_secure.dir/bank_secure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_secure.dir/bank_secure.cpp.s"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/japkirat/BankSecure/src/bank_secure.cpp -o CMakeFiles/bank_secure.dir/bank_secure.cpp.s

src/CMakeFiles/bank_secure.dir/account.cpp.o: src/CMakeFiles/bank_secure.dir/flags.make
src/CMakeFiles/bank_secure.dir/account.cpp.o: ../src/account.cpp
src/CMakeFiles/bank_secure.dir/account.cpp.o: src/CMakeFiles/bank_secure.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/japkirat/BankSecure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/bank_secure.dir/account.cpp.o"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/bank_secure.dir/account.cpp.o -MF CMakeFiles/bank_secure.dir/account.cpp.o.d -o CMakeFiles/bank_secure.dir/account.cpp.o -c /home/japkirat/BankSecure/src/account.cpp

src/CMakeFiles/bank_secure.dir/account.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_secure.dir/account.cpp.i"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/japkirat/BankSecure/src/account.cpp > CMakeFiles/bank_secure.dir/account.cpp.i

src/CMakeFiles/bank_secure.dir/account.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_secure.dir/account.cpp.s"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/japkirat/BankSecure/src/account.cpp -o CMakeFiles/bank_secure.dir/account.cpp.s

src/CMakeFiles/bank_secure.dir/auth.cpp.o: src/CMakeFiles/bank_secure.dir/flags.make
src/CMakeFiles/bank_secure.dir/auth.cpp.o: ../src/auth.cpp
src/CMakeFiles/bank_secure.dir/auth.cpp.o: src/CMakeFiles/bank_secure.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/japkirat/BankSecure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/bank_secure.dir/auth.cpp.o"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/bank_secure.dir/auth.cpp.o -MF CMakeFiles/bank_secure.dir/auth.cpp.o.d -o CMakeFiles/bank_secure.dir/auth.cpp.o -c /home/japkirat/BankSecure/src/auth.cpp

src/CMakeFiles/bank_secure.dir/auth.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_secure.dir/auth.cpp.i"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/japkirat/BankSecure/src/auth.cpp > CMakeFiles/bank_secure.dir/auth.cpp.i

src/CMakeFiles/bank_secure.dir/auth.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_secure.dir/auth.cpp.s"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/japkirat/BankSecure/src/auth.cpp -o CMakeFiles/bank_secure.dir/auth.cpp.s

src/CMakeFiles/bank_secure.dir/customer.cpp.o: src/CMakeFiles/bank_secure.dir/flags.make
src/CMakeFiles/bank_secure.dir/customer.cpp.o: ../src/customer.cpp
src/CMakeFiles/bank_secure.dir/customer.cpp.o: src/CMakeFiles/bank_secure.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/japkirat/BankSecure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/bank_secure.dir/customer.cpp.o"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/bank_secure.dir/customer.cpp.o -MF CMakeFiles/bank_secure.dir/customer.cpp.o.d -o CMakeFiles/bank_secure.dir/customer.cpp.o -c /home/japkirat/BankSecure/src/customer.cpp

src/CMakeFiles/bank_secure.dir/customer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_secure.dir/customer.cpp.i"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/japkirat/BankSecure/src/customer.cpp > CMakeFiles/bank_secure.dir/customer.cpp.i

src/CMakeFiles/bank_secure.dir/customer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_secure.dir/customer.cpp.s"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/japkirat/BankSecure/src/customer.cpp -o CMakeFiles/bank_secure.dir/customer.cpp.s

src/CMakeFiles/bank_secure.dir/encrypt.cpp.o: src/CMakeFiles/bank_secure.dir/flags.make
src/CMakeFiles/bank_secure.dir/encrypt.cpp.o: ../src/encrypt.cpp
src/CMakeFiles/bank_secure.dir/encrypt.cpp.o: src/CMakeFiles/bank_secure.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/japkirat/BankSecure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/bank_secure.dir/encrypt.cpp.o"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/bank_secure.dir/encrypt.cpp.o -MF CMakeFiles/bank_secure.dir/encrypt.cpp.o.d -o CMakeFiles/bank_secure.dir/encrypt.cpp.o -c /home/japkirat/BankSecure/src/encrypt.cpp

src/CMakeFiles/bank_secure.dir/encrypt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_secure.dir/encrypt.cpp.i"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/japkirat/BankSecure/src/encrypt.cpp > CMakeFiles/bank_secure.dir/encrypt.cpp.i

src/CMakeFiles/bank_secure.dir/encrypt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_secure.dir/encrypt.cpp.s"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/japkirat/BankSecure/src/encrypt.cpp -o CMakeFiles/bank_secure.dir/encrypt.cpp.s

src/CMakeFiles/bank_secure.dir/kyc.cpp.o: src/CMakeFiles/bank_secure.dir/flags.make
src/CMakeFiles/bank_secure.dir/kyc.cpp.o: ../src/kyc.cpp
src/CMakeFiles/bank_secure.dir/kyc.cpp.o: src/CMakeFiles/bank_secure.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/japkirat/BankSecure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/bank_secure.dir/kyc.cpp.o"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/bank_secure.dir/kyc.cpp.o -MF CMakeFiles/bank_secure.dir/kyc.cpp.o.d -o CMakeFiles/bank_secure.dir/kyc.cpp.o -c /home/japkirat/BankSecure/src/kyc.cpp

src/CMakeFiles/bank_secure.dir/kyc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_secure.dir/kyc.cpp.i"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/japkirat/BankSecure/src/kyc.cpp > CMakeFiles/bank_secure.dir/kyc.cpp.i

src/CMakeFiles/bank_secure.dir/kyc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_secure.dir/kyc.cpp.s"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/japkirat/BankSecure/src/kyc.cpp -o CMakeFiles/bank_secure.dir/kyc.cpp.s

src/CMakeFiles/bank_secure.dir/mysql_con.cpp.o: src/CMakeFiles/bank_secure.dir/flags.make
src/CMakeFiles/bank_secure.dir/mysql_con.cpp.o: ../src/mysql_con.cpp
src/CMakeFiles/bank_secure.dir/mysql_con.cpp.o: src/CMakeFiles/bank_secure.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/japkirat/BankSecure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/bank_secure.dir/mysql_con.cpp.o"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/bank_secure.dir/mysql_con.cpp.o -MF CMakeFiles/bank_secure.dir/mysql_con.cpp.o.d -o CMakeFiles/bank_secure.dir/mysql_con.cpp.o -c /home/japkirat/BankSecure/src/mysql_con.cpp

src/CMakeFiles/bank_secure.dir/mysql_con.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_secure.dir/mysql_con.cpp.i"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/japkirat/BankSecure/src/mysql_con.cpp > CMakeFiles/bank_secure.dir/mysql_con.cpp.i

src/CMakeFiles/bank_secure.dir/mysql_con.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_secure.dir/mysql_con.cpp.s"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/japkirat/BankSecure/src/mysql_con.cpp -o CMakeFiles/bank_secure.dir/mysql_con.cpp.s

src/CMakeFiles/bank_secure.dir/screens.cpp.o: src/CMakeFiles/bank_secure.dir/flags.make
src/CMakeFiles/bank_secure.dir/screens.cpp.o: ../src/screens.cpp
src/CMakeFiles/bank_secure.dir/screens.cpp.o: src/CMakeFiles/bank_secure.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/japkirat/BankSecure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/bank_secure.dir/screens.cpp.o"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/bank_secure.dir/screens.cpp.o -MF CMakeFiles/bank_secure.dir/screens.cpp.o.d -o CMakeFiles/bank_secure.dir/screens.cpp.o -c /home/japkirat/BankSecure/src/screens.cpp

src/CMakeFiles/bank_secure.dir/screens.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_secure.dir/screens.cpp.i"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/japkirat/BankSecure/src/screens.cpp > CMakeFiles/bank_secure.dir/screens.cpp.i

src/CMakeFiles/bank_secure.dir/screens.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_secure.dir/screens.cpp.s"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/japkirat/BankSecure/src/screens.cpp -o CMakeFiles/bank_secure.dir/screens.cpp.s

src/CMakeFiles/bank_secure.dir/transactions.cpp.o: src/CMakeFiles/bank_secure.dir/flags.make
src/CMakeFiles/bank_secure.dir/transactions.cpp.o: ../src/transactions.cpp
src/CMakeFiles/bank_secure.dir/transactions.cpp.o: src/CMakeFiles/bank_secure.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/japkirat/BankSecure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/bank_secure.dir/transactions.cpp.o"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/bank_secure.dir/transactions.cpp.o -MF CMakeFiles/bank_secure.dir/transactions.cpp.o.d -o CMakeFiles/bank_secure.dir/transactions.cpp.o -c /home/japkirat/BankSecure/src/transactions.cpp

src/CMakeFiles/bank_secure.dir/transactions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_secure.dir/transactions.cpp.i"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/japkirat/BankSecure/src/transactions.cpp > CMakeFiles/bank_secure.dir/transactions.cpp.i

src/CMakeFiles/bank_secure.dir/transactions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_secure.dir/transactions.cpp.s"
	cd /home/japkirat/BankSecure/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/japkirat/BankSecure/src/transactions.cpp -o CMakeFiles/bank_secure.dir/transactions.cpp.s

# Object files for target bank_secure
bank_secure_OBJECTS = \
"CMakeFiles/bank_secure.dir/bank_secure.cpp.o" \
"CMakeFiles/bank_secure.dir/account.cpp.o" \
"CMakeFiles/bank_secure.dir/auth.cpp.o" \
"CMakeFiles/bank_secure.dir/customer.cpp.o" \
"CMakeFiles/bank_secure.dir/encrypt.cpp.o" \
"CMakeFiles/bank_secure.dir/kyc.cpp.o" \
"CMakeFiles/bank_secure.dir/mysql_con.cpp.o" \
"CMakeFiles/bank_secure.dir/screens.cpp.o" \
"CMakeFiles/bank_secure.dir/transactions.cpp.o"

# External object files for target bank_secure
bank_secure_EXTERNAL_OBJECTS =

src/bank_secure: src/CMakeFiles/bank_secure.dir/bank_secure.cpp.o
src/bank_secure: src/CMakeFiles/bank_secure.dir/account.cpp.o
src/bank_secure: src/CMakeFiles/bank_secure.dir/auth.cpp.o
src/bank_secure: src/CMakeFiles/bank_secure.dir/customer.cpp.o
src/bank_secure: src/CMakeFiles/bank_secure.dir/encrypt.cpp.o
src/bank_secure: src/CMakeFiles/bank_secure.dir/kyc.cpp.o
src/bank_secure: src/CMakeFiles/bank_secure.dir/mysql_con.cpp.o
src/bank_secure: src/CMakeFiles/bank_secure.dir/screens.cpp.o
src/bank_secure: src/CMakeFiles/bank_secure.dir/transactions.cpp.o
src/bank_secure: src/CMakeFiles/bank_secure.dir/build.make
src/bank_secure: src/CMakeFiles/bank_secure.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/japkirat/BankSecure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable bank_secure"
	cd /home/japkirat/BankSecure/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bank_secure.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/bank_secure.dir/build: src/bank_secure
.PHONY : src/CMakeFiles/bank_secure.dir/build

src/CMakeFiles/bank_secure.dir/clean:
	cd /home/japkirat/BankSecure/build/src && $(CMAKE_COMMAND) -P CMakeFiles/bank_secure.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/bank_secure.dir/clean

src/CMakeFiles/bank_secure.dir/depend:
	cd /home/japkirat/BankSecure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/japkirat/BankSecure /home/japkirat/BankSecure/src /home/japkirat/BankSecure/build /home/japkirat/BankSecure/build/src /home/japkirat/BankSecure/build/src/CMakeFiles/bank_secure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/bank_secure.dir/depend

