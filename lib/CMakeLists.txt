include(GenerateExportHeader)

add_subdirectory(debug)

add_library(literal SHARED
$<TARGET_OBJECTS:literal_debug>
)
