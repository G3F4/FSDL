cmake_minimum_required(VERSION 2.8.4)
project(FSDL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/singeltons/Application.cpp
    src/singeltons/Application.hpp
    src/singeltons/TextureStash.cpp
    src/singeltons/TextureStash.hpp
    src/singeltons/Events.cpp
    src/singeltons/Events.hpp
    src/singeltons/TextStash.cpp
    src/singeltons/TextStash.hpp
    src/FSDL.hpp
    src/main.cpp
    src/MyApp.cpp
    src/MyApp.hpp
    src/singeltons/Events.cpp
    src/singeltons/Events.hpp
    src/entities/Texture.cpp
    src/entities/Texture.hpp
    src/entities/TextObject.cpp
    src/entities/TextObject.hpp

    Makefile
    README.md)

add_executable(FSDL ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS} ${SDL2MIXER_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES} ${SDL2MIXER_LIBRARIES})
