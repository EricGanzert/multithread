add_executable(chapter1 ch01_mt_example.cpp)

target_link_libraries(chapter1 PRIVATE pthread)