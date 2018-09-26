cmake_minimum_required(VERSION 3.1.3)
project(protobuf)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fpermissive -fvisibility=hidden -Wall -std=c++14" )

set(CMAKE_CXX_STANDARD 14)

add_definitions(-DNDEBUG)

add_subdirectory(cmake)
add_subdirectory(examples)
add_subdirectory(mytest)


#./protoc36 -I=src/ --cpp_out=examples/ --proto_path=examples addressbook.proto


