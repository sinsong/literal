add_library(literal_debug OBJECT
    unreachable.cpp
)

target_link_options(literal_debug "-fPIC")