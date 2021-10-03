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

add_executable(swap
    swap.cpp
)
target_link_libraries(swap PRIVATE pthread)

add_executable(simple_mutex
    simple_mutex.cpp
)
target_link_libraries(simple_mutex PRIVATE pthread)

add_executable(non_blocking_locking
    non_blocking_locking.cpp
)
target_link_libraries(non_blocking_locking PRIVATE pthread)

add_executable(lock_guard
    lock_guard.cpp
)
target_link_libraries(lock_guard PRIVATE pthread)