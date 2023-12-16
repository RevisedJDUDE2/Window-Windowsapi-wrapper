cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Autoclick)

add_executable(Autoclick src/main.cpp)
target_include_directories(Autoclick PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(Autoclick PUBLIC Windowlib)

add_library(Windowlib SHARED src/lib/Window.cpp)
target_include_directories(Windowlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
