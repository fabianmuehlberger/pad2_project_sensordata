# dont worry, you need this
cmake_minimum_required(VERSION 2.6)

#set´s the project name
project(generic_list)

# setup 
set(CMAKE_C_FLAGS "-std=c99 -Werror")
set(CMAKE_BUILD_TYPE "Debug")

# set the directory for the executes
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/exec)

# add 
add_subdirectory(common)

