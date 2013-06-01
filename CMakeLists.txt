project(ftc_tp2)
cmake_minimum_required(VERSION 2.8)

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_EXE_LINKER_FLAGS
"${CMAKE_EXE_LINKER_FLAGS} -Wl,-enable-auto-import"
)

set(
CMAKE_SHARED_LIBRARY_CXX_FLAGS
"${CMAKE_SHARED_LIBRARY_CXX_FLAGS} -Wl,--enable-auto-import "
)
