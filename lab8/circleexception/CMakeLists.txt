
project(circleexception)

set(HEDEAR_FILES CircleException.h)
set(SOURCE_FILES CircleException.cpp)

add_library(libcircleexception STATIC ${SOURCE_FILES})
target_include_directories(libcircleexception PUBLIC .)

add_executable(circleexception ${SOURCE_FILES} main.cpp)

target_link_libraries(circleexception libcircleexception)
