cmake_minimum_required(VERSION 3.1.3)
project(protobuf)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fpermissive -fvisibility=hidden -Wall -std=c++14" )

set(CMAKE_CXX_STANDARD 14)

#Debug Release RelWithDebInfo >和 MinSizeRel。
#set(CMAKE_BUILD_TYPE "Release")

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

#add_definitions(-DNDEBUG)

add_subdirectory(cmake)
#add_subdirectory(examples)
add_subdirectory(mytest)


#./protoc36 -I=src/ --cpp_out=examples/ --proto_path=examples addressbook.proto


