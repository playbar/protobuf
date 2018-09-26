# Minimum CMake required
cmake_minimum_required(VERSION 3.8)

# Project
project(protobuf-examples)

# Find required protobuf package
#find_package(protobuf CONFIG REQUIRED)

if(protobuf_VERBOSE)
  message(STATUS "Using Protocol Buffers ${Protobuf_VERSION}")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

# http://www.cmake.org/Wiki/CMake_FAQ#How_can_I_build_my_MSVC_application_with_a_static_runtime.3F
if(MSVC AND protobuf_MSVC_STATIC_RUNTIME)
  foreach(flag_var
      CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
      CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
    if(${flag_var} MATCHES "/MD")
      string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
    endif(${flag_var} MATCHES "/MD")
  endforeach()
endif()

set(data_write_SRCS data_write.cc data.pb.cc)
add_executable(data_write ${data_write_SRCS})
target_include_directories(data_write   PUBLIC ${PROTOBUF_INCLUDE_DIRS})
target_link_libraries(data_write protobuf::libprotobuf)


set(data_read_SRCS data_read.cc data.pb.cc)
add_executable(data_read ${data_read_SRCS})
target_include_directories(data_read   PUBLIC ${PROTOBUF_INCLUDE_DIRS})
target_link_libraries(data_read protobuf::libprotobuf)


set(reader_SRCS reader.cpp helloworld.pb.cc)
add_executable(reader ${reader_SRCS})
target_include_directories(reader   PUBLIC ${PROTOBUF_INCLUDE_DIRS})
target_link_libraries(reader protobuf::libprotobuf)

set(writer_SRCS writer.cpp helloworld.pb.cc)
add_executable(writer ${writer_SRCS})
target_include_directories(writer   PUBLIC ${PROTOBUF_INCLUDE_DIRS})
target_link_libraries(writer protobuf::libprotobuf)


set(msg_SRCS msg.cpp msg.pb.cc)
add_executable(msg ${msg_SRCS})
target_include_directories(msg   PUBLIC ${PROTOBUF_INCLUDE_DIRS})
target_link_libraries(msg protobuf::libprotobuf)

#foreach(example add_data list_data)
#  set(${example}_SRCS ${example}.cc data.pb.cc)
#  set(${example}_PROTOS data.proto)
#
#  #Code Generation
#  if(protobuf_MODULE_COMPATIBLE) #Legacy Support
#    protobuf_generate_cpp(${example}_PROTO_SRCS ${example}_PROTO_HDRS ${${example}_PROTOS})
#    list(APPEND ${example}_SRCS ${${example}_PROTO_SRCS} ${${example}_PROTO_HDRS})
#  endif()
#
#  #Executable setup
#  set(executable_name ${example}_cpp)
#  add_executable(${executable_name} ${${example}_SRCS} ${${example}_PROTOS})
#  if(protobuf_MODULE_COMPATIBLE) #Legacy mode
#    target_include_directories(${executable_name} PUBLIC ${PROTOBUF_INCLUDE_DIRS})
#    target_link_libraries(${executable_name} ${PROTOBUF_LIBRARIES})
#  else()
#    target_link_libraries(${executable_name} protobuf::libprotobuf)
##    protobuf_generate(TARGET ${executable_name})
#  endif()
#
#endforeach()
