# Set the minimum required version of CMake. 3.10 is a good modern baseline.
cmake_minimum_required(VERSION 3.10)

# Define the project name and specify that the language is C.
project(DataStructuresProject C)

# Set the C standard to C11. You can also use C99 or C17 if you prefer.
# This ensures your code is compiled with a consistent language version.
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Create an executable target.
# This command tells CMake to create a program named "my_app"
# from the source file "main.c".
# If you have more source files, just add them to the list,
# e.g., add_executable(my_app main.c linked_list.c)
add_executable(main divide-conquer.c)

# Add compiler flags for better code quality and debugging.
# These flags are highly recommended for development.
target_compile_options(main PRIVATE
    -g          # Include debugging information in the executable
    -Wall       # Enable all standard warnings (highly recommended)
    -Wextra     # Enable extra warnings
    -Wpedantic  # Warn on non-standard language extensions
)

# Optional: Print a message after CMake has finished configuring.
message(STATUS "CMake configuration complete. Run 'make' to build.")

