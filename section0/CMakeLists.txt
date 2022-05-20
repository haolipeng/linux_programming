add_executable(thread main.c)
add_executable(unixServer unixServer.cpp)
add_executable(unixClient unixClient.cpp)

target_link_libraries(thread pthread)