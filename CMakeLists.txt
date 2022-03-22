cmake_minimum_required(VERSION 3.22.2)

project(Suduko)

add_executable(${PROJECT_NAME} ./src/main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static") #T1
# set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CSS_STANDARD_LIBRARIES}") #T2
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive") #T3

# set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")