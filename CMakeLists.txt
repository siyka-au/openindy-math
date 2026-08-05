cmake_minimum_required(VERSION 3.16)

project(OpenIndyMath LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Armadillo REQUIRED)

add_library(OpenIndyMath SHARED
    src/oivec.cpp
    src/oimat.cpp
    src/laarmadillo.cpp
    src/chooselalib.cpp
)

target_compile_definitions(OpenIndyMath PRIVATE OI_MATH_LIB)

target_include_directories(OpenIndyMath
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        src
        ${ARMADILLO_INCLUDE_DIRS}
)

target_link_libraries(OpenIndyMath
    PUBLIC
        Qt6::Core
    PRIVATE
        ${ARMADILLO_LIBRARIES}
)
