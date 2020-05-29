add_executable(test_main test_main.c)
target_link_libraries(test_main my_graphics my_file_io my_validation)

add_executable(hello_world hello_world.c)
target_link_libraries(hello_world)

add_executable(main main.c)
target_link_libraries(main my_helpers)

add_executable(test_readFile test_readFile.c)
target_link_libraries(test_readFile my_validation)

# add_executable(demo_fnc_ptr main_fnc_ptr.c)
# target_link_libraries (demo_fnc_ptr)

# add_executable(demo_person_from_file main_person_from_file.c)
# target_link_libraries (demo_person_from_file person list)

# add_executable(demo_person main_person.c)
# target_link_libraries (demo_person person list)


