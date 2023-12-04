cmake_minimum_required(VERSION 3.26)
project(spcreator)

set(CMAKE_CXX_STANDARD 23)

add_executable(spcreator main.cpp)

target_include_directories(spcreator PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>)

file (GLOB files *.cpp)
foreach (file ${files})
    target_sources(spcreator PRIVATE ${file})
#    target_sources(SPCreator PRIVATE exec_command.cpp options_parse.cpp)
endforeach ()

# boost
find_package(Boost COMPONENTS program_options thread REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()
target_link_libraries(${CMAKE_PROJECT_NAME} ${Boost_LIBRARIES})

# 宏
if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG)
endif()