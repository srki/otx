cmake_minimum_required(VERSION 3.09)

project(otx
        VERSION 0.1
        DESCRIPTION "A Simple Header Library for Parsing Program Options."
        LANGUAGES C CXX)

add_library(otx-c INTERFACE)
target_include_directories(otx-c INTERFACE include/c)

add_library(otx-cpp INTERFACE)
target_include_directories(otx-cpp INTERFACE include/cpp)

add_subdirectory(tests)