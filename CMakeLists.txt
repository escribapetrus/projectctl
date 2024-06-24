cmake_minimum_required(VERSION 3.10)
project(ProjectCTL VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

file(GLOB SOURCES "src/*.cpp")

# Add the main executable
add_executable(ProjectCTL main.cpp ${SOURCES})

find_package(SQLite3 REQUIRED)
target_link_libraries(ProjectCTL SQLite::SQLite3)

file(GLOB TEST_SOURCES "tests/test_*.cpp")

foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE} ${SOURCES})
    target_link_libraries(${TEST_NAME} SQLite::SQLite3)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

enable_testing()

