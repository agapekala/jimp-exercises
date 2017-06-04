
project(add)

set(HEDEAR_FILES Add.h)
set(SOURCE_FILES Add.cpp)

add_library(libadd STATIC ${SOURCE_FILES})
target_include_directories(libadd PUBLIC .)

add_executable(add ${SOURCE_FILES} main.cpp)

target_link_libraries(add libadd)
