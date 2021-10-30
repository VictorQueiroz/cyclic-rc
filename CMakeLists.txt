cmake_minimum_required(VERSION 3.13)
project(cyclic_rc)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(deps/libcrc)

set(NODE_SOURCE_FILES src/node_crc.cc)

if(CMAKE_JS_VERSION)
    include_directories(${CMAKE_JS_INC})
    set(NODE_SOURCE_FILES ${NODE_SOURCE_FILES} ${CMAKE_JS_SRC})
endif()

add_library(cyclic_rc SHARED ${NODE_SOURCE_FILES})
target_link_libraries(cyclic_rc PRIVATE ${CMAKE_JS_LIB} crc)
target_include_directories(cyclic_rc PRIVATE node_modules/nan $ENV{NODE_INSTALL_DIR}/include/node)

if(CMAKE_JS_VERSION)
    set_target_properties(cyclic_rc PROPERTIES PREFIX "" SUFFIX ".node")
endif()