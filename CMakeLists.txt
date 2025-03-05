cmake_minimum_required(VERSION 3.28)

project(keyboard_overlay LANGUAGES CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
set(SFML_BUILD_AUDIO OFF)
FetchContent_Declare(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 3.0.0 GIT_SHALLOW ON EXCLUDE_FROM_ALL SYSTEM)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(libuiohook GIT_REPOSITORY https://github.com/kwhat/libuiohook.git GIT_TAG 1.2 GIT_SHALLOW ON EXCLUDE_FROM_ALL SYSTEM)
FetchContent_MakeAvailable(libuiohook)

add_executable(keyboard_overlay main.cpp DisplayKey.cpp)
target_link_libraries(keyboard_overlay PRIVATE SFML::Graphics uiohook)
