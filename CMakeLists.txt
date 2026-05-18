cmake_minimum_required(VERSION 3.10)

set(APP_NAME cocos-demo-game)
project(${APP_NAME})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT DEFINED COCOS2DX_ROOT_PATH)
    if(DEFINED ENV{COCOS2DX_ROOT_PATH})
        set(COCOS2DX_ROOT_PATH $ENV{COCOS2DX_ROOT_PATH})
    else()
        set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cocos2d)
    endif()
endif()

set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

include(CocosBuildSet)
add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)

set(GAME_HEADER
    Classes/AppDelegate.h
    Classes/DemoBase.h
    Classes/MenuScene.h
    Classes/SpriteDemo.h
    Classes/ActionDemo.h
    Classes/LabelDemo.h
    Classes/InputDemo.h
    Classes/SceneDemo.h
    Classes/EventDemo.h
    Classes/NodeDemo.h
    Classes/AnimationDemo.h
)

set(GAME_SOURCE
    Classes/AppDelegate.cpp
    Classes/DemoBase.cpp
    Classes/MenuScene.cpp
    Classes/SpriteDemo.cpp
    Classes/ActionDemo.cpp
    Classes/LabelDemo.cpp
    Classes/InputDemo.cpp
    Classes/SceneDemo.cpp
    Classes/EventDemo.cpp
    Classes/NodeDemo.cpp
    Classes/AnimationDemo.cpp
)

if(LINUX)
    list(APPEND GAME_SOURCE proj.linux/main.cpp compat/glibc_compat.c)
elseif(WINDOWS)
    list(APPEND GAME_SOURCE proj.win32/main.cpp)
elseif(APPLE)
    list(APPEND GAME_SOURCE proj.mac/main.cpp)
endif()

set(all_code_files ${GAME_HEADER} ${GAME_SOURCE})

if(ANDROID)
    add_library(${APP_NAME} SHARED ${all_code_files})
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos/platform/android ${ENGINE_BINARY_PATH}/cocos/platform)
    target_link_libraries(${APP_NAME} -Wl,--whole-archive cpp_android_spec -Wl,--no-whole-archive)
else()
    add_executable(${APP_NAME} ${all_code_files})
endif()

target_link_libraries(${APP_NAME} cocos2d)
target_include_directories(${APP_NAME} PRIVATE Classes)

set(GAME_RES_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/Resources")
if(LINUX OR WINDOWS)
    set(APP_RES_DIR "$<TARGET_FILE_DIR:${APP_NAME}>/Resources")
    add_custom_command(TARGET ${APP_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${GAME_RES_FOLDER} ${APP_RES_DIR}
    )
endif()
