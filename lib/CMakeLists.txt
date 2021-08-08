# https://stackoverflow.com/questions/50600708/combining-cmake-object-libraries-with-shared-libraries
function(add_literal_module target_name)
    add_library(${target_name} OBJECT ${ARGN})
    set_property(TARGET ${target_name} PROPERTY POSITION_INDEPENDENT_CODE ON)
endfunction()

add_subdirectory(debug)

add_library(literal SHARED
$<TARGET_OBJECTS:literal_debug>
)

set_property(TARGET literal PROPERTY POSITION_INDEPENDENT_CODE ON)
