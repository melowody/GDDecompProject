cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(REGD VERSION 1.0.0)

find_file(WINDOWS_HEADER windows.h)
if(NOT WINDOWS_HEADER)
  message(FATAL_ERROR "Can't find windows.h!")
endif()

file(
  GLOB_RECURSE SOURCE_FILES
  src/Headers/GD/Misc/GameSoundManager.cpp
  src/Headers/GD/Misc/FMODAudioEngine.cpp
  src/*.cpp
  src/*.h
  src/*.hpp
  # nice
  libraries/cappuccino-sdk/template/default-cpp/cappuccino-sdk/incl/cocos2dx/custom/Sprites/CCMenuItemSpriteExtra/CCMenuItemSpriteExtra.cpp
)
add_library(REGD SHARED ${SOURCE_FILES})

target_include_directories(REGD PRIVATE
  libraries/minhook/include
  libraries/fmod
  libraries/cappuccino-sdk/template/default-cpp/cappuccino-sdk/incl/cocos2dx/
  libraries/cappuccino-sdk/template/default-cpp/cappuccino-sdk/incl/cocos2dx/include
  libraries/cappuccino-sdk/template/default-cpp/cappuccino-sdk/incl/cocos2dx/kazmath/include
  libraries/cappuccino-sdk/template/default-cpp/cappuccino-sdk/incl/cocos2dx/platform/win32
  libraries/cappuccino-sdk/template/default-cpp/cappuccino-sdk/incl/cocos2dx/platform/third_party/win32
  libraries/cappuccino-sdk/template/default-cpp/cappuccino-sdk/incl/cocos2dx/platform/third_party/win32/OGLES
  libraries/cappuccino-sdk/template/default-cpp/cappuccino-sdk/incl/extensions
)

add_subdirectory(libraries/minhook)
target_link_libraries(REGD minhook)

target_link_libraries(REGD ${CMAKE_SOURCE_DIR}/libraries/cappuccino-sdk/template/default-cpp/cappuccino-sdk/lib/cappuccino.lib)
# most of the time you dont need this
target_link_libraries(REGD ${CMAKE_SOURCE_DIR}/libraries/cappuccino-sdk/template/default-cpp/cappuccino-sdk/lib/libExtensions.lib)

target_link_libraries(REGD ${CMAKE_SOURCE_DIR}/libraries/fmod/fmod_vc.lib)

set_target_properties(REGD PROPERTIES PREFIX "")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})