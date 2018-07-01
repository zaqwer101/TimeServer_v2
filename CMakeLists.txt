cmake_minimum_required(VERSION 3.10)
project(sandbox)

set(CMAKE_CXX_STANDARD 11)
find_library(PTHREAD_LIBRARY pthread)
find_library(LIBCURL_LIBRARY lcurl)
add_executable(sandbox main.cpp Server.cpp Server.h Connection.cpp Connection.h)
target_link_libraries(sandbox ${PTHREAD_LIBRARY} -lcurl)