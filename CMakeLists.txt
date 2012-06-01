project(acacia)
enable_testing()
cmake_minimum_required(VERSION 2.8)

find_package(Threads)

find_package(${CMAKE_CURRENT_LIST_DIR}/cmake/ZEROMQ REQUIRED CONFIG)
find_package(${CMAKE_CURRENT_LIST_DIR}/cmake/MSGPACK REQUIRED CONFIG)
find_package(${CMAKE_CURRENT_LIST_DIR}/cmake/LIBEV REQUIRED CONFIG)
find_package(${CMAKE_CURRENT_LIST_DIR}/cmake/FUSE REQUIRED CONFIG)

set(ACACIA_INTERFACE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CTEST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern/ctest)

add_subdirectory(extern)

set(ACACIA_LINK_LIBS
      ${CMAKE_THREAD_LIBS_INIT}
      ${LIBEV_LIBRARY}
)

function(acacia_test NAME LINKLIBS)
	include_directories(${CTEST_INCLUDE_DIR})
	add_executable(${NAME} ${NAME}.c)
	target_link_libraries(${NAME}
                          ${ACACIA_LINK_LIBS}
                          ${LINKLIBS})
	add_test(${NAME} ${NAME})
endfunction(acacia_test)

include_directories(${ACACIA_INTERFACE_DIR})
add_subdirectory(common)
add_subdirectory(server)
add_subdirectory(client)