cmake_minimum_required(VERSION 3.5)
project(Projects2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
#set(CMAKE_CXX_FLAGS “${CMAKE_CXX_FLAGS} -stdlib=libc++6”)

set(SOURCE_FILES main.cpp CEdge.cpp CEdge.h CGraph.cpp CGraph.h CVertex.cpp CVertex.h CPath.cpp CPath.h)
add_executable(Projects2 ${SOURCE_FILES})