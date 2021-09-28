add_executable(basic_use
    basic_use.cpp
)
target_link_libraries(basic_use PRIVATE pthread)

add_executable(thread_id
    thread_id.cpp
)
target_link_libraries(thread_id PRIVATE pthread)

add_executable(sleeping
    sleeping.cpp
)
target_link_libraries(sleeping PRIVATE pthread)