# ----- 1. Runtime environment
cmake_minimum_required(VERSION 3.22)
project(Competitve-programming)

# ----- 2. Debugging
# for debugging with gdb in Terminal
# set(CMAKE_BUILD_TYPE DEBUG)
# set(CMAKE_C_FLAGS "-O0 -ggdb")
# set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb")
# set(CMAKE_C_FLAGS_RELEASE "-O0 -ggdb")

# ----- 3. Global variable

# ----- 4. Software library
# set(includes /usr/local/include/libxml2)
# include_directories(${includes})

# ----- 3. Static and shared library
# Static (A file)
# set(libs_static libxml2.a)
# link_directories(/usr/local/lib)

# Shared (SO file)
# set(libs_shared libxml2.so)
# link_directories(/usr/local/lib)

# ----- 4. File to compile
set(sources exercism/armstrong-numbers.c)
add_executable(main ${sources})

# This is for math.h tool: "-l m" which calling "libm.so"
target_link_libraries(main ${libs_static} ${libs_shared} m)

# Look in /lib or /usr/lib. The libraries are all named lib<name>.a or lib<name>.so - it's the "<name>" you put after the -l. In this case, the math library is named libm.so, so we call it -lm. - https://stackoverflow.com/questions/8671366/undefined-reference-to-pow-and-floor