cmake_minimum_required (VERSION 3.0)
project (PSOP-Debugger)

add_compile_options(-std=c++17)

include_directories(ext/libelfin ext/linenoise include)
add_executable(main main.cpp ext/linenoise/linenoise.c breakpoint.cpp debugger.cpp)



add_executable(test test.cpp)
set_target_properties(test
                      PROPERTIES COMPILE_FLAGS "-gdwarf-2 -O0")

add_custom_target(
   libelfin
   COMMAND make
   WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/ext/libelfin
)
target_link_libraries(main
                      ${PROJECT_SOURCE_DIR}/ext/libelfin/dwarf/libdwarf++.so
                      ${PROJECT_SOURCE_DIR}/ext/libelfin/elf/libelf++.so)
add_dependencies(main libelfin)
