cmake_minimum_required(VERSION 3.16)

project(OpenIndyMath LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Armadillo REQUIRED)

set(HEADERS
    include/global.h
    include/chooselalib.h
    include/linearalgebra.h
    include/oivec.h
    include/oimat.h
)

set(SOURCES
    src/oivec.cpp
    src/oimat.cpp
    src/laarmadillo.cpp
    src/chooselalib.cpp
)

add_library(OpenIndyMath SHARED ${SOURCES} ${HEADERS})

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(OpenIndyMath PRIVATE -Wall -Wextra -Wpedantic)
endif()
# Source files and string literals are UTF-8; MSVC needs to be told.
target_compile_options(OpenIndyMath PUBLIC $<$<CXX_COMPILER_ID:MSVC>:/utf-8>)

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
    PRIVATE
        ${ARMADILLO_LIBRARIES}
)
