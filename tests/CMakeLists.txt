add_executable(main-c main.c)
target_link_libraries(main-c PRIVATE otx-c)

add_executable(main-cpp main.cpp)
target_link_libraries(main-cpp PRIVATE otx-cpp)
target_compile_features(main-cpp PUBLIC cxx_std_11)
