add_executable(thread main.c)
add_executable(unixServer unixServer.cpp)
add_executable(unixClient unixClient.cpp)
add_executable(dup_example dup-dup2-example.cpp)

target_link_libraries(thread pthread)