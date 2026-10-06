add_executable(simulate main.cpp)
target_link_libraries(simulate PRIVATE motion::core)
motion_set_warnings(simulate)
