add_executable(fetch_add
fetch_add.cpp
)
target_link_libraries(fetch_add PRIVATE pthread)

add_executable(fetch_sub
fetch_sub.cpp
)
target_link_libraries(fetch_sub PRIVATE pthread)