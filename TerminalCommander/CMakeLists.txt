cmake_minimum_required (VERSION 2.6)
project (TerminalCommander)

set(execDirectory TerminalCommander)

#create executable directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/${execDirectory})

#copy assets to executable directory
file(	COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets
	DESTINATION ${CMAKE_BINARY_DIR}/${execDirectory} )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${execDirectory}/)

#find all source and header files
file(GLOB_RECURSE srcCoding ${CMAKE_CURRENT_SOURCE_DIR}/src/coding/*.cpp)
file(GLOB_RECURSE srcGui ${CMAKE_CURRENT_SOURCE_DIR}/src/gui/*.cpp)
file(GLOB_RECURSE srcMain ${CMAKE_CURRENT_SOURCE_DIR}/src/main/*.cpp)
file(GLOB_RECURSE srcShip ${CMAKE_CURRENT_SOURCE_DIR}/src/ship/*.cpp)
file(GLOB_RECURSE srcUtils ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/*.cpp)

#set cmake_modules directory as path to look for modules
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(SDL REQUIRED)
find_package(CEGUI REQUIRED COMPONENTS OpenGL)
find_package(GLM REQUIRED)

link_libraries(
	${SDL_LIBRARY}
	SDLmain
	${OPENGL_LIBRARIES}
	${GLUT_LIBRARY}
	${CEGUI_LIBRARY}
)

include_directories(
	${CEGUI_INCLUDE_DIRS}
	${OPENGL_INCLUDE_DIRS}
	${GLUT_INCLUDE_DIRS}
	${GLM_INCLUDE_DIRS}	
)

add_executable(	
	TerminalCommander 
	WIN32 
	${srcCoding} 
	${srcGui} 
	${srcMain} 
	${srcShip} 
	${srcUtils}	
)
