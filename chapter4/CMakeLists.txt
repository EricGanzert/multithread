add_executable(scheduler_example 
    abstract_request.h
    dispatcher.h
    dispatcher.cpp
    main.cpp
    request.h
    request.cpp
    worker.h
    worker.cpp
)

target_link_libraries(scheduler_example PRIVATE pthread)