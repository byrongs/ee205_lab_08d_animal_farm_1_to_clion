cmake_minimum_required(VERSION 3.21)
project(ee205_animal_farm
        VERSION 4.0
        DESCRIPTION "All animals are equal, but some animals are more equal than others"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(ee205_lab_08d_animal_farm_1_to_clion src/main.cpp src/addCats.cpp src/addCats.h src/config.h src/catDatabase.cpp src/catDatabase.h src/deleteCats.cpp src/deleteCats.h src/updateCats.cpp src/updateCats.h src/reportCats.cpp src/reportCats.h)

message(STATUS "CMAKE_SOURCE_DIR = [${CMAKE_SOURCE_DIR}]" )

set(CMAKE_VERBOSE_MAKEFILE off)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

set(DOC_BUILD_DIR "${PROJECT_BINARY_DIR}/generated_docs")

find_package(Doxygen
        REQUIRED dot
        OPTIONAL_COMPONENTS mscgen dia)

if (DOXYGEN_FOUND)
    message(STATUS "Generating documentation using Doxygen")
else (DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
message(STATUS "PROJECT_BINARY_DIR = [${PROJECT_BINARY_DIR}]")