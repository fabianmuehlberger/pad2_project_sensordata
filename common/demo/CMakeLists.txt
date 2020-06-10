add_executable(test_main test_main.c)
target_link_libraries(test_main my_graphics my_file_io my_validation)

add_executable(hello_world hello_world.c)
target_link_libraries(hello_world)

add_executable(main main.c)
target_link_libraries(main my_helpers my_graphics)

add_executable(test_readFile test_readFile.c)
target_link_libraries(test_readFile my_validation my_file_io my_helpers my_structure)

add_executable(test_structure test_structure.c)
target_link_libraries(test_structure my_structure)

add_executable(test_data_conversion test_data_conversion.c)
target_link_libraries(test_data_conversion)