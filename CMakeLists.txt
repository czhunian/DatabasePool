cmake_minimum_required(VERSION 3.0)
project(testmysql)

aux_source_directory(. SRC_LIST)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(/usr/include/mysql)
link_directories((/usr/lib/mysql))
add_executable(main ${SRC_LIST})

target_link_libraries(main mysqlclient pthread)
