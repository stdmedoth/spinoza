# Set minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(spinoza)

# Define the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the C++ standard to use
include_directories(include)

# Search for all .cpp files in the src directory
file(GLOB SOURCES "src/*.cpp")

# Fetch all header files (.h and .hpp)
file(GLOB HEADERS "include/*.h" "include/*.hpp")

# Add executable from found source code files
add_executable(${PROJECT_NAME} ${SOURCES})

# If necessary, link additional libraries here
# target_link_libraries(${PROJECT_NAME} nome_da_biblioteca)
