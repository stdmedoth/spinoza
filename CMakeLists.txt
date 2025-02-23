# Set minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(spinoza)

# Define the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Search for all .cpp files in the src directory
file(GLOB SOURCES "src/*.cpp")

# Fetch all header files (.h and .hpp)
file(GLOB HEADERS "include/*.h" "include/*.hpp")

# Add executable for the main project
add_executable(${PROJECT_NAME} ${SOURCES})

# If necessary, link additional libraries here
# target_link_libraries(${PROJECT_NAME} nome_da_biblioteca)

# Find all example files in the examples directory
file(GLOB EXAMPLES "examples/*.cpp")

# Add an executable for each example file
foreach(EXAMPLE_FILE ${EXAMPLES})
    # Get the filename without extension
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_FILE} NAME_WE)
    
    # Create an executable for each example
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_FILE} ${SOURCES})

    # If necessary, link additional libraries
    # target_link_libraries(${EXAMPLE_NAME} nome_da_biblioteca)
endforeach()
