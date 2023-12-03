cmake_minimum_required(VERSION 3.27.7)
project(flappybird VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
include(FetchContent)
enable_testing()

#libraries
set(RAYLIB_VERSION 4.5.0)
FetchContent_Declare(
    raylib
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

add_executable(flappybird main.cpp)
target_link_libraries(${PROJECT_NAME} raylib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
