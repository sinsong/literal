include(GoogleTest)

function(add_literal_unittest test_name)
    add_executable(${test_name} ${ARGN})
    target_link_libraries(${test_name} literal gtest_main)
    add_custom_command(
        TARGET ${test_name} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:literal> $<TARGET_FILE_DIR:${test_name}>
    )
    gtest_discover_tests(${test_name})
endfunction()

add_subdirectory(debug)
add_subdirectory(list)