add_executable(fetch_add
fetch_add.cpp
)

target_link_libraries(fetch_add PRIVATE pthread)