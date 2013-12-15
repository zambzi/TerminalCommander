cmake_minimum_required (VERSION 2.6)
project (TerminalCommander)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/coding/*)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/gui/*)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main/*)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ship/*)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/*)

file(GLOB_RECURSE TARGET_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/coding/*.h)
file(GLOB_RECURSE TARGET_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/gui/*.h)
file(GLOB_RECURSE TARGET_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/main/*.h)
file(GLOB_RECURSE TARGET_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/ship/*.h)
file(GLOB_RECURSE TARGET_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/*.h)

find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)
find_package(SDL REQUIRED)
find_package(CEGUI REQUIRED)


if(NOT SDL_FOUND)
	message( FATAL_ERROR "SDL not found!")
endif (NOT SDL_FOUND)

if(NOT CEGUI_FOUND)
	message( FATAL_ERROR "CEGUI not found!")
endif (NOT CEGUI_FOUND)

link_libraries(
	${SDL_LIBRARY}
	SDLmain
	${CEGUI_LIBRARY}
)

include_directories(
	${CEGUI_INCLUDE_DIRS}
)

add_executable(TerminalCommander WIN32 ${SOURCES})