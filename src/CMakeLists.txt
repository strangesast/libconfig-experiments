add_executable(demo main.c)

find_library(LIBCONFIG config REQUIRED)
target_link_libraries(demo config)

set_target_properties(demo
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
