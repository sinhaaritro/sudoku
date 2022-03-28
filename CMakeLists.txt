cmake_minimum_required(VERSION 3.22.2)

# set the project name and version
project(Suduko VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(./src) #For Headers

file(GLOB SOURCES "src/*.cpp") #For CPP

add_executable(${PROJECT_NAME} ${SOURCES})

# add_library(point src/Point2D.h src/Point2D.cpp)
# add_library(boardposition src/BoardPosition.h src/BoardPosition.cpp)
# add_library(player src/Player.h src/Player.cpp)
# add_library(suduko src/Suduko.h src/Suduko.cpp)
# add_executable(${PROJECT_NAME} src/main.cpp)
# target_link_libraries(${PROJECT_NAME} PUBLIC point boardposition player suduko)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static") #T1
# set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CSS_STANDARD_LIBRARIES}") #T2
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive") #T3

# set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")