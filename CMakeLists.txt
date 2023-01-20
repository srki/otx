cmake_minimum_required(VERSION 3.09)

project(otx
        VERSION 0.1
        DESCRIPTION "A Simple Header Library for Parsing Program Options."
        LANGUAGES CXX)

add_library(otx SHARED src/otx.cpp)
target_include_directories(otx PUBLIC include)
target_compile_features(otx PUBLIC cxx_std_17)

add_subdirectory(tests)