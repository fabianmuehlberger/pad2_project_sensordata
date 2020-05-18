# creates library from source file
add_library(list SHARED list.c)

# link library to the project
target_link_libraries (list person)
